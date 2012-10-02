/*
KMP
*/
#include<iostream>
#include<cstring>
using namespace std;
int KMP( char* T, char* P );
void CompPi( char * P, int pi[] );
int main(void){
	char *T = "Hell world,my name is liudedepeng, I comes from HITWH.";
	char *P = "liudedepeng";
	int index = KMP( T, P );
	cout<<index<<endl;
	return 0;
}
/*
Find P in T
return index
*/
int KMP( char * T, char * P ){
	int nP = strlen( P );//length of P
	int nT = strlen( T );//length of T
	int pi[nP];//pi array of P
	//initialize pi
	for( int i = 0; i<nP; i++ ){
		pi[i] = 0;
	}
	CompPi( P, pi );//Cpmpute pi of P
	int q = -1;//status
	int i = 0;//To travelsal T with pi
	while( i<nT ){
		//q is already Ok count
		while( q>-1 && P[q+1]!=T[i] ){
			q = pi[q];
		}
		if( P[q+1]==T[i] ){
			q = q+1;
		}
		if( q==nP ){
			return i-nP;
		}
		i++;
	}
	return -1;
}
/*
Cpmpute pi array of P
*/
void CompPi( char * P, int pi[] ){
	int nP = strlen( P );
	pi[0] = -1;
	int k = -1;
	int q = 1;//Must from 1
	while( q<nP ){
		while( k>-1 && P[k+1]!=P[q] ){
			k = pi[k];
		}
		if( P[k+1]==P[q] ){
			k = k+1;
		}
		pi[q] = k;
		q++;
	}
	return ;
}
