#ifndef BLOCK
#define BLOCK

class block
{
	private :

		int color;
		int x, y;

	public :

		block(int color);
		~block();
		int get_color();
		void set_color(int color);
		int get_x();
		int get_y();
		void set_location(int x, int y);
		bool can_left();
		bool can_right();
		bool can_down();
		void right();
		void left();
		void down();
		void down_all();
};

#endif
