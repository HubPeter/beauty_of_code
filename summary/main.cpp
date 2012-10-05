/*
生成最短摘要并输出
way1:遍历所有可能的字符串，找出最短摘要并返回最小长度
*/
/*
主函数中使用的方法的实现有问题，会进入死循环，在33行处
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define K 3
int summary( char *article[], int len, char* key[], int n );
bool IsAllExisted( int result[], int n );
int main(void){
	char *article[] = {"hello","world", "my", "name", "is", "linux", \
		"i", "lvoe", "hello", "coding", "and", "i", "am", "coding", \
		"so", "do", "you", "love", "coding", "and", "me"};
	char *key[3] = {"hello", "linux", "coding"};
	int n = 3;//count of key words
	int result[3] = {0,0,0};
	int pBegin = 0;
	int pEnd = 0;
	int nLen = sizeof(article)/sizeof(char*);
	int nMin = nLen;
	int nAbstractBegin;
	int nAbstractEnd;
	while(true){
		while(!IsAllExisted(result, n) && pEnd<nLen ){
			for( int i = 0; i<n; i++ ){
				if( strcmp( article[pEnd], key[i] )==0 )
				result[i]++;
			}
			pEnd++;
		}
		while(IsAllExisted( result, n )){
			if( pEnd-pBegin<nMin ){
				nMin = pEnd-pBegin;
				nAbstractBegin = pBegin;
				nAbstractEnd = pEnd;
			}
			for( int i = 0; i<n; i++ ){
				if( strcmp( article[pBegin], key[i] )==0 ){
						result[i]--;
				}
			}
			pBegin++;
		}
		if(pEnd>nLen){
			break;
		}
	}
	cout<<nMin<<endl;
	return 0;
}
bool IsAllExisted( int *result, int n ){
	int i = 0;
	while(i<n){
		if( result[i]==0 ){
			return false;
		}
		i++;
	}
	return true;
}
int summary1( char *article[], int len, char* key[], int n ){
	bool result[3] = {false,false,false};//开关量
	int start, end;
	start = 0;
	end = 0;
	int min = len;
	//find first good sequence
	for ( int i = 0; i<len; i++ ){
		result[0] = result[1] = result[2] = 0;
		start = i;
		end = i;
		while( !(result[0]&&result[1]&&result[2]) && end<len ){
			for( int i = 0; i<n; i++ ){
				if( strcmp(article[end], key[i])==0 ){
					result[i] = true;
				}
			}
			end++;//继续查找下一个字符串
		}
		if( i==0 && !(result[0]&&result[1]&&result[2]) )
			return -1;
		--end;
		if( result[0]&&result[1]&&result[2] ){
			if( (end-start+1)<min ){
				min = end-start+1;
			}
		}
	}
	return min;//找不到
}
/*
遍历所有可能的字符串
时间复杂度：len＊len＊len＊n
*/
int summary0( char *article[], int len, char* key[], int n ){
	int min = len;
	int start ;
	int bitn = 7;
	for( int l = n; l<=len; l++ ){//所有长度
		//所有字符串
		for( int j = 0; j<len-l; j++){
			bool result[]={0,0,0};//bit K, for example K=3, then result is\
					right if 111(b)
			for( int i=j; i<j+l; i++ ){
				//判断当前字符串是否包含所有关键字
				for( int m=0; m<n; m++ ){//和每一个关键词比较
					if( strcmp( key[m], article[i] )==0 ){
						result[m] = 1;
					}
				}
				if( result[0]==1 && result[1]==1 && result[2]==1 ){//find all
					if( (i-j)<min ){//set min
						min = i-j ;
						start = j;
					}
				}
			}
		}
	}
	cout<<"summary:"<<endl;
	for( int i = start; i<start+min; i++ ){
		cout<<article[i]<<" ";
	}
	cout<<endl;
	return min;
}

