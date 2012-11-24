#include<iostream>
#include<semaphore.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define SEMFILE "mymutex"

using namespace std;

int count;

int main(int argc, char*argv[]){
	count = 0;
	int nLoop = 10000000
	//open
	sem_t *mutex = sem_open( 
		SEMFILE,
		O_CREAT | O_EXCL,		
		0x600,
		1
		);
	if( errno==EACCES ){
		printf("Can't open %s, permission not enough!",SEMFILE );
		exit(errno);
	}
	
	//fork
	if( fork()==0 ){
		for( int i = 0; i<nLoop; i++  ){
			sem_wait(mutex);
			count++;
			printf("child: %d\n", count);
			sem_post(mutex);
		}
		sem_unlink(SEMFILE);
		exit(0);
	}
	
	//parent
		//unlink
	for( int i = 0; i<nLoop; i++ ){
		sem_wait( mutex );
		count++;
		printf("parent: %d", count);
		sem_post( mutex );
		sem_unlink(SEMFILE);
	}
	sem_close(mutex);//destruction semaphore

	return 0;
}
