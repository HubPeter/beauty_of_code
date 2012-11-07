/*
bit operations imple /13
*/
#include<iostream>
using namespace std;

int bMul(int nA, int nB);
int bDiv(int nA, int nB);

int main(void){
	int nA, nB;
	cin>>nA>>nB;
	int nTotal = 0;
	nTotal = bMul( nA, nB );
	cout<<nA<<" x "<<nB<<" = "<<nTotal<<endl;
	return 0;
}
int bMul(int nA, int nB){
	int nTotal = 0;
	while( nB>0 ){
		if( nB&1 ){
			nTotal += nA;
		}
		nA <<= 1;
		nB = nB >> 1;
	}
	return nTotal;
}
