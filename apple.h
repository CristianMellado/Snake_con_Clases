/*
Snake2.0


Departamento de Ciencia de la Computación
Prof: D.Sc. Manuel Eduardo Loaiza Fernández

Alumnos:
 - Cristian Mellado Baca
 - Marcelo Torres Acuña
 - Alexander Carpio Mamani
*/




#pragma once
#include <time.h>
#include "obstacle.h"
#include "printer.h"

class Obs;

class Apple : public Printer{  // hereda los metodos y atributos de la clase Printer
	public:
  	    int *apple;
        bool mostrar;

        Apple(int, string);
        ~Apple();
	    void appear_apple(Obs *);
		bool same_pos(int,int);
		void ate_apple();
};
