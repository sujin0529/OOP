#ifndef ARRAY
#define ARRAY

#include "block.h"
#include <iostream>
#include <vector>
#include <queue>
#include <set>

class array_2d
{

	public :
		array_2d();
		// 생성자

		static block * block_array[12][5];
		static int score;
		// 변수

		static void insert(std::vector<block *> v);
		static void insert(int x, int y, block* b);
		static block* get_block(int x, int y);
		static void print();
		
		static void explosion();
		static int get_score();

};

#endif
