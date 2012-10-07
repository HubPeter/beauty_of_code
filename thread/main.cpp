#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int g = 0;
void* thread(void * ptr){
	static int p = 10;
	for( int i = 0; i<3; i++ ){
		g++;
	}
}
int main(void){
	pthread_t id;
	static int p = 100;
	pthread_create( &id, NULL, thread, NULL );
	for( int i = 0; i<3; i++ ){
		g++;
	}
	pthread_join( id, NULL );
	return 0;
}
