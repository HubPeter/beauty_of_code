#include<iostream>
using namespace std;
int main( int argc, char* argv[] ){
	for( int i=0; i<argc; i++ ){
		//cout<<argv[i]<<endl;
	}
	cout<<__LINE__<<endl;
	cout<<__FILE__<<endl;
	cout<<__FUNCTION__<<endl;
	return 0;
}
