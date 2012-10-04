#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
struct Node {
	int key;
	struct Node* next;
};
int main(int argc, char * argv[]){
	int a[100];
	int b[200];
	srand( (unsigned int)time(NULL) );
	for( int i=0; i<100; i++ ){
		a[i] = rand();
		b[i] = rand();
	}
	for( int i = 100; i<200; i++ )
		b[i] = rand();
	struct Node* link = NULL;
	int i=0;//to be merged
	int j=0;//to be merged
	struct Node* tail = NULL;
	while( i<100 || j<200 ){
		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
		int min;
		if( i<100 && j<200 ){//both of a and b is not empty
			if( a[i]<=b[j] ){
				min = a[i];
				++i;
			}
			else {
				min = b[j];
				++j;
			}
		}else if( i<100 ){//only a is left
			min = a[i];
			++i;
		}else{//only b is left
			min = b[j];
			++j;
		}
		if( link == NULL )
			link = node;
		node->key = min;
		if(tail == NULL)
			tail = node;
		else
			tail->next = node;
		node->next = NULL;;
	}
	struct Node* p;
	p = link;
	while( p ){
		cout<<p->key<<" ";
		p = p->next;
	}
	cout<<endl;

	return 0;
}
