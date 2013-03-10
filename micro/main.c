#include<stdio.h>

#define ADD(x,y) ((x)+(y))
#define cmp(x, y) ( (x)>(y)?(x):(y) )

int main(void){
	int x = 10;
	int y = 100;
	printf("%d\n", ADD(x, y));
	printf("%d\n", cmp(x, y));
	
	return 0;
}
