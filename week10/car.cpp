#include "car.h"

car::car():vehicle(){
	
}
car::car(int new_wheel_number, int new_max_speed):vehicle(new_wheel_number, new_max_speed){
	
}
car::car(int new_wheel_number, int new_max_speed, char* new_car_name):vehicle(new_wheel_number, new_max_speed){
	car_name = new_car_name;
}
car::car(int new_wheel_number, int new_max_speed, char* new_car_name, bool new_has_name):vehicle(new_wheel_number, new_max_speed, new_has_name){
	car_name = new_car_name;
}

char* car::get_car_name(){
	return car_name;
}
const char* car::get_class_name(){
	return "car";
}
void car::set_car_name(char* new_car_name){
	car_name = new_car_name;
}
