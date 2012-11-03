/*
two sorted arrays find the intersections of them
*/
#include<iostream>
using namespace std;
int main(void){
	int nArr1[] = {1, 2, 4, 9, 89, 90, 97, 102, 103};
	int nArr2[] = {4, 9, 90, 102, 103, 111, 123, 455, 999};
	//two pointers
	//length of them
	int nLenArr1 = sizeof(nArr1)/sizeof(int);
	int nLenArr2 = sizeof(nArr2)/sizeof(int);
	//loop
	int nCur1=0,nCur2=0;
	while((nCur1<nLenArr1)&&(nCur2<nLenArr2)){//what is the boundary!!!
		//find one next
		if( nArr1[nCur1]==nArr2[nCur2] ){
			cout<<nArr1[nCur1]<<"	";
			nCur1++;
			nCur2++;
		}else if(nArr1[nCur1]<nArr2[nCur2]){
			nCur1++;
		}else{
			nCur2++;
		}
	}
	cout<<endl;
}
