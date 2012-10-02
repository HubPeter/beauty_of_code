#include<iostream>
#include<cassert>
using namespace std;
char * strcpy( char* dest, const char *src );
int strchr( const char* src, char c );
char * strncpy( char* dest, const char * src, int n );
int strcmp( const char* a, const char* b );
int main(void){
	char a[] = "liudepengFanYiWei";
	char b[] = "liudepenn";
	int cmp = strcmp( a, b );
	cout<<cmp<<endl;
	return 0;
}
int strcmp( const char* a, const char* b ){
	assert( a && b );
	char* sa = (char*)a;
	char* sb = (char*)b;
	while( *sa && *sb && *sa==*sb ){
		sa++;
		sb++;
	}
	int cmp = *sa - *sb;
	if( cmp ==0 )
		return 0;
	else if(cmp>0){
		return 1;
	}else
		return -1;
}
/*
Find first index of c in src
*/
int strchr( const char* src, char c ){
	assert( src && c );
	char *s = (char*)src;
	while( *s && *s!=c ){
		s++;
	}
	if( *s!=0 )
		return s-src;
	return -1;
}
char * strncpy( char* dest, const char * src, int n ){
	assert( dest && src );
	char * d = dest;
	char * s = (char *) src;
	while( n-- && (*d++=*s++)!=0 )
		;
	*d = 0;
	return dest;
}

char * strcpy( char* dest, const char *src ){
	if( dest==src ){
		return dest;
	}
	assert( dest!=NULL && src!=NULL );
	char * s = (char*) src;
	char * d = dest;
	
	while(*d++ = *s++)
		;
	return dest;
}
