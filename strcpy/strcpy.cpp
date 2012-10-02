#include<iostream>
#include<cassert>
using namespace std;
char * strcpy( char *strDest, const char* strSrc );
void F( const int n );
int main(void){
	char src[] = "Hello world";
	char dest[12];
	const int n = 0;
	F( n );
	//strcpy( dest, src );
	//cout<<dest<<endl;
	return 0;
}
void F( const int n ){
	n++;//copy is also const int 
	return ;
}
char * strcpy( char *strDest, const char* strSrc ){
	assert( ( strDest!=NULL )&&( strSrc!=NULL ) );
	//char * address = (char *)strSrc;
	while( (*strDest++ = *strSrc++)!=0 );
	return strDest;
}
