#ifndef _LINK_H_

#include<iostream>
using namespace std;

struct Node{
	struct Node* next;
	int data;
};
typedef struct Node *PNode, *LINK;

PNode merge_local( LINK link1, LINK link2 );
void show_link( LINK link );
LINK create_link( int count );
LINK free_link( LINK link );
int get_length( LINK link );
PNode extract_min( LINK*, LINK* );
LINK attach_tail( LINK link,PNode* tail, PNode node );

#define _LINK_H_
#endif

