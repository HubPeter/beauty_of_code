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
	CompPi( P, pi );//Cpmpute pi of P
	int q = 0;//status
	int i = 0;//To travelsal T with pi
	while( i<nT ){
		while( q>0 && P[q+1]!=T[i+1] ){
			q = pi[q];
		}
		if( P[q+1]==T[i+1] ){
			q = q+1;
		}
		i = i+1;
		if( q==nP ){
			return i-nP+1;
		}
	}
	return -1;
}
/*
Cpmpute pi array of P
*/
void CompPi( char * P, int pi[] ){
	int nP = strlen( P );
	pi[0] = 0;
	int k = 0;
	int q = 0;
	while( q<nP ){
		while( k>0 && P[k+1]!=P[q+1] ){
			k = pi[k];
		}
		if( P[k+1]==P[q+1] ){
			k = k+1;
		}
		q++;
		pi[q] = k;
	}
	return ;
}
