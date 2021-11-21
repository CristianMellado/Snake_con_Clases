#pragma once
#include <time.h>
#include <conio.h>
#include "obstacle.h"
#include "printer.cpp"

class Obs;

class Snake : public Printer{
    public:
        int x, y, len, **snake, t, limit_t;
        char *keys, state;
        Snake(int , string, int);
        ~Snake();

		void snake_controller(Obs *, char );
		void change_course();
		bool same_pos(int, int);
		void crash_snake();
		int get_len();
		void add_tail();
};



