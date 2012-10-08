/*
数组是按照顺序存放的
big end:	顺序存放，低地址存放低位，高地址存放高位
*/

#include<iostream>

using namespace std;
union U{
	short s;
	char c[2];
};
int main(void){

	union U u;
	u.s = 0x0102;
	if( sizeof(u.s)==2 ){
		if( u.c[0]==0x01&&u.c[1]==0x02 ){
			cout<<"Big endian.\n"<<endl;
		}else{
			cout<<"Little endian.\n"<<endl;
		}
	}
	return 0;
}
