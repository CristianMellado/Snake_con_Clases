#pragma once
#include "snake.h"
#include "printer.h"

class Snake;

class Obs : public Printer{
    public:
        int **obs, max_obs, n_obs;
        Obs(int , string);
        ~Obs();

        bool same_pos(int,int);
		bool collide_obs(int,int);
		void collide_snakes(Snake *, Snake *);
        void crash(int,int);
        int get_n_obs();
};