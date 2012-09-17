#include<iostream>

using namespace std;
int Gcd( int ,int );
int main(void){
	int nA,nB;
	cout<<"Enter A:";
	cin>>nA;
	cout<<"Enter B:";
	cin>>nB;
	if( nA>0 && nB>0 ){
		cout<<nA<<endl<<nB<<endl;
		cout<<Gcd( nA, nB );
		cout<<endl;
	}
	return 0;
}
/*
To compute Greatest Common Divisor
by travelsal
*/
/*
int Gcd( int nA, int nB ){
	//if GCD is ok nA or nB will be zero
	while( nA>0 && nB>0 ){
		//nA = nB mod nA
		nA = nA % nB;
		// exchange nA and nB
		int temp = nA;
		nA = nB;
		nB = temp;
	}
	if( nA == 0 )
		return nB;
	else 
		return nA;
}
*/
/*
By reverse
*/
/*
int Gcd(int nA, int nB){
	if( nA==0 )
		return nB;
	return Gcd( nB%nA, nA );
}
*/
/*
	with 2
*/
int Gcd(int nA, int nB){
	if( nA>nB )
		return Gcd( nB, nA );
	if( nA == 0 )
		return nB;
	if( nB%2==0 ){
		if( nA%2==0 )
			return Gcd( (nB>>1)%nA, nA>>1 )<<1;
		else
			return Gcd( (nB>>1)%nA, nA );
	}
	else
		return Gcd( nB%nA, nA );
}
