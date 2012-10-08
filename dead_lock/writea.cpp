//writea.cpp
#include<iostream>
#include<fcntl.h>
#include<stdio.h>
using namespace std;
int main(void){
	int fda,fdb;
	char str[1024];
	fda = open("filea", O_WRONLY);
	//fprintf(fda, "I Love You A");
	fdb = open("fileb", O_RDONLY);
	//fscanf(fdb, "%s", str);
	//cout<<str<<endl;
	return 0;
}
