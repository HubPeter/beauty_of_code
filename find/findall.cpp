#include<list>
#include<iostream>
using namespace std;

list<int> list1;
void find_factor( int sum, int n );
int main(void){
	int sum = 2000;
	int n = 2000;
	find_factor( sum, n );
	return 0;
}
void find_factor( int sum, int n ){
	//递归出口
	if( sum<=0 || n<=0 )
		return;
	//输出结果
	if( sum == n ){
		list1.reverse();
		for( list<int>::iterator iter=list1.begin(); iter!=list1.end(); iter++ ){
			cout<<*iter<<"+";
		}
		cout<<n<<endl;
		list1.reverse();
	}
	list1.push_front( n );
	find_factor( sum-n, n-1 );//有n的情况
	list1.pop_front();
	find_factor( sum, n-1 );//没有n的情况
}
