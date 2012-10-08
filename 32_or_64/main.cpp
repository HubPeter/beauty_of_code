#include<iostream>
#include<stdio.h>
using namespace std;
int main(void){
	int i = 0x80000000;
	int p;
	for( int j=0; j>=0;){
		p = j;
		j++;
	}
	printf("max:%d\n", p);
	if(i<0){
		printf("%d\n", i);
		printf("32\n");
	}else{
		printf("%d\n", i);
		printf("64\n");
	}
	return 0;
}
