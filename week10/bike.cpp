#include "bike.h"

bike::bike():vehicle(){
	bike_name = nullptr;
}

bike::bike(int new_wheel_number, int new_max_speed):vehicle(new_wheel_number, new_max_speed){
	bike_name = nullptr;
}

bike::bike(int new_wheel_number, int new_max_speed, char* new_bike_name):vehicle(new_wheel_number, new_max_speed){
	bike_name = new_bike_name;
}

bike::bike(int new_wheel_number, int new_max_speed, char* new_bike_name, int new_bike_number):vehicle(new_wheel_number, new_max_speed){
	bike_name = new_bike_name;
	bike_number = new_bike_number;
}

bike::bike(int new_wheel_number, int new_max_speed, char* new_bike_name, int new_bike_number, bool new_has_name):vehicle(new_wheel_number, new_max_speed, new_has_name){
	bike_name = new_bike_name;
	bike_number = new_bike_number;
}

int bike::get_bike_number(){
	return bike_number;
}
char* bike::get_bike_name(){
	return bike_name;
}
const char* bike::get_class_name(){
	return "bike";
}
void bike::set_bike_name(char* new_bike_name){
	bike_name = new_bike_name;
}
void bike::set_bike_number(int new_bike_number){
	bike_number = new_bike_number;
}
