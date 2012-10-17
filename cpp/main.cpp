#include<iostream>
using namespace std;
class P{
public:
	P(int tn){
		n = tn;
	}
	int Get(){
		return n;
	}
	int p;
private:
	int n;
};
class C:public P{
public:
	C(int tc){
		c = tc;
	}
private:
	int c;
};
int main(void){
	P p(10, 20);
	C c(30);
	return 0;
}
