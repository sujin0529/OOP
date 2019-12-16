#ifndef FOLD_BLOCK
#define FOLD_BLOCK
#include "big_block.h"
#include "array_2d.h"

class fold_block : public big_block
{
	public :
		fold_block();
		void rotate();
		bool can_down();
};

#endif
