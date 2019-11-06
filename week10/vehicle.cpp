#include "vehicle.h"

vehicle::vehicle(){
	has_name = false;
	wheel_number = 0;
	max_speed = 0;
}

vehicle::vehicle(int new_wheel_number, int new_max_speed){
	has_name = true;
	wheel_number = new_wheel_number;
	max_speed = new_max_speed;
}
vehicle::vehicle(int new_wheel_number, int new_max_speed, bool new_has_name){
	has_name = new_has_name;
	wheel_number = new_wheel_number;
	max_speed = new_max_speed;
}

int vehicle::get_wheel_number(){
	return wheel_number;
}
void vehicle::set_wheel_number(int new_wheel_number){
	wheel_number = new_wheel_number;
}

int vehicle::get_max_speed(){
	return max_speed;
}
void vehicle::set_max_speed(int new_max_speed){
	max_speed = new_max_speed;
}

bool vehicle::get_has_name(){
	return has_name;
}
void vehicle::set_has_name(bool new_has_name){
	has_name = new_has_name;
}

const char* vehicle::get_class_name(){
	return "vehicle";
}


