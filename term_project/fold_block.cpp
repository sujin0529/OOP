#include "fold_block.h"


fold_block::fold_block(){
    srand((unsigned int)time(0));
    block * b1 = new block(std::rand()%4+1);
    b1->set_location(2,0);
    block * b2 = new block(std::rand()%4+1);
    b2->set_location(2,1);
    block * b3 = new block(std::rand()%4+1);
    b3->set_location(1,1);
    v.push_back(b3);
    v.push_back(b2);
    v.push_back(b1);
}

bool fold_block::can_down(){
    int check = 0; // down 못하는 블럭 유무
    for(auto iterator = v.begin(); iterator != v.end()-1; iterator++){
        if(!((*iterator)->can_down())){
            check++;
        }
    }

    return !check;
}

void fold_block::rotate(){
    
}

