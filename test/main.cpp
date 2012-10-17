#include<iostream>
using namespace std;
class OnlyOneObject{
public:
	 OnlyOneObject(){
		if(counter==0){
			counter++;
			cout<<"Success"<<endl;
		}else{
			cout<<"已经创建了一个实例"<<endl;
		}
	}
	~OnlyOneObject(){
		if(counter>0){
			counter=0;
			cout<<"销毁了实例"<<endl;
		}
	}
private:
	static int counter;
};
int OnlyOneObject::counter=0;
int main(void){
	class OnlyOneObject obj1;
	class OnlyOneObject obj2;
	obj1.~OnlyOneObject();
	class OnlyOneObject obj3;
	obj3.~OnlyOneObject();
	return 0;
}
