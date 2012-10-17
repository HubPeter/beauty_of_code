/*
问题描述：设有3个传教士（Missionaries）和3个野人(Cannibals)
来到河边，打算乘一只船从右岸渡到左岸去。该船的最大负荷能力
为两个人（k=2）。在任何情况下：如果野人人数超过传教士人数，
那么野人就会把传教士吃掉。他们怎样才能用这条船安全地把所有
人都渡过河去呢？（提示：用状态空间来描述，其综合数据库：
用三元数组表示， m表示传教士，c表示野人，b表示船状态)

这个问题是人工智能中经典的搜索问题，下面用深度优先搜索算法
来解这个题，示例代码如下：
*/
#include <iostream>  
#include <vector>  
#include <list>  
using namespace std;  

typedef struct  
{
    int m;//表示传教士  
    int c;// 表示野人  
    int b;//船状态0:left 1:right
}MCNode;
  
list<MCNode> fringe;//相当于队列  
vector<MCNode> closed;//closed表  
  
//判断是否是目标结点  
bool IsGoal(MCNode tNode)  
{  
    if(tNode.m==0&&tNode.c==0&&tNode.b==0)  
        return true;  
    else  
        return false;  
}  
//判断是否是合法状态  
bool IsLegal(MCNode tNode)  
{  
    if(tNode.m>=0&&tNode.m<=3&&tNode.c>=0&&tNode.c<=3)//保证数量合法
    {  
        if((tNode.m==tNode.c)||(tNode.m==3)||(tNode.m==0))
			//>传教士和野人数量相等 >全是传教士 >没有传教士?
            return true;  
        else  
            return false;  
    }  
    else  
        return false;  
}  
//重载运算符，判断两结构体是否相等  
bool operator==(MCNode m1,MCNode m2)  
{  
    if(m1.m==m2.m&&m1.c==m2.c&&m1.b==m2.b)  
        return true;  
    else  
        return false;  
}  
//判断是否已在closed表中  
bool IsClosed(MCNode tNode)  
{  
    int i;  
    for(i=0;i!=closed.size();i++)  
    {  
        if(tNode==closed[i])  
            return true;  
    }  
    if(i==closed.size())  
        return false;  
}  
void ExpandNode(MCNode tNode,int b,list<MCNode> &fringe)  
{  
    MCNode node[5];//应用5条规则集生成新结点  
    if(b==1)//船上有一个人
    {  
        for(int i=0;i<5;i++)  //初始化规则集
            node[i].b=0;  
		//1个传教士上船
        node[0].m=tNode.m-1;  
        node[0].c=tNode.c;  
		//1个野人上船
        node[1].m=tNode.m;  
        node[1].c=tNode.c-1;  
		//1个野人1个传教士
        node[2].m=tNode.m-1;  
        node[2].c=tNode.c-1;  
		//2传教士
        node[3].m=tNode.m-2;  
        node[3].c=tNode.c;  
		//2野人
        node[4].m=tNode.m;  
        node[4].c=tNode.c-2;  
    }  
    else  
    {  
        for(int i=0;i<5;i++)  
            node[i].b=1;  
        node[0].m=tNode.m+1;  
        node[0].c=tNode.c;  
        node[1].m=tNode.m;  
        node[1].c=tNode.c+1;  
        node[2].m=tNode.m+1;  
        node[2].c=tNode.c+1;  
        node[3].m=tNode.m+2;  
        node[3].c=tNode.c;  
        node[4].m=tNode.m;  
        node[4].c=tNode.c+2;  
    }  
    for(int i=0;i<5;i++){
        if(IsLegal(node[i])&&!IsClosed(node[i])){//当前\
			状态合法，且已在closed表中
            fringe.push_front(node[i]);//队列后进先出，\
				深度优先搜索，最后得到一条最小解序列  
            //fringe.push_back(node[i]);//队列后进后出,\
				广度优先搜索，最后得到最小解序列状态空间图  
		}
	}
}  
void main()  
{  
    MCNode InitNode,//初始状态
		unode;  
    InitNode.m=3;  
    InitNode.c=3;  
    InitNode.b=1;  
    fringe.push_back(InitNode);//将初始状态空间加入到队列  
    while(!fringe.empty()) //not empty 
    {  
        unode=fringe.front();  //get head
        fringe.pop_front();  
        if(IsGoal(unode))  //是目标状态
        {  
            closed.push_back(unode);  //
            for(int i=0;i!=closed.size();i++)  
                cout<<closed[i].m<<","<<closed[i].c<<","<<closed[i].b<<endl;  
            break;  
        }  
        if(!IsClosed(unode))  
        {  
            closed.push_back(unode);  //
            ExpandNode(unode,unode.b,fringe);  
        }  
    }  
}  
