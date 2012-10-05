#include<iostream>
using namespace std;
bool Find( int yang[][4], int k );
int main(void){
	int yang[4][4]={
	{1,	2,	8,	9},
	{2,	4,	9,	12},
	{4,	7,	10,	13},
	{6,	8,	11,	15},
	};
	bool r = Find( yang, 6);
	cout<<r<<endl;
	return 0;
}
bool Find( int yang[][4], int k ){
	int i = 0;
	int j = 3;
	int val = yang[i][j];
	while( i<4 && j>-1 ){
		if( val == k )
			return true;
		else if( val < k ){
			val = yang[++i][j];
		}else{
			val = yang[i][--j];
		}
	}
}
/*
全部递归，
矩阵规模：n
时间复杂度是：n
空间复杂度为lgn
*/
/*
bool Find0( int yang[4][4], int row, int col, int rows,  int k ){
	//find on cross line
	if( rows==1 ){
		if( yang[row][col]==k ){
			cout<<"little:"<<row<<" "<<col<<endl;
			return true;
		}else{
			//此处显示了我对递归理解的不够到位，基本路术
			return false;
		}
	}
	//cut to four little yangs
	rows = rows/2;
	bool r =(Find( yang, row, col, rows, k ) ||
		Find( yang, row, col+rows, rows, k ) ||
		Find( yang, row+rows, col, rows, k ) ||
		Find( yang, row+rows, col+rows, rows, k) );
	
	return r;
}
*/
