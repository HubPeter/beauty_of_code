#include<iostream>
using namespace std;
char  * LeftRotate( char * str, int k );
int main(void){
	char *str = "hello Liudepeng, Welcome to Code";
	cout<<str<<endl;
	str = LeftRotate( str, 5 );
	cout<<str<<endl;
	return 0;
}
char * LeftRotate( char * str, int k ){
	int nLen = 0;
	char * sT = str;
	cout<<nLen<<endl;
	while(*sT++)
		nLen++;
	for( int i = 0; i<k; i++ ){
		char cTemp = *str;
		for( int j = 0; j<nLen-1; j++ ){
			str[j] = str[j+1];
		}
		str[nLen-1] = cTemp;
	}
	return str;
}
