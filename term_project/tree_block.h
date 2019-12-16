#ifndef TREE_BLOCK
#define TREE_BLOCK
#include "big_block.h"
#include "array_2d.h"

class tree_block : public big_block
{
	public :
		tree_block();
		void rotate();
		bool can_down();
};

#endif
