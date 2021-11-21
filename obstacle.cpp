#include "obstacle.h"

Obs::Obs(int size, string img):Printer(size, img){
    max_obs = 5;
    n_obs = 0;

    obs = new int *[max_obs];
	for(int i=0;i<max_obs;i++){    
		obs[i] = new int[2];
	}
}

Obs::~Obs(){
	for(int i=0;i<max_obs;i++){
		delete[] obs[i];       
	}
	delete[] obs;
}


bool Obs::collide_obs(int x, int y){
    for(int i=0; i<n_obs; i++){
        if (x==obs[i][0] && y==obs[i][1]){
			return true;
		}
    }
    return false;
}


bool Obs::same_pos(int x, int y){
    for(int i=0; i<n_obs; i++){
        if (y==obs[i][0] && x==obs[i][1]) return true;
    }
    return false;
}

void Obs::crash(int x, int y){
    if (n_obs < max_obs){
        obs[n_obs][0] = x;
        obs[n_obs][1] = y;
        n_obs++;
    }
}

int Obs::get_n_obs(){
    return n_obs;
}

void Obs::collide_snakes(Snake *p1, Snake *p2){
	bool one = false, two=false;
	int x,y,a,b;
	
	x = p1->snake[0][0];y = p1->snake[0][1];
	for(int i=0; i<p2->get_len(); i++){
		if (p2->snake[i][0] == x && p2->snake[i][1] == y) one = true;
	}
	for(int i=1; i<p1->get_len(); i++){
		if (p1->snake[i][0] == x && p1->snake[i][1] == y) one = true;
	}
	
	a = p2->snake[0][0];b = p2->snake[0][1];
	for(int i=0; i<p1->get_len(); i++){
		if (p1->snake[i][0] == a && p1->snake[i][1] == b) two = true;
	}
	for(int i=1; i<p2->get_len(); i++){
		if (p2->snake[i][0] == a && p2->snake[i][1] == b) two = true;
	}
	
	if (one && two && x==a && y==b){
		crash(x,y);
		p1->crash_snake();
		p2->crash_snake();
	}
	else if (one && two && (x!=a || y!=b)){
		crash(x,y);
		crash(a,b);
		p1->crash_snake();
		p2->crash_snake();
	}
	else if (one){
		crash(x,y);
		p1->crash_snake();
	}
	else if (two){
		crash(a,b);
		p2->crash_snake();
	}
}