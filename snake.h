#pragma once
#include <time.h>
#include <conio.h>
#include "obstacle.h"
#include "printer.cpp"

class Obs;  // prototipo de clase Obs

class Snake : public Printer{   // Herencia de Class Printer a class Snake
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



