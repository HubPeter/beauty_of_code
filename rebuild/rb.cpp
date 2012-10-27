#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define TREESZ 10

struct NODE {
	struct NODE* pLeft;
	struct NODE* pRight;
	char cValue;
};
typedef struct NODE* pNODE;
typedef struct NODE* pTREE;


void showStr( char* b, char * e );
pTREE tTree = NULL;//Original tree
pTREE tReTree = NULL;//Rebuilt tree
void buildTree( pTREE* _tMyTree, int nNodeCount );
void reBuildTree( pTREE* _tMyTree, char *sPre, char* sPreE, char *sIn, \
	char *sInE );
void preTra( pTREE tMyTree, char sPre[] );
void inTra( pTREE tMyTree, char sIn[] );

int main(void){
	char sPre[TREESZ+10];//PreOrder
	memset( sPre, '\0', sizeof(sPre) );
	char sIn[TREESZ+10];//Inoder
	memset( sIn, '\0', sizeof(sIn) );
	//Build tree tTree
	buildTree( &tTree, TREESZ );
	preTra( tTree, sPre );//得到先序
	inTra( tTree, sIn );//得到中序
	//输出原来的树的结果
	cout<<"Pre:	";
	cout<<sPre<<endl;
	cout<<"In:	";
	cout<<sIn<<endl;
	//重建
	reBuildTree( &tReTree, sPre, sPre+TREESZ-1, sIn, sIn+TREESZ-1 );
	//得到序列
	memset( sPre, 0, sizeof(sPre) );
	preTra( tReTree, sPre );//cover sPre
	//输出＆对比
	memset( sIn, 0, sizeof(sIn) );
	inTra( tReTree, sIn );//Cover :D
	cout<<"Pre:	"<<sPre<<endl;
	cout<<"In:	"<<sIn<<endl;
	return 0;
}
/*
*Build a tree
full complete binary tree
*/
void buildTree( pTREE* _tMyTree, int nNodeCount ){
	free( *_tMyTree );
	*_tMyTree = NULL;
	bool bEmpty = true;
	pNODE pNode = NULL, pParent = NULL;
	char cValue = '\0';
	int nChildStatus = 0;//记录当前节点的儿子节点的数量
	int nCurNodeCount = 0;//记录已经插入的节点的数量
	char sBuffer[nNodeCount+1];//存放已经使用过的字符，防止重复
	memset( sBuffer, '\0', sizeof(sBuffer) );
	char *pFind = NULL;
	queue<pNODE> qParent;//to store parents
	while( nCurNodeCount<nNodeCount ){//循环生成nNodeCount个节点
		//make node
		pNode = new NODE;
		pNode->pLeft = pNode->pRight = NULL;
		cValue = '\0';//clear cValue
		while( !( (cValue>='A' && cValue<='Z') || //不连续
				(cValue>='a'&& cValue<='z') ) ){
			cValue = random()%128;
			//防止节点数据的重复
			pFind = find( sBuffer, sBuffer+nCurNodeCount, cValue );
			if( pFind!=sBuffer+nCurNodeCount )//防止节点数据的重复
				continue ;
			//___防止节点数据的重复
		}
		pNode->cValue = cValue;
		qParent.push( pNode );//将生成的节点添加到队列
		//___end of make node

		//将生成的字符存入sBuffer 防止重复
		sBuffer[nCurNodeCount] = cValue;//此时nCurNodeCount未++
		//___将生成的字符存入sBuffer 防止重复
		
		//Handle empty tree
		if( bEmpty==true ){
			*_tMyTree = pNode;
			bEmpty = false;
	
		//___end of handle empty tree
			//如果当前父亲节点为空 或 当前节点已满：需要新的父节点
			pParent = qParent.front();
			qParent.pop();
			//nChildStatus = 0;
		}else{
			if( nChildStatus==2 ){//准备新节点
				pParent = qParent.front();
				qParent.pop();
				nChildStatus = 0;
			}
			if( nChildStatus==0 ){
				pParent->pLeft = pNode;
				nChildStatus = 1;
			}else if (nChildStatus==1){//stick to right
				pParent->pRight = pNode;
				nChildStatus = 2;
			}else ;
		}
		//1.每个节点都被push到队列中
		//完全二叉树，理论上可以使用队列思想
		//___stick node to pParent
		nCurNodeCount++;//成功插入了一个节点
	}
}
/*
*中序遍历，把结果放在sIn中
*/
void inTra( pTREE tMyTree, char sIn[] ){
	if( tMyTree==NULL )
		return ;
	//left
	inTra( tMyTree->pLeft, sIn );
	//mid
	int nLen = strlen( sIn );
	sIn[nLen] = tMyTree->cValue;
	//right
	inTra( tMyTree->pRight, sIn );
}

/*
* Rebuild from preorder travelsal nodes
*
*/
void reBuildTree( pTREE* _tMyTree, char *sPre,char* sPreE, \
	char *sIn, char* sInE){
	if( sPreE-sPre != sInE-sIn ){
		cout<<"调用参数出错"<<endl;
		return ;
	}
	int nLen = sPreE - sPre + 1;//计算总长度
	//root<-sPre
	pNODE pRoot = new NODE;
	char cValue = *sPre;//从前序中获取根节点
	char *pInLeft = NULL;//中 左子树
	char *pInRight = NULL;//中 右子树
	char *pPreLeft = NULL;//前 左子树
	char *pPreRight = NULL;//前 右子树
	//root
	pRoot->pLeft = pRoot->pRight = NULL;
	pRoot->cValue = cValue;
	(*_tMyTree) = pRoot;
	if( nLen==1 )
		return ;
	//___root
	char *pRootInIn = find( sIn, sInE+1, cValue );//begin=<l<end
	
	int nLeftLen = pRootInIn - sIn;//计算左子树的长度
	
	int nRightLen = nLen - 1 -nLeftLen;//右子树的长度
	if( nRightLen==-1 )
		cout<<endl;
	//<--------------->
	//Root<----nLeftLen--------><---------nRightLen-----------> Pre
	//<----nLeftLen-------->Root<---------nRightLen-----------> In
	pPreLeft = sPre + 1;
	pPreRight = sPre + nLeftLen + 1;
	pInLeft = sIn;
	pInRight = sIn + nLeftLen + 1;
	//输出调用过程
	
	//___输出调用过程
	//left	
	if( nLeftLen>0 ){
		showStr( pPreLeft, pPreLeft+nLeftLen-1 );
		cout<<"-----";
		showStr( pInLeft, pInLeft+nLeftLen-1 );
		cout<<endl;
		reBuildTree( (pTREE*)&((*_tMyTree)->pLeft),
					pPreLeft, 
					pPreLeft+nLeftLen-1, 
					pInLeft, 
					pInLeft+nLeftLen-1 );
	}
	//___left
	//right
	if( nRightLen>0 ){
		showStr( pPreRight, pPreRight+nRightLen-1 );
		cout<<"-----";
		showStr( pInRight, pInRight+nRightLen-1 );
		cout<<endl;
		reBuildTree( &((*_tMyTree)->pRight), 
					pPreRight,
					pPreRight+nRightLen-1, 
					pInRight, 
					pInRight+nRightLen-1 );
	}
	//___right
}
/*
*Preorder travelsal
*/
void preTra( pTREE tMyTree, char *sPre ){
	if( tMyTree==NULL )
		return ;
	int nLen = strlen( sPre );
	sPre[nLen] = tMyTree->cValue;
	preTra( tMyTree->pLeft, sPre );
	preTra( tMyTree->pRight, sPre );
}
void showStr( char* b, char * e ){
	while( b<=e ){
		cout<<*b;
		b++;
	}
}
