//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"
#include <iostream>


namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
	release();   
}

void unique_immut::release(){
	if(_mgr != nullptr){
		delete _mgr;
		_mgr = nullptr;
	}
}

Object* unique_immut::get() const{
	if(_mgr==nullptr){
		return nullptr;
	}
	return (Object*)(_mgr->ptr);
}

unique_immut unique_immut::operator+(unique_immut &immut){
	int x = (this->get())->get() + (immut.get())->get();
	this->release();
	immut.release();
	unique_immut u(new Object(x));
	return u;
}

unique_immut unique_immut::operator-(unique_immut &immut){
	int x = (this->get())->get() - (immut.get()) -> get();
	this->release();
	immut.release();
	unique_immut u(new Object(x));
	return u;
}

unique_immut unique_immut::operator*(unique_immut &immut){
	int x = (this->get()) -> get() * (immut.get()) -> get();
	this->release();
	immut.release();
	unique_immut u(new Object(x));
	return u;
}

unique_immut unique_immut::operator/(unique_immut &immut){
	int x = (this->get()) -> get() / (immut.get()) -> get();
	this->release();
	immut.release();
	unique_immut u(new Object(x));
	return u;
}

unique_immut& unique_immut::operator=(unique_immut& r){
	if(this->_mgr == r._mgr){
		return *this;
	}
	this->release();
	unique_immut * p = &r;
	return *p;
}

Object* unique_immut::operator->(){
	return _mgr->ptr;
}

} // end of namespace ptr
