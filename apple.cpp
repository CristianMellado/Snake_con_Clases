#include "apple.h"

Apple::Apple(int size, string img):Printer(size, img){ // constructor y envio de parametros para constructor padre
	mostrar = true;
	
	apple = new int[2]; // separamos memoria para el arreglo apple(x,y).
	apple[0] = -1;
	apple[1] = -1;
}

Apple::~Apple(){  // liberación de memoria para el arreglo apple (x,y).
	delete []apple;
}

void Apple::appear_apple(Obs *obs){ // recibe un puntero de tipo de dato clase Obs
	if(mostrar){
		mostrar=false;
		srand(time(NULL));
		do{
			apple[0] = rand()%(size);
			apple[1] = rand()%(size);
		}while(obs->same_pos(apple[1], apple[0]));
	}
}

bool Apple::same_pos(int x, int y){
	if (apple[0] == y && apple[1] == x) return true;
	return false;
}

void Apple::ate_apple(){
	mostrar = true;
}