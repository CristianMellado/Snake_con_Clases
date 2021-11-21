#include "snake.h"

// los parametros de la clase padre serán enviados por el nombre de la clase padre.
Snake::Snake(int size, string img, int player):Printer(size, img){
	len = 1;
	limit_t = 10;
	t = 0;
	
    snake = new int *[size];  // separamos memoria para un arreglo de punteros int.
	for(int i=0; i<size; i++){    
		snake[i] = new int[2]; // separamos para cada elemento del puntero un array de longitud 2(x,y).
	}
	
    snake[0][0] = size/2;
    snake[0][1] = size/2;

	keys = new char[4];  // separamos memoria para un arreglo de char's.
	
    if (player==1){
        keys[0] = 'a';
        keys[1] = 'd';
        keys[2] = 'w';
        keys[3] = 's';
		state = 'w';
    }
    else if (player==2){
        keys[0] = 'j';
        keys[1] = 'l';
        keys[2] = 'i';
        keys[3] = 'k';
		state = 'k';
        snake[0][1] += 1;
    }

}

Snake::~Snake(){
	for(int i=0;i<size;i++){  // liberamos la memoria separa para cada elemento del array de punteros int.
		delete[] snake[i];       
	}
	delete[] snake; // liberamos la memoria del arreglo de punteros int.
	delete[] keys; // liberamos la memoria para el arreglo de char's
}

void Snake::snake_controller(Obs *obs, char key){ // recibe un puntero de la clase Obs y un char.
	x = snake[0][0];
	y = snake[0][1];
	
	for(int i=0; i<4; i++){
		if (keys[i] == key) state = key;
	}
		
	if (state == keys[0]){
		x--;
		if (x==-1 || obs->collide_obs(x, y)){  // si esque colisiona con la pared o un obstaculo no avanzara.
			x++;
			crash_snake();
		}
	}
	else if (state == keys[1]){				
		x++;
		if (x==size || obs->collide_obs(x, y)){ 
			x--;
			crash_snake();
		}
	}
	else if (state == keys[2]){				
		y--;
		if (y==-1 || obs->collide_obs(x, y)){
			y++;
			crash_snake();
		}
	}
	else if (state == keys[3]){				
		y++;
		if (y==size || obs->collide_obs(x, y)){
			y--;
			crash_snake();
		}
	}

	int ago_x=snake[0][0], ago_y=snake[0][1], copy_x, copy_y;  // la cola sigue al elemento n-1
	for (int i=1; i<len; i++){
		copy_x = snake[i][0];
		copy_y = snake[i][1];
		snake[i][0] = ago_x;
		snake[i][1] = ago_y;
		ago_x = copy_x;
		ago_y = copy_y;
	}
	snake[0][0] = x; snake[0][1] = y;
	
	if (t > limit_t){  // controlador de tiempo para el crecimiento de la cola
		t = 0;
		len++;
	}
	else{
		t++;
	}
}

void Snake::change_course(){
	char current = state;
	srand(time(NULL));
	do{
		state = keys[rand()%4];  // elige una direccion random para la snake.
	}while(state==current); // valida si no es la misma direccion que la actual.
}

bool Snake::same_pos(int x, int y){  // esta funcion verifica si a la hora de guardar los datos en la matrix o mapa son iguales en posiciones
    for(int i=0; i<len; i++){
        if (y==snake[i][0] && x==snake[i][1]) return true;
    }
    return false;	
}

  
void Snake::crash_snake(){
	len = 1;
	t = 0;
	change_course();
}

int Snake::get_len(){
	return len;
}

void Snake::add_tail(){
	len++;
}