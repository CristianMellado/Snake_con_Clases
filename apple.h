#pragma once
#include <time.h>
#include "obstacle.h"
#include "printer.h"

class Obs;

class Apple : public Printer{
	public:
  	    int *apple;
        bool mostrar;

        Apple(int, string);
        ~Apple();
	    void appear_apple(Obs *);
		bool same_pos(int,int);
		int *get_apple();
		void ate_apple();
};