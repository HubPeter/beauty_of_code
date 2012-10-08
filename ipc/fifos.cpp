//fifos.cpp
//named fifos
//process to create pipe files
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
	result = mkfifo("fifo", 0777);
	if(result==-1){
		perror("Mkfifo error:");
		exit(EXIT_FAILURE);
	}
		fd = open("fifo", O_RDONLY);
		while(true){
			read(fd, buf, LEN);
			printf("read from pipe: %s\n", buf);
			if(strcmp(buf, "exit")==0){
				exit(EXIT_SUCCESS);
			}
		}
	return 0;
}
