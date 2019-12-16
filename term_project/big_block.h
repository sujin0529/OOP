#ifndef BIG_BLOCK
#define BIG_BLOCK

#include "block.h"
#include <iostream>
#include <vector>



class big_block{
	private :
		int min_x = 5, max_x = 0;

	protected :
		std::vector<block *>v;
		int max_y=0;

	public :
		~big_block();
		virtual void rotate() = 0;
		bool can_left();
		bool can_right();
		virtual bool can_down();
		void left();
		void right();
		void down();
		void down_all();
		std::vector<block*> get_block();
};

#endif
