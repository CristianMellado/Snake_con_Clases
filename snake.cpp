#include "snake.h"

Snake::Snake(int size, string img, int player):Printer(size, img){
	len = 1;
	limit_t = 10;
	t = 0;
	
    snake = new int *[size];
	for(int i=0; i<size; i++){    
		snake[i] = new int[2];
	}
	
    snake[0][0] = size/2;
    snake[0][1] = size/2;

	keys = new char[4];
	
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
	for(int i=0;i<size;i++){
		delete[] snake[i];       
	}
	delete[] snake;
	delete[] keys;
}

void Snake::snake_controller(Obs *obs, char key){
	x = snake[0][0];
	y = snake[0][1];
	
	for(int i=0; i<4; i++){
		if (keys[i] == key) state = key;
	}
		
	if (state == keys[0]){
		x--;
		if (x==-1 || obs->collide_obs(x, y)){ 
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

	int ago_x=snake[0][0], ago_y=snake[0][1], copy_x, copy_y;
	for (int i=1; i<len; i++){
		copy_x = snake[i][0];
		copy_y = snake[i][1];
		snake[i][0] = ago_x;
		snake[i][1] = ago_y;
		ago_x = copy_x;
		ago_y = copy_y;
	}
	snake[0][0] = x; snake[0][1] = y;
	
	if (t > limit_t){
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
		state = keys[rand()%4];
	}while(state==current);
}

bool Snake::same_pos(int x, int y){
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