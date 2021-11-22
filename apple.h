#pragma once
#include <time.h>
#include "obstacle.h"
#include "printer.h"

class Obs;

class Apple : public Printer{  // hereda los metodos y atributos de la clase Printer
	public:
  	    int *apple;

        Apple(int, string);
        ~Apple();
		bool same_pos(int,int);
		void ate_apple(Obs *);
};