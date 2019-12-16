#include <iostream>
#include "array_2d.h"
#include "block.h"
#include "big_block.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"
#include <ctime>
#include <stdlib.h>
#include <termio.h>

int getch(void){
    int ch;
    struct termios buf, save;
    tcgetattr(0,&save);
    buf = save;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}
// getch 함수를 사용하기 위한 코드

int main()
{
	array_2d *x = new array_2d();
	srand((unsigned int)time(0));
	big_block *block = nullptr;
	std::cout << "Game Start ?" << std::endl;
	std::cout << "start : 1" << std::endl;
	char start_input = std::getchar();
	std::getchar(); // 줄바꿈 버퍼 비우기
	if(start_input != '1'){
		std::cout << "Game Over" << std::endl;
		exit(0);
	}
	// 게임 시작을 하지 않겠다고 한다면 그냥 종료시킴

	while (1)
	{
		int shape = (std::rand() % 3) + 1;
		block = nullptr;
		if (shape == 1)
		{
			block = new fold_block();
		}
		else if (shape == 2)
		{
			block = new tree_block();
		}
		else
		{
			block = new cross_block();
		}
		// 모양 정하기
		
		x->insert(block->get_block());
		system("clear");
		x->print();
		if(!(block->can_down())){
			break;
		}
		while (block->can_down())
		{
			char input = getch();
			if (input == 'a')
			{
				block->left();
			}
			else if (input == 'd')
			{
				block->right();
			}
			else if (input == 's')
			{
				block->down();
			}
			else if (input == 'x')
			{
				block->down_all();
			}
			else{
				// 잘못된 출력 디버깅용.
				std::cout << "wrong" << std::endl;
			}
			system("clear");
			x->print();
		}
		block->down_all();
		x->explosion(); // 블록 터치기
		x->print(); // 출력
		
	}
	std::cout << "" << std::endl;
	std::cout << "Game Over" << std::endl;
}
