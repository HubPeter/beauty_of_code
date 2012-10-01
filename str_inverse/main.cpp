/*
Reverse the XY to YX
*/
#include<iostream>
#include<cstring>
using namespace std;
void LeftRotate( char * str, int k, int n );
void Reverse( char *str, int b, int e );
int main(void){
	char str[] = "hello Liudepeng, Welcome to Code";
	cout<<str<<endl;
	LeftRotate( str, 5, strlen(str) );
	cout<<str<<endl;
	return 0;
}
/*
swap str[ 0, k-1 ] and str[ n-k, n-1 ]
*/
void LeftRotate( char * str, int k, int n )
	{
	//left rotate
	Reverse( str, 0, k-1 );
	Reverse( str, k, n-1 );
	Reverse( str, 0, n-1 );
	
	/*right rotate
	Reverse( str, 0, n-k-1 );
	Reverse( str, n-k, n-1 );
	Reverse( str, 0, n );
	*/
}
/*
Reverse 1 and n not index
*/
void Reverse( char *str, int b, int e ){
	for(; b<e; b++,e--){
		char cT = str[b];
		str[b] = str[e];
		str[e] = cT;
	}
}
