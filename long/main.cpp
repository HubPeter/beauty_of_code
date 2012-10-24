#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define MAXSZ 100

void Multiply( char sResult[MAXSZ], char sNumber1[MAXSZ], char \
	sNumber2[MAXSZ], int nLenNum1, int nLenNum2 );

int main(void){
	//1000000 put from low index
	char sNumber1[MAXSZ];
	char sNumber2[MAXSZ];
	char sResult[MAXSZ];
	// Clear your house
	for( int iStr=0; iStr<MAXSZ; ++iStr ){
		sNumber1[iStr] = '0';// Not '\0'
		sNumber2[iStr] = '0';
		sResult[iStr] = '0';
	}
	cout<<"Input number1:"<<endl;
	cin>>sNumber1;
	cout<<"Input number2:"<<endl;
	cin>>sNumber2;
	Multiply( sResult, sNumber1, sNumber2, strlen(sNumber1), \
		strlen(sNumber2) );
	cout<<sNumber1<<endl;
	cout<<"*"<<endl;
	cout<<sNumber2<<endl;
	cout<<"="<<endl;
	cout<<sResult<<endl;
}
void Multiply( char *sResult, char *sNumber1, char *sNumber2, \
		int nLenNum1, int nLenNum2 ){
	/*12385937 sNumber2    A little obscure, outer loop is slow
	*x  285693 sNumber1    we use sNumber1's every bit to multiply
	*					   sNumber2
	*/
	//compute from low index 
	//Use sNumber1's each bit to multiply sNumber2
	for(int iOfNum1=0; iOfNum1<nLenNum1; ++iOfNum1){
		//Compute sNumber1[iOfNum1] * sNumber2
		/*
		* 285930731
		* x    3
		*/
		for(int iOfNum2=0; iOfNum2<nLenNum2; ++iOfNum2){
			/* :)! order is human, but I compute in machine way, no difference :D
			*  28593 7 37
			*  x---  8 --
			* =    56
			*/
			/*
			* here '7' x '8' : still in ASCII style
			*/
			int nResult2D = (sNumber1[iOfNum1]-'0') * (sNumber2[iOfNum2]-'0');
			/*
			* I get 56, now I add it to sResult
			* Assume sResult is:
			*   19209987
			*   +     56 So,Carry here,
			*          3  carry:1
			*        ...  Loop until carry is 0
			*/
			int iForLocalAdd = iOfNum1;// Index 0 is lowest data remember
			int nCarry = nResult2D % 10;// To remember carry result from \
					add, like 7*8,carry is 5
			int nReminder =nResult2D - nCarry*10;// Hers is for example \
					56 - 50 = 6;
			int nResultLocalMultiply;
			while( iForLocalAdd<MAXSZ ){// Take care of your National \
					Boundary, Notice is following
				nReminder = sResult[iForLocalAdd]-'0'+ nReminder;
				if( nReminder>=0 ){
					nReminder -= 10;
					nCarry++;
				}
				sResult[iForLocalAdd] += nReminder;// char+int:'4'+4 = 8 :D
				if( nCarry==0 ){// No carry here, you are free
					break;
				}
			}
			// Check overflow, sorry This is still Boundary :(
			if( iForLocalAdd>=MAXSZ ){
				perror("Result overflow.");
				exit(1);
			}
		}
		
	}






	//Reverse Result <-- to show Result in human way :D
	//I love U Douban
	
	
}
