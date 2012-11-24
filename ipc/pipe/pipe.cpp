#include<iostream>
#include<unpipc.h>
#define BUF 1024
using namespace std;
int main(void){
	//writer:parent
	//reader:child
	//pipe
	int pFds[2];
	int nPid = -1;//创建的新进程的pid
	if( pipe( pipefd )!=0 ){
		perror("pipe error!");
		exit( 1 );
	}
	char sBuffer[BUF];
	//fork
	nPid = fork();
	if( nPid<0 ){//fork error
		perror("fork error");
		exit( 1 );
	}
	else if( nPid>0 ){//parent:writer
		//close
		close( nPid[0] );
		memset( sBuffer, 0, BUF );
		//write
		write( nPid[1], sBuffer, BUF );
		//close all
		close( nPid[1] );
	}else if( nPid==0 ){//child:reader
		//close
		close( nPid[1] );
		memset( sBuffer, 0, BUF );
		//read
		read( nPid[0], sBuffer, BUF );
		cout<<"read from parent:"<<endl;
		cout<<sBUffer<<endl;
		//close all
		close( nPid[0] );
	}
	//writer
	//child
	return 0;
}
