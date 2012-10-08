#include<stdio.h>
#include<string.h>
class String{
public:
	String(const char* str = NULL);
	String(const String& another);
	~String();
	String & operator = (const String& another);
	char& operator [] (const int index);
	char* GetString();
private:
	char* m_data;
};
