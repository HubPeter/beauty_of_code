#include <iostream>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

using namespace std;

#define MAXLINE 5
#define OPEN_MAX 100
#define LISTENQ 20
#define SERV_PORT 5000
#define INFTIM 1000

void setnonblocking(int sock)
{
    int opts;
    opts=fcntl(sock,F_GETFL);
    if(opts<0)
    {
        perror("fcntl(sock,GETFL)");
        exit(1);
    }
    opts = opts|O_NONBLOCK;
    if(fcntl(sock,F_SETFL,opts)<0)
    {
        perror("fcntl(sock,SETFL,opts)");
        exit(1);
    }   
}

int main()
{
    int i, maxi, listenfd, connfd, sockfd,epfd,nfds;
    ssize_t n;
    char line[MAXLINE];
    socklen_t clilen;
    //声明epoll_event结构体的变量,ev用于注册事件,数组用于回传要处理的事件
    struct epoll_event ev,events[20];
    //生成用于处理accept的epoll专用的文件描述符
    epfd=epoll_create(256);
    struct sockaddr_in clientaddr;
    struct sockaddr_in serveraddr;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    //把socket设置为非阻塞方式
    setnonblocking(listenfd);
    //设置与要处理的事件相关的文件描述符
    ev.data.fd=listenfd;
    //设置要处理的事件类型
    ev.events=EPOLLIN|EPOLLET;
    //ev.events=EPOLLIN;
    //注册epoll事件
    epoll_ctl(epfd,EPOLL_CTL_ADD,listenfd,&ev);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    char *local_addr="127.0.0.1";
    inet_aton(local_addr,&(serveraddr.sin_addr));//htons(SERV_PORT);
    serveraddr.sin_port=htons(SERV_PORT);
    bind(listenfd,(sockaddr *)&serveraddr, sizeof(serveraddr));
    listen(listenfd, LISTENQ);
    maxi = 0;
    for ( ; ; ) {
        //等待epoll事件的发生n of fds ready for requested I/O
        nfds=epoll_wait(epfd,events,20,500);
        //处理所发生的所有事件, 
        for(i=0;i<nfds;++i)//处理每个fd对应的事件
        {
			//如果是服务端口的连接请求 就接受连接
            if(events[i].data.fd==listenfd)
            {
                connfd = accept(listenfd,(sockaddr *)&clientaddr, &clilen);//处理请求
				//cout<<listenfd<<":"<<connfd<<endl;
                if(connfd<0){
                    perror("connfd<0");
                    exit(1);
                }
                setnonblocking(connfd);
                char *str = inet_ntoa(clientaddr.sin_addr);
                cout << "accapt a connection from " << str << endl;
                //设置用于读操作的文件描述符
				//为新的客户注册事件
                ev.data.fd=connfd;//设置事件的fd
                //设置用于注测的读操作事件
                ev.events=EPOLLIN|EPOLLET;//设置事件类型
                //ev.events=EPOLLIN;
                //注册ev
                epoll_ctl(epfd,EPOLL_CTL_ADD,connfd,&ev);//注册事件
            }
			//不是新用户请求 并且是IN类型的事件
            else if(events[i].events&EPOLLIN)//
            {
                cout << "EPOLLIN" << endl;
                if ( (sockfd = events[i].data.fd) < 0) 
                    continue;
				//由下面的处理知，该事件是收到数据的事件
                if ( (n = read(sockfd, line, MAXLINE)) < 0) {
                    if (errno == ECONNRESET) {
                        close(sockfd);
                        events[i].data.fd = -1;
                    } else
                        std::cout<<"readline error"<<std::endl;
                } else if (n == 0) {
                    close(sockfd);
                    events[i].data.fd = -1;
                }
                line[n] = '\0';
                cout << "read " << line << endl;
                //设置用于写操作的文件描述符
                ev.data.fd=sockfd;
                //设置用于注测的写操作事件
                ev.events=EPOLLOUT|EPOLLET;
                //修改sockfd上要处理的事件为EPOLLOUT
                //epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
            }
			//不是新用户请求且不是收到数据事件
            else if(events[i].events&EPOLLOUT)//输出事件
            {   //是写数据事件
                sockfd = events[i].data.fd;//
                write(sockfd, line, n);//发送数据
                //设置用于读操作的文件描述符
                ev.data.fd=sockfd;
                //设置用于注测的读操作事件
                ev.events=EPOLLIN|EPOLLET;
                //修改sockfd上要处理的事件为EPOLIN
                epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
            }
        }
    }
    return 0;
}
