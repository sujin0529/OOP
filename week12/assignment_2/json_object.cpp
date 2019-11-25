#include "json_object.h"
#include <string>
#include "json_dict.h"
#include "json_list.h"
#include "./data/String.h"
#include "./data/Integer.h"

int json_object::_index=0;
json_object* json_object::parse(const char* c, int length){
	json_object* obj = nullptr; // 반환할 애
	for(;_index < length;_index++){
		int i = 0;
		if (*(c + _index) == '{')
		{
			int count = 1;
			bool flag = true;
			int start_index = _index + i;
			i++; // { 지난 곳부터
			
			while(flag){
				if(*(c+_index+i)=='{') count++;
				else if(*(c+_index + i)=='}') count--;
				if(count==0){
					break;
				}
				i++;
			}
			int end_index = _index + i;
			_index = start_index;
			obj = json_dict::parse(c, end_index-start_index+1);
		}
		else if (*(c + _index) == '[')
		{
			int count = 1;
			int start_index = _index + i;
			bool flag = true;
			i++; // [ 지난 곳부터
			
			while(flag){
				
				if(*(c+_index+i)=='[') count++;
				else if(*(c+_index + i)==']') count--;
				if(count==0){
					break;
				}

				i++;
			}
			int end_index = _index + i;
			_index = start_index;
			obj = json_list::parse(c, end_index-start_index+1);
			

		}
		if (*(c + _index) == '\'')
		{
			int start_index = _index + i;
			i++; // ' 지난 곳부터
			while(*(c+_index + i) != '\'') i++;
			int end_index = _index + i;
			obj  = String::parse(c, end_index-start_index+1,'\'');
			

		}
		if (*(c + _index) == '\"')
		{
			int start_index = _index + i;
			i++; // " 지난 곳부터
			while(*(c+_index + i) != '\"') i++;
			int end_index = _index + i;
			obj  = String::parse(c, end_index-start_index+1, '\"');
			

		}
		if ('0'<=*(c + _index) && *(c+_index)<= '9')
		{
			int start_index = _index + i;
			while(*(c+_index + i)<'0' || *(c+_index+i)>'9') i++;
			int end_index = _index + i;
			obj  = Integer::parse(c, end_index-start_index+1);
		}

		
	}
	return obj;
}

json_object* json_object::parse(const std::string& s){
	_index = 0;
	json_object* obj = parse(s.c_str(), s.length());
	return obj;

}

