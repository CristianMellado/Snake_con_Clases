/****************************************************************
Juego: Snake.io Game - mylib.cpp
UCSP : CIENCIAS DE LA COMPUTACIÓN
Alumno:
 - Alexander Carpio Mamani
*****************************************************************/

#include "mylib.h"

#define head_1 '@'
#define head_2 '&'
#define choque '#'

bool collide(int player[][2], int other[][2], int other_score, int chocaron_pos[]){
	for(int i=1;i<other_score+1;i++){
		if(player[0][0]==other[i][0] && player[0][1]==other[i][1]){ 
			chocaron_pos[0] = other[i][0]; chocaron_pos[1] = other[i][1];
			return true;
		}
	}
    return false;
}


bool collide_obs(int x, int y, int obs[][2], int n){
	for(int i=0;i<n;i++){
		if (x==obs[i][0] && y==obs[i][1]){
			return true;
		}
	}
	return false;
}

void snake_game(){
	int x,y, score=0, snake[50][2];
	int a,b, score2=0, snake2[50][2];
	int choques[5][2], n_choques=0, size_choques=0;
	int width=20, height=20, size;
	char state2='k', state='w', floor = char(254), keys_1[4]={'a','d','w','s'}, keys_2[4]={'j','l','i','k'};
	bool tail, tail2, choques_show, key_pressed=false, pared=false, chocaron=false, 
	touch1=false, touch2=false, touch3=false, touch4=false;
	int who = 0, chocaron_pos[2]={-1,-1}, time=10, time_1 = 0, time_2=0, clock=0;
	
	do{
		std::cout<<" Enter size(min 3 - max ?): ";std::cin>>size;
	}while(size < 3);
		
		
	int mid = size/2;
	snake[0][0] = mid;snake[0][1] = mid;
	snake2[0][0] = mid;snake2[0][1] = mid+1;
	width = size; height = size;
	
		
	while(1){	
		system(" ");
		std::cout<<"\033[H\033[2J\033[3J";
		std::cout<<"\nSnake Game \n\n";
		for (int i=0; i<height+2; i++){
			for (int j=0; j<width+2; j++){
				tail = false;
				for (int k=0; k<score+1; k++){
					if (snake[k][0]==j && snake[k][1]==i) tail = true;
				}  
				tail2 = false;
				for (int k=0; k<score2+1; k++){
					if (snake2[k][0]==j && snake2[k][1]==i) tail2 = true;
				}         
				choques_show = false;
				for (int k=0; k<size_choques; k++){
					if (choques[k][0]==j && choques[k][1]==i) choques_show = true;
				}

				if (choques_show){
					std::cout <<choque;
				}
				else if (tail){
					std::cout <<head_1;
				}
				else if (tail2){
					std::cout <<head_2;
				}
				else if (j == 0 || j == width+1 || i == 0 || i == height+1){
					std::cout<< floor;
				}
				else{
					std::cout<<" ";
				}
			}
			std::cout<<std::endl;
		}

		x = snake[0][0]; y = snake[0][1]; 
		if (touch1){
			score = 0;
			ChangeCourse(state, keys_1, clock);
			who=1;
			pared=true;
			time_1=0;
		}

		a = snake2[0][0]; b = snake2[0][1];
		if (touch2){
			score2 = 0;
			ChangeCourse(state2, keys_2, clock);
			who=2;
			pared=true;
			time_2=0;
		}
		
		if (collide(snake,snake2,score2, chocaron_pos)){
			ChangeCourse(state, keys_1, clock);
			choques[size_choques][0] = chocaron_pos[0];
			choques[size_choques][1] = chocaron_pos[1];
			size_choques++;
			n_choques++;
			score = 0;
			time_1=0;
		}
		else if (collide(snake2,snake,score, chocaron_pos)){
			ChangeCourse(state2, keys_2, clock);
			choques[size_choques][0] = chocaron_pos[0];
			choques[size_choques][1] = chocaron_pos[1];
			size_choques++;
			n_choques++;
			score2 = 0;
			time_2=0;
		}
		
		if (snake[0][0]==snake2[0][0] && snake[0][1]==snake2[0][1]){
			chocaron_pos[0] = snake[0][0];
			chocaron_pos[1] = snake[0][1];
			choques[size_choques][0] = chocaron_pos[0];
			choques[size_choques][1] = chocaron_pos[1];
			ChangeCourse(state, keys_1, clock);
			ChangeCourse(state2, keys_2, clock);
			size_choques++;
			n_choques++;
			score = 0;
			score2 = 0;
			time_1=0;
			time_2=0;
		}
		
		if (chocaron_pos[0]!=-1 && chocaron_pos[1]!=-1){
			chocaron = true;
			chocaron_pos[0]=-1; chocaron_pos[1]=-1;
		}
		
		if(key_pressed)
			std::cout<<"\n Gusano 1 ("<<snake[0][1]<<","<<snake[0][0]<<")  Gusano 2 (" << snake2[0][1]<<","<<snake2[0][0]<< ")\n";
		if (pared){
			std::cout<<"\n Gusano 1 ("<<snake[0][1]<<","<<snake[0][0]<<")";
			if (who==1)
				std::cout <<" -> Choco";
			
			std::cout<<"  Gusano 2 (" << snake2[0][1]<<","<<snake2[0][0]<< ")";
			if (who==2)
				std::cout <<" -> Choco";
			
			std::cout<<"\n";
			pared=false;
		}
		if (chocaron){
			std::cout<<"\n Gusano 1 ("<<snake[0][1]<<","<<snake[0][0]<<") -";
			std::cout<<" Gusano 2 (" << snake2[0][1]<<","<<snake2[0][0]<< ") ---> Chocaron en (";
			std::cout<<choques[size_choques-1][1]<<","<<choques[size_choques-1][0]<<")\n";
			chocaron=false;
		}
		
		if (touch3){
			score=0;
			ChangeCourse(state, keys_1, clock);
			time_1=0;
		}
		if (touch4){
			score2=0;
			ChangeCourse(state2, keys_2, clock);
			time_2=0;
		}

		touch1 = false;
		touch2 = false;
		touch3 = false;
		touch4 = false;

		char key = getch();
		key_pressed = true;
		if (key == 'q' || key == 'Q' || n_choques > 4) break;
		else if (key == 'a' || key == 'd' || key == 'w' || key == 's') state = key;
		else if (key == 'j' || key == 'l' || key == 'i' || key == 'k') state2 = key;
		else key_pressed = false;
		
		switch(state){
			case 'a': x--;
				if (x==0){ 
					x++;
					touch1 = true;
				}
				else if (collide_obs(x, y, choques, n_choques)){
					x++;
					touch3 = true;
				}
				break;
			case 'd': x++;
				if (x==width+1 || collide_obs(x, y, choques, n_choques)){ 
					x--;
					touch1 = true;
				}
				else if (collide_obs(x, y, choques, n_choques)){
					x--;
					touch3 = true;
				}
				break;
			case 'w': y--;
				if (y==0 || collide_obs(x, y, choques, n_choques)){
					y++;
					touch1 = true;
				}
				else if (collide_obs(x, y, choques, n_choques)){
					y++;
					touch3 = true;
				}
				break;
			case 's': y++;
				if (y==height+1 || collide_obs(x, y, choques, n_choques)){
					y--;
					touch1 = true;
				}
				else if (collide_obs(x, y, choques, n_choques)){
					y--;
					touch3 = true;
				}
				break;
		}

		switch(state2){
			case 'j': a--;
				if (a==0 || collide_obs(a, b, choques, n_choques)){
					a++;
					touch2 = true;
				}
				else if (collide_obs(a, b, choques, n_choques)){
					a++;
					touch4 = true;
				}
				break;
			case 'l': a++;
				if (a==width+1 || collide_obs(a, b, choques, n_choques)){
					a--;
					touch2 = true;
				}
				else if (collide_obs(a, b, choques, n_choques)){
					a--;
					touch4 = true;
				}
				break;
			case 'i': b--;
				if (b==0 || collide_obs(a, b, choques, n_choques)){
					b++;
					touch2 = true;
				}
				else if (collide_obs(a, b, choques, n_choques)){
					b++;
					touch4 = true;
				}
				break;
			case 'k': b++;
				if (b==height+1 || collide_obs(a, b, choques, n_choques)){
					b--;
					touch2 = true;
				}
				else if (collide_obs(a, b, choques, n_choques)){
					b--;
					touch4 = true;
				}
				break;
		}

		int ago_x=snake[0][0], ago_y=snake[0][1], copy_x, copy_y;
		for (int i=1; i<score+1; i++){
			copy_x = snake[i][0];
			copy_y = snake[i][1];
			snake[i][0] = ago_x;
			snake[i][1] = ago_y;
			ago_x = copy_x;
			ago_y = copy_y;
		}
		snake[0][0] = x; snake[0][1] = y;

		ago_x=snake2[0][0], ago_y=snake2[0][1];
		for (int i=1; i<score2+1; i++){
			copy_x = snake2[i][0];
			copy_y = snake2[i][1];
			snake2[i][0] = ago_x;
			snake2[i][1] = ago_y;
			ago_x = copy_x;
			ago_y = copy_y;
		}
		snake2[0][0] = a; snake2[0][1] = b;

		if (time_1 > time){
			time_1 = 0;
			score++;
		}
		else time_1++;
		if (time_2 > time){
			time_2 = 0;
			score2++;
		}
		else time_2++;
		
		if (clock > 2) clock = 0;
		else clock++;
	}

}

void game(){
	char op;
	do{
		snake_game();
		std::cout<<"\n\n =============== MENU ===============\n";
		std::cout<<"\n Desea jugar denuevo ? (y) para \"si\", cualquier otra tecla \"no\": "; std::cin>>op;
	}while(op=='y');
}

void ChangeCourse(char& course, char keys[4], int index){
	//int index = t/3; // [0-3], t [0-11]
	for(int i=0;i<4;i++){
		if (keys[i]==course){
			course = keys[index];
			break;
		}
	}
}