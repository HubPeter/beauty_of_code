#include<iostream>
#include<cstring>
using namespace std;
char First( char * str );
int main(void){
	char str[] = "abbascededgfghigkck";
	char c = First( str );
	cout<<c<<endl;
	return 0;
}
/*
find first only character from str
*/
char First( char * str ){
	int len = strlen( str );
	for( int i=0; i<len; i++ ){
		char c = str[i];
		for( int j=i+1; j<len; j++ ){
			if( c=='0' )
				continue;
			if( str[j]==c ){
				str[i] = '0';
				str[j] = '0';
			}
		}
	}
	for( int i=0; i<len; i++ ){
		if( str[i]!='0' ){
			return str[i];
		}
	}
	return '0';
}
