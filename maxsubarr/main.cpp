#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int maxSubArr( int arr[], int size );
int main(void){
	int arr[] = {1,3,-5,0,-8,-2,65,-3};
	int max = maxSubArr(arr, sizeof(arr)/sizeof(int));
	cout<<max<<endl;
	return 0;
}
/*
*/
int maxSubArr( int arr[], int size ){
	if (size<=0){
		printf("Error array size.\n");
		exit(1);
	}
	int sum = 0;
	int max = -(1<<31);
	int cur = 0;
	while(cur<size){
		sum += arr[cur++];
		if(sum > max){//如果增加了，就更新最大值
			max = sum;
		}else if(sum<0){//没有增加，就是减少了，和是负数，则会减少和值，\
			应该清零
			sum = 0;
		}
	}
	return max;
}
