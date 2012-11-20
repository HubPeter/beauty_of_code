#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
using std::setprecision;
#define SIZE 100000
#define MAX 100000
/*
1000ms

100000
100000.00000000

space <---> time
*/

double fRand(double fMin, double fMax);

int main(void){
	//gen
	double arrData[SIZE];
	for( int i=0; i<SIZE; i++ ){
		arrData[i] = fRand( 0, 99999.99999999 );
	}
	//---gen
	//sort
	//base number sort and non-unique
	int arrCount[MAX];
	int arrCountTemp[MAX];
	int arrStartTemp[MAX];
	for( int i=0; i<MAX; i++ ){
		arrCount[i] = 0;
		arrCountTemp[i] = 0;
		arrStartTemp[i] = 0;
	}
	for( int i=0; i<SIZE; i++ ){
		arrCount[ (int)arrData[i] ]++;
		arrCountTemp[ (int)arrData[i] ]++;
	}
	for( int i=1; i<MAX; i++ ){
		arrCount[i] = arrCount[i] + arrCount[i-1];
		arrStartTemp[i] = arrCount[i-1];
	}
	double arrNew[SIZE];
	for( int i=0; i<SIZE; i++ ){
			arrNew[arrCount[(int)arrData[i]] - 1 ] = arrData[i];//0 based,第一个
			arrCount[(int)arrData[i]]--;
	}
	for( int i=0; i<MAX; i++ ){
		//sort( arrNew, curStart, curStart+countCur );
		for( int out=arrStartTemp[i]+arrCountTemp[i]-1; out>=arrStartTemp[i]+1; out-- ){
			for( int in=arrStartTemp[i]+1; in<=out; in++ ){
				if( arrNew[in]<arrNew[in-1] ){
					double temp = arrNew[in];
					arrNew[in] = arrNew[in-1];
					arrNew[in-1] = temp;
				}
			}
		}
	}
	
	//---sort
	//show
	for(int i=1; i<=SIZE; i++){
			cout<<setprecision(20)<<arrNew[i]<<endl;
	}
	//---show
}

double fRand(double fMin, double fMax)
{
	while(true){
    	double f = (double)rand() / RAND_MAX;
		double r = fMin + f * (fMax - fMin);
		if(r>=0)
			return r;
	}
}
