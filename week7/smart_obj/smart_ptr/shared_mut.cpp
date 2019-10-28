//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

shared_mut::shared_mut(const shared_mut &shared) {
	_mgr =  shared._mgr;
	increase();
 }

shared_mut::~shared_mut() {
	release();	
}

int shared_mut::count(){
	if(_mgr==nullptr){
		return 0;
	}
	return (_mgr)->count;
}
void shared_mut::increase(){
	int x = (_mgr)->count;
	x++;
	(_mgr)->count = x;
}

void shared_mut::release(){
	if(_mgr!=nullptr){
		(_mgr)->count--;
		if((_mgr)->count==0){
			delete _mgr;
			_mgr = nullptr;
		}
		_mgr = new mgr();
	}
}

Object* shared_mut::get() const{
	if(_mgr == nullptr){
		return nullptr;
	}
	return (Object* )(_mgr->ptr);
}

shared_mut shared_mut::operator+(const shared_mut &shared){
	int x = (this->get())->get() + (shared.get())->get();
	shared_mut s(new Object(x));
	return s;
}

shared_mut shared_mut::operator-(const shared_mut &shared){
	int x = (this->get())->get() - (shared.get())->get();
	shared_mut s(new Object(x));
	return s;
}

shared_mut shared_mut::operator*(const shared_mut &shared){
	int x = (this->get())->get() * (shared.get())->get();
	shared_mut s(new Object(x));
	return s;
}

shared_mut shared_mut::operator/(const shared_mut &shared){
	int x = (this->get())->get() / (shared.get())->get();
	shared_mut s(new Object(x));
	return s;
}


Object* shared_mut:: operator->() {
    return _mgr->ptr;
}

shared_mut& shared_mut::operator=(const shared_mut &r){
	this->release();
	this->_mgr = r._mgr;
	this->increase();
	return *this;
}

} // end of namespace ptr
