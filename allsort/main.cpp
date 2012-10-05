/*
输出字符串的全排列
*/
#include<iostream>
#include<cstring>
using namespace std;
void R( char* str, int first, int num );
void swap( char* a, char* b );
int main(void){
	char * str = "abc";
	R( str, 0, strlen(str) );
	return 0;
}
void R( char* str, int first, int num ){
	if( num<=1 ){
		char * s = str;
		while( *s ){
			cout<<*s;
			++s;
		}
		cout<<endl;
	}
		return;
	for( int i = first; i<first+num; ++i ){
		swap( str+first, str+i );
		R( str, first+1, num-1 );
		swap( str+first, str+i );
	}
}
void swap( char* a, char* b ){
	char c = *a;
	*a = *b;
	*b = c;
}
