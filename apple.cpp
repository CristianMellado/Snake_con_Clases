/**
Snake2.0
Departamento de Ciencia de la Computación
Prof: D.Sc. Manuel Eduardo Loaiza Fernández
Alumnos:
 - Cristian Mellado Baca
 - Marcelo Torres Acuña
 - Alexander Carpio Mamani
*/

#include "apple.h"

Apple::Apple(int size, string img):Printer(size, img){ // constructor y envio de parametros para constructor padre
	apple = new int[2]; // separamos memoria para el arreglo apple(x,y).
	
	srand(time(NULL));
	apple[0] = rand()%(size);
	apple[1] = rand()%(size);
}

Apple::~Apple(){  // liberación de memoria para el arreglo apple (x,y).
	delete []apple;
}

bool Apple::same_pos(int x, int y){
	if (apple[0] == y && apple[1] == x) return true;
	return false;
}

void Apple::ate_apple(Obs *obs){
	srand(time(NULL));
	do{
		apple[0] = rand()%(size);
		apple[1] = rand()%(size);
	}while(obs->same_pos(apple[1], apple[0]));
}
