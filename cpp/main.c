#include<stdio.h>
void F(){
	static int n = 100;
	n++;
}
int main(void){
	F();
	F();
	F();
	F();
	return 0;
}
