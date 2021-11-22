/**
Snake2.0


Departamento de Ciencia de la Computación
Prof: D.Sc. Manuel Eduardo Loaiza Fernández

Alumnos:
 - Cristian Mellado Baca
 - Marcelo Torres Acuña
 - Alexander Carpio Mamani
*/



#pragma once
#include "snake.h"
#include "printer.h"

class Snake;  // prototipado de clase Snake

class Obs : public Printer{  // hereda metodos y atributos de clase Printer
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
