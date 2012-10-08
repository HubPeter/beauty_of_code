//fifos2.cpp
//named fifos
//process to write pipe
//open second
#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<unistd.h>
#define LEN 1024
using namespace std;
int main(void){
	int result;
	pid_t pid;
	char buf[LEN];
	int fd, flag=0;
	unlink("fifo");
	//result = mkfifo("fifo", 0777);
	if(result==-1){
		perror("Mkfifo error:");
		exit(EXIT_FAILURE);
	}
		fd = open("fifo", O_WRONLY);
		while(true){
			waitpid(pid, NULL, WNOHANG);
			if(flag==1){
				exit(EXIT_SUCCESS);
				close(fd);
			}
			scanf("%s", buf);
			write(fd, buf, strlen(buf)+1);
			if(strcmp(buf, "exit")==0){
				flag = 1;
				sleep(1);
			}
		}
	return 0;
}
