#ifndef CROSS_BLOCK
#define CROSS_BLOCK

#include "big_block.h"
#include "array_2d.h"

class cross_block : public big_block
{
	public :
		cross_block();
		void rotate();
		bool can_down();
};

#endif
