/*
生成随机数，不重复
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
#define SIZE 100000000
void swap( int *arr, int a, int b );
int main(int argc, char* argv[]){
	int *arr = (int*)malloc(sizeof(int)*SIZE);
	for( int i = 1; i<=SIZE; i++ ){
		arr[i] = i;
	}
	//set seed
	srand( (unsigned int)time(NULL) );
	int i,j;
	for( int i=0; i<SIZE; i++ ){
		i = ( rand() )%SIZE;
		j = ( rand() )%SIZE;
		swap( arr, i, j );
	}
	return 0;
}
void swap( int *arr, int a, int b ){
	if( a>=SIZE || b>=SIZE || a<0 || b<0 )
		return;
	int temp =(int) *(arr+a);
	*(arr+a) = *(arr+b);
	*(arr+b) = temp;
}
