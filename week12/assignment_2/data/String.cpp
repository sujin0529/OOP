#include "String.h"
//#include <cstring>

String::String(const std::string& str){
	set_val(str);
}

std::string String::val(){
	return _val;
}
void String::set_val(const std::string& str){
	_val = str;
}

json_object* String::parse(const char* c, int length, char base){
	std::string str;
	int i=1; // offset 따옴표 다음부터 처리하기 위해 초기값 1
	for(;_index+i < _index+length-1; i++){
		// 길이 3, index 1
		// 어차피 마지막은 따옴표일거니까
		if(*(c+_index+i) == base){
			throw std::runtime_error("따옴표 처리가 잘못 되었습니다.");
		}
		str += *(c+_index+i);
	}
	i++; // 따옴표 다음 위치로 옮기기 위해서 i를 1 증가
	_index +=i; // _index 조정
	return new String(str);
}

json_object::_type String::type(){
	return STRING;
}

std::string String::to_string(){
	std::string str;
	char base ='\0';
	for(int i=0; i<(int)_val.length();i++){
		if(_val.at(i) == '\''){
			base = '"';
		}
		else if(_val.at(i)=='"'){
			base = '\'';
		}
		str+=_val.at(i);
		 
	}
	if(base == '\0'){
		base = '\'';
		str=base+str;
		str+="'";
	}
	else {
		str=base+str;
		str+=base;
	}
	return str;
}
