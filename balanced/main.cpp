/*
check if a string is balanced
(hello {workd , i [comes from {china shandong(chiping)}]})
*/
#include<iostream>
#include<stack>
using namespace std;
int main(void){
	//one pointer 
	stack<char> sOperator;
	char * sStr="hello {workd , i [comes from {china shandong\
		(chiping)}]})";
	char* pCur=sStr;
	bool bBalanced = 1;
	while( *pCur!='\0' ){
		if( *pCur=='(' || 
			*pCur=='[' || 
			*pCur=='{' ) {
			sOperator.push( *pCur );
		}else if(*pCur==')'){
			if(!sOperator.empty() && sOperator.top()=='('){
					sOperator.pop();
			}else{
				bBalanced=false;
				break;
			}
		}else if(*pCur==']'){
			if(!sOperator.empty() && sOperator.top()=='['){
				sOperator.pop();
			}else{
				bBalanced=false;
				break;
			}
		}else if(*pCur=='}'){
			if(!sOperator.empty() && sOperator.top()=='{'){
				sOperator.pop();
			}else{
				bBalanced=false;
				break;
			}
		}
		pCur++;
	}
	if( bBalanced )
		cout<<"Balanced string"<<endl;
	else 
		cout<<"Not balanced string"<<endl;
		
}
