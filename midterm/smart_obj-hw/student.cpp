#include "student.h"

student::student(){
	this->name = nullptr;
	this->student_id = -1;
}

student::student(char* name) {
	this->name = name;
	this->student_id = -1;
}

student::student(int student_id) {
	this->name = nullptr;
	this->student_id = student_id;
}

student::student(char *name, int student_id) {
	this->name = name;
	this->student_id = student_id;
}

int student::get_student_id() {
    
    return student_id;
}

int student::get_id() {
    
    return 1;
}
