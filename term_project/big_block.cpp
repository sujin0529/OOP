#include "big_block.h"

big_block::~big_block(){
    std::cout << "소멸" << std::endl;
}


bool big_block::can_left(){
    int check = 0; // left 못하는 블록 유무
    min_x = 5;
    auto it = v.begin();
    for(auto iterator = v.begin(); iterator != v.end(); iterator++){
        if((*iterator)->get_x() < min_x){
            min_x = (*iterator)->get_x();
        }
    }
    for(;it != v.end(); it++){
        if((*it)->get_x()==min_x){
            break;
        }
    }
    if(!(*it)->can_left()){
        check++;
    }
    return !check;
}


bool big_block::can_right(){
    int check = 0; // left 못하는 블록 유무
    auto it = v.begin();
    max_x = 0;
    for(auto iterator = v.begin(); iterator != v.end(); iterator++){
        if((*iterator)->get_x() > max_x){
            max_x = (*iterator)->get_x();
        }
    }
    for(;it != v.end(); it++){
        if((*it)->get_x()==max_x){
            break;
        }
    }
    if(!(*it)->can_right()){
        check++;
    }
    return !check;
}


bool big_block::can_down(){
    int check = 0; // left 못하는 블록 유무
    auto it = v.begin();
    max_x = 0;
    min_x = 5;
    for(auto iterator = v.begin(); iterator != v.end(); iterator++){
        if((*iterator)->get_x() > max_x){
            max_x = (*iterator)->get_x();
        }
        else if((*iterator)->get_x() < min_x){
            min_x = (*iterator)->get_x();
        }
    }
    for(;it != v.end(); it++){
        if((*it)->get_x()==max_x){
            break;
        }
    }
    if(!(*it)->can_down()){
        check++;
    }
    for(;it != v.end(); it++){
        if((*it)->get_x()==min_x){
            break;
        }
    }
    if(!(*it)->can_down()){
        check++;
    }
    return !check;
}

void big_block::left(){
    if(this->can_left()){
        for(auto iterator = v.begin(); iterator != v.end(); iterator++){
            (*iterator)->left();
        }
    }
}

void big_block::right(){
    if(this->can_right()){
        for(auto iterator = v.end()-1; iterator != v.begin(); iterator--){
            (*iterator)->right();
        }
        auto iterator = v.begin();
       (*iterator)->right();
    }
}

void big_block::down(){
    if(this->can_down()){
        for(auto iterator = v.begin(); iterator != v.end(); iterator++){
            (*iterator)->down();
        }
    }
}

void big_block::down_all(){
    while(this->can_down()){
        for(auto iterator = v.begin(); iterator != v.end(); iterator++){
            (*iterator)->down();
        }
    }
    for(auto iterator = v.begin(); iterator != v.end(); iterator++){
        while((*iterator)->can_down()){
            // 더 내려갈 수 있는 블럭이 있다면
            (*iterator)->down();
        }
    }
}

std::vector<block*> big_block::get_block(){
    return this->v;
}
