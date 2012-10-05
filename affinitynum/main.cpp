/*
亲和数：a，b
a的所有真因子之和等于b
b的所有真因子之和等于a
*/
#include<iostream>
#include<cstdlib>
using namespace std;
#define N 50000//范围
void FindAff( int n );
int Sum( int n );
int main(void){
	FindAff( N );
	return 0;
}
/*
分解因式
质数
*/
int Sum( int n ){
	int sum = 0;
	for( int i = 2; i<n/2; i++ ){
		if( n%i==0 )
			sum+=i;
	}
	return sum;
}
void FindAff( int n ){
	int *arrSum = (int*)malloc( sizeof(int)*n );
	arrSum[0] = 0;
	arrSum[1] = 1;
	for( int i = 2; i<n; i++ ){
		arrSum[i] = Sum( i );
	}
	for( int i = 2; i<n; i++ ){
		if( arrSum[i]<=n && arrSum[i]>0 ){
			cout<<i<<"--"<<arrSum[i]<<endl;
		}
	}
	return ;
}
