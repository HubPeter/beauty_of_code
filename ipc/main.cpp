#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main(void){//8048644
	int begin = 0x100;//bffff1cc
	long end = 0x40000000;//bffff1d0
	static int n = 1024;//804a030
	cout<<n<<endl;
	//0x804 84c9 bfff f1b0
	long size = end - begin;//bffff1d4
	char* str = (char*)malloc(sizeof(char)*size);//bffff1d8->804863`9
	char* s = (char*) malloc(sizeof(char)*size);//bffff1dc->b7edcff4
	memset(str, 0, size);//b7db8ef0
	memset(s, 0, size);
	return 0;
}
