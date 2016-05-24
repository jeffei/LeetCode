/*
	引用计数指针资源管理
*/

#include <iostream>
using namespace std;

template <class T>
class SmartPtr{
private:
	T *_data;
	int* refCnt;
	void clear(){
		delete _data;
		delete refCnt;
		_data=0;
		refCnt=0;
	}
public:
	SmartPtr(T*);
	SmartPtr(const SmartPtr&);
	SmartPtr& operator=(const SmartPtr&);
	~SmartPtr();
	T& operator*() const;
	T* operator->() const;
	bool operator!() const;
};
template <class T>
SmartPtr<T>::SmartPtr(T* realPtr){
	this->_data=realPtr;
	this->refCnt=new int(1);
}
template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& rhs){
	this->_data=rhs._data;
	this->refCnt=rhs.refCnt;
	++*refCnt;
}

template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& rhs){
	if(this==&rhs) return *this;
	if(--*this->refCnt==0){
		clear();
		cout<<"operator clear"<<endl;
	}
	this->_data=rhs._data;
	this->refCnt=rhs.refCnt;
	(*this->refCnt)++;
}

template <class T>
SmartPtr<T>::~SmartPtr(){
	if(--*refCnt==0){
		clear();
		cout<<"dtor clear"<<endl;
	}
}

template<class T>
T* SmartPtr<T>::operator->()const{
	return _data;
}
template<class T>
T& SmartPtr<T>::operator*()const{
	return *_data;
}

template <class T>
bool SmartPtr<T>::operator!()const{
	return _data==NULL;
}