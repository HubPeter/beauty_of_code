#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include"link.h"
using namespace std;

int main( void ){
	int LENGTH = 1024*100;
	LINK link1 = create_link( LENGTH );
	//cout<<"link1:"<<endl;
	show_link( link1 );
	LINK link2 = create_link( LENGTH );
	//cout<<"link2:"<<endl;
	show_link( link2 );
	LINK link = merge_local( link1, link2 );
	link1 = NULL;
	link2 = NULL;
	//cout<<"new link:"<<endl;
	show_link( link );
	//cout<<"freeing ..."<<endl;
	link = free_link( link );
	show_link( link );
	return 0;
}


PNode merge_local( LINK link1, LINK link2 ){
	LINK link = NULL;//new link
	PNode tail = NULL;
	
	while( link1!=NULL || link2!=NULL ){
		//cout<<"before extract "<<endl;
		//cout<<"Link---1---";
		show_link(link1);
		//cout<<"Link---2---";
		show_link(link2);
		//find min
		PNode next = extract_min( &link1, &link2 );
		//attach to the tail
		//cout<<"before attach "<<endl;
		//cout<<"Link---1---";
		show_link(link1);
		//cout<<"Link---2---";
		show_link(link2);
		link = attach_tail( link , &tail, next );
	}
	return link;
}
void show_link( LINK link ){
	/*
	while( link!=NULL ){
		cout<<link->data<<"  ";
		link = link->next;
	}
	cout<<endl;
	*/
}
LINK create_link( int count ){
	LINK link = NULL;
	int length = 0;
	for( int i=0; i<count; i++ ){
		length = get_length( link);
		PNode node = (PNode)malloc( sizeof(struct Node) );
		int data = rand()%1024;
		node->data = data;
		node->next = NULL;
		if( NULL==link ){
			link = node;
		}
		else{
			//insert in right way;
			PNode p = link;
			PNode pre = p;
			while( p!=NULL && data>p->data ){
				pre = p;
				p = p->next;
			}
			if( pre->data<=data ){
				node->next = pre->next;
				pre->next = node;
			}else if( p!=NULL ){
			    node->next = link;
				link = node;
			}
			
		};
		//check count;
		if( get_length(link)<length ){
			cout<<"Bad insert after inserted "<<data<<endl;
			show_link( link );
		}
		
	}
	return link;
}
LINK free_link( LINK link ){
	PNode p = NULL;
	while( link!=NULL ){
		p = link;
		link = link->next;
		p->next = NULL;
		free( p );
	}
	return NULL;
}
int get_length( LINK link ){
	int length = 0;
	while( link!=NULL ){
		length++;
		link = link->next;
	}
	return length;
}
//get min and move to the next
PNode extract_min( LINK* l1, LINK* l2 ){
	PNode next = NULL;
	if( NULL==*l1 ){
		next = *l2;
		*l2 = (*l2)->next;
	}else if( NULL==*l2 ){
		next = *l1;
		*l1 = (*l1)->next;
	}else{
		if( (*l1)->data<=(*l2)->data ){
			next = *l1;
			*l1 = (*l1)->next;
		}else{
			next = *l2;
			*l2 = (*l2)->next;
		}
	}
	next->next = NULL;
	return next;
}
//attach node to link
LINK attach_tail( LINK link, PNode* tail, PNode node ){
	if( NULL==link ){
		*tail = node;
		return node;
	}
	/*
	PNode p = link;
	while( p->next!=NULL ){
		p = p->next;
		}
	p->next = node;
	*/
	(*tail)->next = node;
	*tail = node;
	return link;
}
