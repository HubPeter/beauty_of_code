#include<iostream>
using namespace std;
#define K 5
void TopK( int arr[], int b, int e, int k );
int main(void){
	int arr[] = {3,5,85,2953,2354,39,928,210,23,3852,298,3831,8738,8,2943,285};
	int n = sizeof(arr)/4;
	TopK( arr, 0, n-1, K );
	for(int i = 0; i<K; i++ ){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
	return 0;
}
/*

*/
int Partition( int arr[], int b, int e ){
	int i = b-1;
	int j = b;
	int key = arr[e];
	while( j<e ){
		if( arr[j]<=key ){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	i++;
	arr[e] = arr[i];
	arr[i] = key;
	return i-b+1;
}
/*
Get top k
int array
begin 
end
k to get
*/
void TopK( int arr[], int b, int e, int k ){
	if(b>=e)
		return;
	int c = Partition( arr, b, e );
	if( c==k ){
		return;
	}else if(c<k){//not enough
		TopK( arr, b+c, e, k-c );
	}else{//more than need
		TopK( arr, b, e-1, k );
	}
	return ;
}
