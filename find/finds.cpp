#include<iostream>
using namespace std;
bool Find2( int arr[], int sum, int n );
void quickSort( int arr[], int p, int r );
int partition( int arr[], int p, int r );
void Show( int arr[] );
int main(void){
	int arr[] = {2,3,5,38, 8, 5, 2, 58, 2, 5, 8, 3, 98, 29};
	int n = sizeof(arr)/sizeof(int);
	int sum = 7;
	bool rst = Find2( arr, sum, n );
	cout<<rst<<endl;
	return 0;
}
/*
fidn 2 number sum of them is sum
*/
bool Find2( int arr[], int sum, int n ){
	Show( arr );
	quickSort( arr, 0, n-1 );
	Show( arr );
	int l = 0;
	int h = n-1;
	while( l<h ){
		int nSum = arr[l] + arr[h];
		if( nSum==sum ){
			cout<<arr[l]<<"+"<<arr[h]<<endl;
			return 1;
		}else if(nSum<sum){
			++l;
		}else {
			--h;
		}
	}
	return 0;
}
void quickSort( int arr[], int p, int r ){
	if( p<r ){
		int i = partition( arr, p, r );
		quickSort( arr, p, i-1 );
		quickSort( arr, i+1, r );
	}
}
int partition( int arr[], int p, int r ){
	int i = p-1;
	int j = p;
	int key = arr[r];
	while( j<r ){
		if( arr[j]<=key ){
			++i;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		++j;
	}
	--j;
	++i;
	arr[r] = arr[j];
	arr[i] = key;
	return i;
}
void Show( int arr[] ){
	for( int i = 0; i<14; i++ ){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return ;
}
