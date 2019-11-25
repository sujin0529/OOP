#include "json_dict.h"
#include "./data/String.h"
#include "json_list.h"
#include "./data/Integer.h"
#include "json_object.h"

void json_dict::put(json_object *key, json_object *val)
{
	int index = find(key);
	int i=0;
	auto iterator = v.begin();
	if(index != -1){
		while(i!=index){
			i++;
			iterator++;
		}
		*iterator = std::make_pair(key, val);
	}
	else{
		v.push_back(std::make_pair(key, val));
	}
	
}

int json_dict::find(json_object *key)
{
	int index = 0;
	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
	{
		if(iterator->first->type() == key->type()){

			if(key->type() == STRING){
				if((((String*)iterator->first)->val()) == ((String*)key)->val()){
					// c++ 한정으로 == 연산자로 두 문자열 동일한지 확인 가능
					return index;
				}
			}
			else if(key->type() == INT){
				if(((Integer*)iterator->first)->val() == ((Integer*)key)->val()){
					return index;
				}
			}
		}
		index++;
	}
	return -1;
}

json_dict::json_dict()
{
	
}

json_object *json_dict::parse(const char *c, int length)
{
	json_dict *dict = new json_dict();
	int i = 1; // 길이가 오면 { 부터 시작일 것
	json_object *key= nullptr;
	json_object *value = nullptr;
	for (; _index + i < _index + length; i++)
	{
		if(*(c+_index+i) == ',' || *(c+_index+i)==' '){
			if(*(c+_index+i)== ','){
				key= nullptr;
				value = nullptr;
			}
			continue;
		}
		if (*(c + _index + i) == '\'')
		{
			int start_index = _index + i;
			i++; // ' 지난 곳부터
			while (*(c + _index + i) != '\'')
				i++;
			int end_index = _index + i;
			_index = start_index;
			value = String::parse(c, end_index - start_index + 1, '\'');
			i = 0; // offset 다시 맞춰줘야 함.
			while (*(c + _index + i) == ' ')
				i++;
			// 공백 무시

			if (*(c + _index + i) == ':')
			{
				key = value;
				value = nullptr;
				// value가 nullptr가 아닐 때 넣을 수 있도록 하기 위함.
				continue;
			}
		}
		else if (*(c + _index + i) == '\"')
		{
			int start_index = _index + i;
			i++; // " 지난 곳부터
			while (*(c + _index + i) != '\"')
				i++;
			int end_index = _index + i;
			_index = start_index;
			value = String::parse(c, end_index - start_index + 1, '\"');
			i = 0; // offset 다시 맞춰줘야 함.
			while (*(c + _index + i) == ' ')
				i++;

			if (*(c + _index + i) == ':')
			{
				key = value;
				value = nullptr;
				// value가 nullptr가 아닐 때 넣을 수 있도록 하기 위함.
				continue;
			}
		}

		else if ('0' <= *(c + _index + i) && *(c + _index + i) <= '9')
		{
			int start_index = _index + i;
			while ('0' <= *(c + _index + i) && *(c + _index + i)<='9')
				i++;
			int end_index = _index + i;
			_index = start_index;
			value = Integer::parse(c, end_index - start_index);
		
			i = 0;
			while (*(c+_index+i)==' ')
				i++;
			
			if (*(c + _index + i) == ':')
			{
				key = value;
				value = nullptr;
				continue;
				// value가 nullptr가 아닐 때 넣을 수 있도록 하기 위함.
			}
		}

		else if (*(c + _index + i) == '[')
		{
			// int start_index = _index + i;
			// i++; // [ 지난 곳부터
			// while (*(c + _index + i) != ']')
			// 	i++;
			int count =1;
			bool flag = true;
			int start_index = _index + i;
			i++; // { 지난 곳부터
			// while (*(c + _index + i) != '}')
			// 	i++;
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
			value = json_list::parse(c, end_index - start_index + 1);
			_index = end_index;
			i=0;
		}
		
		else if (*(c + _index + i) == '{')
		{
			int count =1;
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
			value = json_dict::parse(c, end_index - start_index + 1);
			_index = end_index;
			i=0;
		}

		if (value != nullptr && key != nullptr)
		{
			dict->put(key, value);

			key = nullptr;
			value = nullptr;
		}
		
		if(*(c+_index+i)=='}'){
			_index++;
			return dict;
		}
		
	}
	return dict;
}

json_object *json_dict::operator[](json_object *key) const
{

	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
	{
		if (iterator->first == key)
		{
			return iterator->second;
		}
	}
	return nullptr;
}
json_object *json_dict::operator[](const std::string &key) const
{

	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
	{
		
		if ((iterator->first)->type() != STRING)
		{
			// string 타입에 맞지 않으면 어차피 틀림
			continue;
		}
		if (((String *)(iterator->first))->val() == key)
		{
			return iterator->second;
		}
	}
	return nullptr;
}
json_object *json_dict::operator[](int key) const
{
	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
	{
		if ((iterator->first)->type() != INT)
		{
			// integer 타입에 맞지 않으면 어차피 틀림
			continue;
		}
		if (((Integer *)(iterator->first))->val() == key)
		{
			return iterator->second;
		}
	}
	return nullptr;
}

json_object::_type json_dict::type()
{
	return DICT;
}

std::string json_dict::to_string()
{
	std::string str;
	str += "{";
	auto it = v.end();
	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
	{
		if ((iterator->first)->type() == STRING)
		{
			String *s = (String *)(iterator->first);
			str += s->to_string();
			str += ":";
		}
		else if ((iterator->first)->type() == INT)
		{
			Integer *in = (Integer *)(iterator->first);
			str += in->to_string();
			str += ":";
		}
		else{
			str += iterator->first->to_string();
			str += ":";
		}

		if (iterator->second->type() == STRING)
		{
			String *s = (String *)(iterator->second);
			str += s->to_string();
		}

		else if (iterator->second->type() == INT)
		{
			Integer *in = (Integer *)(iterator->second);
			str += in->to_string();
		}
		else{
			str += iterator->second->to_string();
		}
		if(iterator != (it-1))
			str += ", ";
	}
	str += "}";
	return str;
}
