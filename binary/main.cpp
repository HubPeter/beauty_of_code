#include<iostream>
#include<stack>
using namespace std;
struct Node* Build( int arr[], int n );
void MidTravel( struct Node*tree );
void PreTravel( struct Node*tree );
void SucTravel( struct Node*tree );
void Insert( struct Node * tree, int data );
void Print(struct Node* p);
struct Node{
	int data;
	struct Node* l;
	struct Node* r;
};

int main(void){
	int arr[] = {1,3,5,6,9,39,92,0,138,39,693,9,3};
	int n = sizeof(arr)/sizeof(int);
	struct Node* tree = Build( arr, n );
	MidTravel( tree );
	return 0;
}
void Insert( struct Node * tree, int data ){
	struct Node* p = tree, *q = tree;
	//make a node
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->next = NULL;
	node->data = data;
	if( p==NULL ){
		tree = node;
		return;
	}
	//find right position
	while(p!=NULL){
		q = p;
		if( p->data<=data ){
			p = p-l;
		}else{
			p = p->r;
		}
	}
	if( q->data<=data ){
		p->l = node;
	}else{
		p->r = node;
	}
}
struct Node* Build( int arr[], int n ){
	struct Node * root = NULL;
	for(int i=0; i<n; i++){
		Insert( root, arr[i] );
	}
	return root;
}
void MidTravel( struct Node*tree ){
	stack<struct Node*> s;
	if(tree==NULL){
		return;
	}
	struct Node* p = tree;
	//go to left
	while(p!=NULL){
		s.push( p );
		p = p->l;
	}
	while(!s.empty()){
		p = s.pop();
		print( p );
		if( p->r!=NULL ){
			s.push( p->r );
		}
		//go to left
		while(p!=NULL){
			s.push(p);
			p = p->l;
		}
	}
}
void PreTravel( struct Node*tree ){
	if(tree==NULL){
		return;
	}
	struct Node *p=tree,*q=tree;
	stack<struct Node*> s;
	//go to left
	while(p!=NULL){
		Print( p );
		if(p->r!=NULL){
			s.push( p );
		}
		p = p->l;
	}
	while(!s.empty()){
		p = s.pop();
		Print(p);
		//go to left
		while(p!=NULL){
			Print( p );
			if(p->r!=NULL){
				s.push( p->r );
			}
			p = p->l;
		}
	}
}
void SucTravel( struct Node*tree ){
	if(tree==NULL){
		return;
	}
	
}
void Print(struct Node* p){
	printf("%d	", p->data);
}
