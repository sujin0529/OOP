#include "tree_block.h"

tree_block::tree_block()
{
	srand((unsigned int)time(0));
	block *b1 = new block(std::rand() % 4 + 1);
	b1->set_location(2, 0);
	block *b2 = new block(std::rand() % 4 + 1);
	b2->set_location(2, 1);
	block *b3 = new block(std::rand() % 4 + 1);
	b3->set_location(2, 2);
	v.push_back(b3);
	v.push_back(b2);
	v.push_back(b1);
}

bool tree_block::can_down()
{
	int check = 0;
	auto iterator = v.begin();
	if (!((*iterator)->can_down()))
	{
		check++;
	}

	return !check;
}


void tree_block::rotate()
{

}
