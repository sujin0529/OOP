#include "block.h"
#include "array_2d.h"

block::block(int color){
	this->color = color;
}

int block::get_color(){
	return this->color;
}

void block::set_color(int color){
	this->color = color;
}

int block::get_x(){
	return x;
}

int block::get_y(){
	return y;
}

void block::set_location(int x, int y){
	this->x = x;
	this->y = y;
}

bool block::can_left(){
	// 블럭이 왼쪽으로 이동할 수 있으면 true
	if(this->get_x()>0){
		if((array_2d::block_array[(this->get_y())][this->get_x()-1])->get_color()==0){
			return true;
		}	
	}
	return false;
}

bool block::can_right(){
	// 블럭이 오른쪽으로 이동할 수 있으면 true
	if(this->get_x()<4){
		if((array_2d::block_array[(this->get_y())][this->get_x()+1])->get_color() == 0){
			return true;
		}	
	}
	return false;
}

bool block::can_down(){
	// 블럭이 아래로 이동할 수 있으면 true
	if((this->get_y())<11){
		if((array_2d::block_array[this->get_y()+1][(this->get_x())])->get_color() == 0){
			return true;
		}
	}
	return false;
}

void block::right(){
	// 오른쪽으로 이동

	array_2d::block_array[this->get_y()][this->get_x()+1]
	= array_2d::block_array[this->get_y()][this->get_x()];
	// 오른쪽 위치에 값을 넣고
	
	array_2d::block_array[this->get_y()][this->get_x()] = new block(0);
	// 원래 위치의 값 없애기
	this->set_location(get_x()+1, get_y());
}

void block::left(){
	// 왼쪽으로 이동
	if(this->can_left()){
		array_2d::block_array[this->get_y()][this->get_x()-1]
	= array_2d::block_array[this->get_y()][this->get_x()];
	// 왼쪽 위치에 값을 넣고
	
	array_2d::block_array[this->get_y()][this->get_x()] = new block(0);
	// 원래 위치의 값 없애기
	this->set_location(get_x()-1, get_y());
	}

}

void block::down(){
	// 아래로 이동
	array_2d::block_array[this->get_y()+1][this->get_x()]
	= array_2d::block_array[this->get_y()][this->get_x()];
	// 아래 위치에 값을 넣고
	array_2d::block_array[this->get_y()][this->get_x()] = new block(0);
	// 원래 위치의 값 없애기
	this->set_location(get_x(), get_y()+1);
}

void block::down_all(){
	// 최대한으로 아래로 이동
	while(this->can_down()){
		this->down();
		// down이 가능한 동안에 계속 down
	}
}

