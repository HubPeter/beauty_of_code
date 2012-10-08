#include"string.h"
#include<iostream>
using namespace std;
String::String(const char * str /*= NULL*/){
	if(str==NULL){
		m_data = new char[1];
		m_data[0] = '\0';
	}else{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
}
String::String(const String& another){
	m_data = new char[strlen(another.m_data)+1];
	strcpy(m_data, another.m_data);
}
String& String::operator = (const String& another){
	if(this==&another){
		return *this;
	}
	delete []m_data;
	m_data = new char[strlen(another.m_data)+1];
	strcpy(m_data, another.m_data);
	return *this;
}
char& operator[](const int index){
	if(index>=0&&index<strlen(m_data)){
		return &m_data[index];
	}
	return NULL;
}
char* String::GetString(){
	return this->m_data;
}
String::~String(){
	delete []m_data; 
}
int main(void){
	String* s = new String("Hello world");
	cout<<s->GetString()<<endl;
	return 0;
}
