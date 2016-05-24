#ifndef  _MYSTRING_
#define  _MYSTRING_

#include <iostream>
#include <cstring>
using namespace std;
class String{
private:
	char *_data;
public:
	explicit String(const char* str=NULL);
	String(const String& rhs);
	String& operator=(const String& rhs);
	~String();
};
String::String(const char* str){
	cout<<"Normal ctor"<<endl;
	if(str){
		_data=new char[1];
		*_data='\0';
	}else{
		_data=new char[strlen(str)+1];
		strcpy(_data,str);
	}
}
String::String(const String& rhs){
	cout<<"Copy Ctor"<<endl;
	_data=new char[strlen(rhs._data)+1];
	strcpy(_data,rhs._data);
}
String& String::operator=(const String& rhs){
	cout<<"Operator="<<endl;
	if(&rhs == this) return *this;
	delete[] _data;
	_data=new char[strlen(rhs._data)+1];
	strcpy(_data,rhs._data);
	return *this;
}
String::~String(){
	delete[] _data;
	_data=0;
	cout<<"dtor"<<endl;
}
#endif