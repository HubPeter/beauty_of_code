#include<iostream>
using namespace std;
bool IsInter( char * a, char * b );
void quickSort( char* arr );
int BSearch( char * a, char c );
int main(void){
	char a[] = "hello world";
	char b[] = "worldd";
	bool isInter = IsInter( a, b );
	cout<<isInter<<endl;
	return 0;
}
bool IsInter( char * a, char * b ){
	quickSort( a );
	quickSort( b );
	int s = BSearch( a, b[0] );
	int aLen = strlen(a);
	int bLen = strlen(b);
	if( s<aLen ){
		int j = 0;
		j++;
		i++;
		while( *a && *b ){
			if( a[j] = b[j] ){
				i++;
				j++;
			}else{
				i++;
			}
		}
		if( b[j]==0 )
			return 1;
	}
	return 0;
}
int BSearch( char * a, char c ){
	int h = strlen( a );
	int l = 0;
	int m = 0;
	while( l<h-1 ){
		m = ( h+l )/2;
		if( a[m]<c ){
			l = m;
		}else if( a[i]>c ){
			h = m;
		}else
			return m;
	}
	if( a[l]==c )
		return l;
	else if( a[h]==c )
		return h;
	return -1;
}
/*
bool IsInter( char *a, char *b ){
	quickSort( a );
	quickSort( b );
	char * ta = a;
	char * tb = b;
	while( *ta&&*tb && (*ta != *tb) ){
		ta++;
	}
	if(*ta && *tb){
		while( *ta && *tb ){
			if( *ta==*tb ){
				ta++;
				tb++;
			}else if( *ta<*tb )
				ta++;
			else
				tb++;
		}
		if( *tb==0 )
			return 1;
	}
	return 0;
}
*/
void quickSort( char* arr, int p, int r ){
	
}
/*
bool IsInter( char* a, char* b){
	for( int i = 0; a[i]!=0; i++ ){
		int j;
		for( j = 0; b[j]!=0; j++ ){
			if( a[i+j]!=b[j] )
				break;
		}
		if(b[j]==0)
			return 1;
	}
	return 0;
}
*/
