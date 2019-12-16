#include "array_2d.h"

#define RESET "\033[0m"
#define GRAY "\033[8m"
#define BLACK "\033[30m"			  /* Black */
#define RED "\033[31m"				  /* Red */
#define GREEN "\033[32m"			  /* Green */
#define BLUE "\033[34m"				  /* Blue */
#define WHITE "\033[37m"			  /* White */

block *array_2d::block_array[12][5];
int array_2d::score = 0;

array_2d::array_2d()
{
	for (int height = 0; height < 12; height++)
	{
		for (int width = 0; width < 5; width++)
		{
			block_array[height][width] = new block(0);
		}
	}
	// 초기화 단계
}

void array_2d::insert(std::vector<block *> v)
{
	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
	{
		insert((*iterator)->get_x(), (*iterator)->get_y(), (*iterator));
	}

	// 파라미터로 받은 블럭을 배열에 삽입
}

void array_2d::insert(int x, int y, block *b)
{
	// 배열 x,y 위치에 블럭 b 삽입
	block_array[y][x] = b;
}

block *array_2d::get_block(int x, int y)
{
	return block_array[y][x];
}

void array_2d::print()
{
	std::cout << "score : " << array_2d::get_score() << std::endl;
	std::cout << "" << std::endl;
	for (int height = 0; height < 12; height++)
	{
		for (int width = 0; width < 5; width++)
		{
			block *b = get_block(width, height);
			switch (b->get_color())
			{
			case 0:
				std::cout << '.';
				break;
			case 1:
				std::cout << WHITE << 1; 
				break;
			case 2:
				std::cout << RED << 2;
				break;
			case 3:
				std::cout << BLUE << 3;
				break;
			case 4:
				std::cout << GREEN << 4;
				break;
			}
			std::cout << RESET << "  ";
		}
		std::cout << "" << std::endl;
	}
}

void array_2d::explosion()
{
	// 터질 수 있는가
	std::queue<block *> block_queue;
	std::vector<block *> visit_block; // 방문한 블록들 담기

	int block_color = 0;

	for (int y = 11; y >= 0; y--)
	{
		for (int x = 0; x < 5; x++)
		{
			while (!block_queue.empty())
			{
				block_queue.pop();
			}
			visit_block.clear();
			if (array_2d::block_array[y][x]->get_color() != 0 &&
				array_2d::block_array[y][x]->get_color() != 1)
			// 없지도 않고, gray도 아님
			{
				block_queue.push(array_2d::block_array[y][x]);
				block_color = block_queue.front()->get_color();
			}
			else
			{
				continue;
			}

			while (!block_queue.empty())
			{
				visit_block.push_back(block_queue.front());
				int block_x = block_queue.front()->get_x();
				int block_y = block_queue.front()->get_y();
				block_queue.pop();
				if (block_x < 4 && array_2d::block_array[block_y][block_x + 1]->get_color() == block_color)
				{
					int check = 0;
					for (auto it = visit_block.begin(); it != visit_block.end(); it++)
					{
						if (((*it)->get_x() == block_x + 1) && ((*it)->get_y() == block_y))
						{
							check = 1;
						}
					}
					if (!check)
					{
						block_queue.push(array_2d::block_array[block_y][block_x + 1]);
					}
				}
				if (block_y > 0 && array_2d::block_array[block_y - 1][block_x]->get_color() == block_color)
				{
					int check = 0;
					for (auto it = visit_block.begin(); it != visit_block.end(); it++)
					{
						if (((*it)->get_x() == block_x) && ((*it)->get_y() == block_y - 1))
						{
							check = 1;
						}
					}
					if (!check)
					{
						block_queue.push(array_2d::block_array[block_y - 1][block_x]);
					}
				}
				if (block_y < 11 && array_2d::block_array[block_y + 1][block_x]->get_color() == block_color)
				{
					int check = 0;
					for (auto it = visit_block.begin(); it != visit_block.end(); it++)
					{
						if (((*it)->get_x() == block_x) && ((*it)->get_y() == block_y + 1))
						{
							check = 1;
						}
					}
					if (!check)
					{
						block_queue.push(array_2d::block_array[block_y + 1][block_x]);
					}
				}
				if (block_x > 0 && array_2d::block_array[block_y][block_x - 1]->get_color() == block_color)
				{
					int check = 0;
					for (auto it = visit_block.begin(); it != visit_block.end(); it++)
					{
						if (((*it)->get_x() == block_x - 1) && ((*it)->get_y() == block_y))
						{
							check = 1;
						}
					}
					if (!check)
					{
						block_queue.push(array_2d::block_array[block_y][block_x - 1]);
					}
				}
			}
			if (visit_block.size() >= 4)
			{
				score++;
				int visit_size = visit_block.size();
				while (visit_size > 0)
				{
					block *gray_check = visit_block.front();
					visit_block.erase(visit_block.begin());
					visit_size--;
					int _x = gray_check->get_x();
					int _y = gray_check->get_y();
					array_2d::block_array[_y][_x] = new block(0);
					if ((_y > 0) && ((array_2d::block_array[_y - 1][_x]->get_color()) == 1))
					{
						// 위
						visit_block.push_back(array_2d::block_array[_y - 1][_x]);
					}
					if ((_x > 0) && ((array_2d::block_array[_y][_x - 1]->get_color()) == 1))
					{
						// 왼쪽
						visit_block.push_back(array_2d::block_array[_y][_x - 1]);
					}
					if ((_x < 4) && ((array_2d::block_array[_y][_x + 1]->get_color()) == 1))
					{
						// 오른쪽
						visit_block.push_back(array_2d::block_array[_y][_x + 1]);
					}
					if ((_y < 11) && ((array_2d::block_array[_y + 1][_x]->get_color()) == 1))
					{
						// 아래
						visit_block.push_back(array_2d::block_array[_y + 1][_x]);
					}
				}
				visit_size = visit_block.size();
				while (visit_size > 0)
				{
					block *del_block = visit_block.front();
					visit_size--;
					visit_block.erase(visit_block.begin());
					int _x = del_block->get_x();
					int _y = del_block->get_y();
					array_2d::block_array[_y][_x] = new block(0);
				}
				for (int down_y = 11; down_y >= 0; down_y--)
				{
					for (int down_x = 0; down_x < 5; down_x++)
					{
						if (array_2d::block_array[down_y][down_x]->get_color() != 0)
						{
							array_2d::block_array[down_y][down_x]->down_all();
						}
					}
				}
				x = -1;
				y = 11;
				// 좌표 초기화
			}
		}
	}
}

int array_2d::get_score()
{
	// 점수 반환
	return score;
}
