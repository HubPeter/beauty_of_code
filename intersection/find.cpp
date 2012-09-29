#include<iostream>
#include<map>
#include<utility>
using namespace std;
#define true 1
struct NODE{
	int key;
	struct NODE* l;
	struct NODE* r;
};

struct NODE * BInsert( struct NODE* root, struct NODE* p );
void DFS( struct NODE* root );

int main(void){
	int n;
	n = 0;
	struct NODE * p = NULL;
	struct NODE * root = NULL;
	while( true ){
		cout<<"Enter n(quit with -1)";
		cin>>n;
		if( n<0 )
			break;
		p = (struct NODE*) malloc( sizeof( struct NODE ) );
		p->key = n;
		p->l = NULL;
		p->r = NULL;
		root = BInsert( root, p );
	}
	DFS( root );
}

