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
Bitmap
*/
char First( char *str ){
	int len = strlen( str );
	bool map[26][2];
	for( int i=0; i<26; i++ ){
		map[2*i] = 0;
		map[2*i+1] = 0
	}
	for( int i=0; i<len; i++ ){
		bool bit0 = map[str[2*i]];
		bool bit1 = map[str[2*i+1]];
		if( !bit0 && !bit1 )//never
			map[str[2*i+1]] = 1;
		else if(!bit0 && bit1){//once
			map[str[2*i]] = 1;
			map[str[2*i+1]] = 0;
		}
	}
	for( int i = 0; i<26; i++ ){
		if( map[2*i]==0 && map[2*i+1]==1 )
			return 'a'+i;
	}
	return 0;
}
/*
T: n^2
find first only character from str
*/
/*
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
*/
