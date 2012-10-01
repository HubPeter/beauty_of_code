#include<iostream>
using namespace std;
#define K 5
#define P(x) (((x)+1)/2-1)
#define L(x) (((x)+1)*2-1)
#define R(x) ((((x)+1)*2)+1-1)
void TopK( int arr[], int n, int top[] );
void BuildHeap( int arr[], int n );
void MaxHeapify( int arr[], int index );
void Decrease( int top[], int index, int n, int value );
int Max( int top[] );
int main(void){
	int arr[] = { 1,2,5,7,8,229,35, 29, 385, 18543,285,238,29,32895,293,23,256,358,98 };
	int n = sizeof( arr )/4;
	int top[K] = {0,0,0,0,0};//good choice to set them to zero :)
	for( int i=0; i<n; i++ ){
		cout<<arr[i]<<endl;
	}
	TopK( arr, n, top );
	cout<<"Top "<<K<<endl;
	for( int i = 0; i<K; i++ ){
		cout<<top[i]<<endl;
	}
	return 0;
}
/*
Find Top K in arr adn put them into top
arr:array of all
n:length of arr
top: array of max_heap
*/
void TopK( int arr[], int n, int top[] ){
	//init heap
	BuildHeap( top, K );
	//for loop
	for( int i = 0; i<n; i++ ){
		if( arr[i]<Max( top ) ){
			Decrease( top, 0, K, arr[i] );
		}
	}
	return;
}
/*
top:max_heap
index:index to be decreased
value:decrease to
n:
*/
void Decrease( int top[], int index, int n, int value ){
	top[index] = value;
	while( index<n ){
		if( value<top[L(index)] ){
			top[index] = top[L(index)];
			top[L(index)] = value;
			index = L(index);
		}else if( value<top[R(index)] ){
			top[index] = top[R(index)];
			top[R(index)] = value;
			index = R(index);
		}else
			break;
	}
	return ;
}
/*
Build arr to an heap
top :heap
n: length of max_heap
*/
void BuildHeap( int top[], int n ){
	for( int i=0; i<n; i++ ){
		top[i] = 10000000; 
		//MaxHeapify( top, i );
	}
	return ;
}
/*
return max value of max_heap
top:max_heap
*/
int Max( int top[] ){
	if(top!=NULL)
		return top[0];
	return -1;
}
