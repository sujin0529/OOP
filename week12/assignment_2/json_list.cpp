#include "json_list.h"
#include "json_object.h"
#include "./data/String.h"
#include "./data/Integer.h"
#include "json_dict.h"

json_list::json_list()
{
}

json_object *json_list::parse(const char *c, int length)
{
	json_list *list = new json_list();
	int i = 1; // [부터 시작할 것이므로
	json_object *value = nullptr;
	//std::cout << *(c+_index) << "  "<<_index << std::endl;

	for (; _index + i < _index + length - 1; i++)
	{

		if (*(c + _index + i) == ',')
		{
			//i--;
			continue;
			//break;
		}
		else if (*(c + _index + i) == '\'')
		{
			int start_index = _index + i;
			i++; // ' 지난 곳부터
			while (*(c + _index + i) != '\'')
				i++;
			int end_index = _index + i;
			_index = start_index;
			value = String::parse(c, end_index - start_index + 1, '\'');
			i = 0;
			list->v.push_back(value);
		}
		else if (*(c + _index + i) == '\"')
		{
			int start_index = _index + i;
			i++; // ' 지난 곳부터
			while (*(c + _index + i) != '\"')
				i++;
			int end_index = _index + i;
			_index = start_index;
			value = String::parse(c, end_index - start_index + 1, '\'');
			i = 0;
			list->v.push_back(value);
		}
		else if ('0' <= *(c + _index + i) && *(c + _index + i) <= '9')
		{
			int start_index = _index + i;
			while ('0' <= *(c + _index + i) && *(c + _index + i) <= '9')
				i++;
			int end_index = _index + i - 1;
			_index = start_index;
			value = Integer::parse(c, end_index - start_index + 1);
			i = 0;
			list->v.push_back(value);
		}
		else if (*(c + _index + i) == '[')
		{	
			int count = 1;
			int start_index = _index + i;
			i++;
			bool flag = true;

			while (flag)
			{

				if (*(c + _index + i) == '[')
					count++;
				else if (*(c + _index + i) == ']')
					count--;
				if (count == 0)
				{
					i++;
					break;
				}

				i++;
			}
			int end_index = _index + i; // ]까지로
			_index = start_index;
		
			value = json_list::parse(c, end_index - start_index + 1);
			_index = end_index;
			i = 0;
			list->v.push_back(value);
			
		
		}

		else if (*(c + _index + i) == '{')
		{
			int count = 1;
			bool flag = true;
			int start_index = _index + i;
			i++; // { 지난 곳부터
			// while (*(c + _index + i) != '}')
			// 	i++;
			while (flag)
			{
				if (*(c + _index + i) == '{')
					count++;
				else if (*(c + _index + i) == '}')
					count--;
				if (count == 0)
				{
					break;
				}

				i++;
			}
			int end_index = _index + i;
			_index = start_index;
			value = json_dict::parse(c, end_index - start_index + 1);
			_index = end_index;
			i = 0;
			list->v.push_back(value);
		}

		if (*(c + _index + i) == ']')
		{
			_index++;
			return list;
		}
	}
	return list;
}

json_object *json_list::operator[](int key) const
{
	int i = 0;
	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
	{
		if (key == i)
		{
			return *iterator;
		}
		i++;
	}
	return nullptr;
}

json_object::_type json_list::type()
{
	return LIST;
}

std::string json_list::to_string()
{
	std::string str;
	str += "[";
	auto it = v.end();
	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
	{
		if ((*iterator)->type() == STRING)
		{
			String *s = (String *)*iterator;
			str += s->to_string();
		}
		else if ((*iterator)->type() == INT)
		{
			Integer *in = (Integer *)*iterator;
			str += in->to_string();
		}
		else
		{
			str += (*iterator)->to_string();
		}
		if (iterator != (it - 1))
		{
			str += ", ";
		}
	}
	str += "]";
	return str;
}
