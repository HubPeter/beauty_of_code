#include<stdio.h>
#include<assert.h>
#include<string.h>
int atoi( const char * str );
int main(void){
	char* str1 = "   -1234--";
	int n = atoi( str1 );
	printf("%s\n%d\n", str1, n);
	return 0;
}
int atoi( const char* str ){
	assert( str );
	int n = 0;
	int opt = 1;//+1
	char* table = "0123456789";
	char* p = (char*) str;
	while(*p == ' '){//skip space characters
		p++;
	}
	if(*p=='-'){
		p++;
		opt = -1;
	}else if(*p=='+'){
		p++;
	}
	while(*p>='0'&&*p<='9'){
	/*strchr会进行朴素的匹配，所以比较次数的期望值为5*/
		n = n*10+(*p-'0');
		p++;
	}
	return n*opt;
}
