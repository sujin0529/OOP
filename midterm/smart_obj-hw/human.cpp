//
// Created by 김혁진 on 2019/10/28.
//

#include "human.h"

human::human() {
	this->name = nullptr;
}

human::human(char name[]) {
    this->name = name;
}

char *human::get_name() {
    
	return name;
}

int human::get_id() {
   
    return 0;
}
