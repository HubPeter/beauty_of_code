#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<linux/socket.h>
#define BUFSIZE 1024

int main(void){
	int pipes[2], child;
	//pipe
	if( pipe(pipes)==-1 ){
		perror("Error opening pipes pairs\n");
		exit( 10 );
	}
	if( (child=fork())==-1 ){
		perror("Error Fork\n");
		exit( 1 );
	}
	if( child ){//parent
		char buf[BUFSIZE];
		//close one socket
		close( pipes[1] );
		//read
		read( pipes[0], buf, BUFSIZE );
		printf("Child say:%s\n");
		close( pipes[0] );
	}else{//child
		char buf[BUFSIZE] = "Hello father\n";
		//close one socket
		close( pipes[0] );
		//write
		write( pipes[1], buf, strlen(buf)+1 );
		printf("I say:%s\n", buf);
		close( pipes[1] );
	}
	return 0;
}
