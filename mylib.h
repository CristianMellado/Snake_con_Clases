/****************************************************************
Juego: Snake.io Game - mylib.h
UCSP : CIENCIAS DE LA COMPUTACIÓN
Alumno:
 - Alexander Carpio Mamani
*****************************************************************/

#include <iostream>
#include <conio.h>

bool collide(int, int, int , int);
bool collide_obs(int, int, int , int );
void game();
void snake_game();
void refresh();
void ChangeCourse(char&, char [],int);
