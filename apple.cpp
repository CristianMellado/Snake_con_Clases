#include "apple.h"

Apple::Apple(int size, string img):Printer(size, img){
	mostrar = true;
	
	apple = new int[2];
	apple[0] = -1;
	apple[1] = -1;
}

Apple::~Apple(){
	delete []apple;
}

void Apple::appear_apple(Obs *obs){
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

int *Apple::get_apple(){
	return apple;
}

void Apple::ate_apple(){
	mostrar = true;
}