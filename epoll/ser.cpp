#include<iostream>
#include<sys/epoll.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<strings.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define PLSIZE 20
#define LISTENQ 20
#define BUFSIZE 1024
#define SERV_PORT 5000
void setnonblocking(int sock){
	int opts;
	//get
	opts = fcntl(sock, F_GETFL);
	if(opts<0){
		perror("GetFL error.");
		exit(1);
	}
	opts = opts|O_NONBLOCK;
	//set
	if(fcntl(sock, F_SETFL, opts)<0){
		perror("SetFL error.");
		exit(1);
	}
}

int main(void){
	char buffer[BUFSIZE];
	int listenfd, connfd;
	socklen_t clilen;
	//create epoll instance
	int epfd = epoll_create(PLSIZE);
	//ev events[20]
	struct epoll_event ev, events[PLSIZE];
	//create listenfd
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	setnonblocking(listenfd);
	//struct sockaddr*addr;
	struct sockaddr_in clientaddr,serveraddr;
	ev.data.fd = listenfd;
	ev.events = EPOLLIN|EPOLLET;
	//register event
	epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	char* local_addr = "127.0.0.1";
	inet_aton(local_addr, &(serveraddr.sin_addr));
	serveraddr.sin_port = htons(SERV_PORT);
	//bind listen
	bind(listenfd, (sockaddr*)&serveraddr, sizeof(serveraddr));
	if(listen(listenfd, LISTENQ)!=0){
		perror("Listen error.");
		exit(1);
	}
	while(true){
		int nfds = epoll_wait(epfd, events, PLSIZE, 500);
		for(int i=0; i<nfds; i++){
			//new user
			if(events[i].data.fd==listenfd){
				//acctpt
				connfd = accept(listenfd, (sockaddr*)&clientaddr,  &clilen);
				if(connfd<0){
					cout<<listenfd<<"<--"<<connfd<<endl;
					perror("Accept error.\n");
					exit(1);
				}
				//set event params
				ev.data.fd = clientfd;
				//register event
				epoll_ctl(epfd, EPOLL_CTL_ADD, clientfd, &ev);
			}
			//to read data from user
			else if(0){
				//read
				;
				//output
			}
			//to write data to clientfd
			else{
				//data
				//write
			}
		}
	}
	return 0;
}
