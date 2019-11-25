#include "Integer.h"

Integer::Integer(int value){
	set_val(value);
}

int Integer::val(){
	return _val;
}

void Integer::set_val(const int& value){
	_val = value;
}

json_object* Integer::parse(const char * c, int length){
	std::string str;
	int i = 0;
	for(; _index+i < length+_index; i++){
		if('0'>*(c+_index+i) || '9'<*(c+_index+i)){
			throw std::runtime_error("정수가 아닙니다.");
		}
		str += *(c+_index+i);
	}
	_index += i;
	int result = atoi(str.c_str());
	return new Integer(result);
}

json_object::_type Integer::type(){
	return INT;
}

std::string Integer::to_string(){
	std::string str;
	str = std::to_string(_val);
	return str;

}
