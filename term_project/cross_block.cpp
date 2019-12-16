#include "cross_block.h"


cross_block::cross_block()
{
    srand((unsigned int)time(0));
    block *b1 = new block(std::rand() % 4 + 1);
    b1->set_location(2, 0); // 위
    block *b2 = new block(std::rand() % 4 + 1);
    b2->set_location(2, 1); // 중앙
    block *b3 = new block(std::rand() % 4 + 1);
    b3->set_location(2, 2); // 아래
    block *b4 = new block(std::rand() % 4 + 1);
    b4->set_location(1, 1); // 왼쪽
    block *b5 = new block(std::rand() % 4 + 1);
    b5->set_location(3, 1); // 오른쪽
    v.push_back(b4);
    v.push_back(b3);
    v.push_back(b2);
    v.push_back(b5);
    v.push_back(b1);
}

bool cross_block::can_down()
{
    int check = 0; // down 못하는 블럭 유무
    auto iterator = v.begin();
    if (!((*iterator)->can_down()))
    {
        check++;
    }
    iterator++;
    if (!((*iterator)->can_down()))
    {
        check++;
    }
    iterator += 2;
    if (!((*iterator)->can_down()))
    {
        check++;
    }


    return !check;
}

void cross_block::rotate()
{
}
