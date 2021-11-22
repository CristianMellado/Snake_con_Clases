#include "map.h"

Map::Map(int size=0){
    this->size = size;
    wall = char(254);

    matrix = new int *[size];  // separación de memoria para la matriz o mapa
	for(int i=0;i<size;i++){    
		matrix[i] = new int[size];
	}

    // 0: floor
    // 1: snake 1
    // 2: snake 2
    // 3: obstacle
    // 4: apple

	for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
		    matrix[i][j] = 0;
        }
	}


    player_1 = new Snake(size, "@", 1); // separacion de memoria para llos objetos(Snake, Apple, Obs)
    player_2 = new Snake(size, "&", 2);
	
	string img_app = "\033[31m";
	img_app.push_back(char(254));
	img_app+= "\033[0m";
    apple = new Apple(size, img_app);
	
    obs = new Obs(size, "#");
}

Map::~Map(){  // destructor
	for(int i=0;i<size;i++){   // liberación de memoria para la matriz o mapa
		delete[] matrix[i];       
	}
	delete[] matrix;

    delete player_1;  // lineración de memoria para los objetos Snake, Apple, Obs.
    delete player_2;
    delete apple;
    delete obs;
}

void Map::run_map(){
    while(1){
		char key = 'x';
		if (kbhit()){
			key = getch();
			if (key == 'q' || key == 'Q') break;  // si presionamos 'q' o 'Q' termina el juego.
		}
		
		if (obs->get_n_obs() > 4) break;  // si el número de colisiónes es mayor a 4 termina el juego.
		
		player_1->snake_controller(obs, key);
		player_2->snake_controller(obs, key);
		
		if(apple->same_pos(player_1->snake[0][1], player_1->snake[0][0])){
			apple->ate_apple(obs);
			player_1->add_tail();
		}
		else if (apple->same_pos(player_2->snake[0][1], player_2->snake[0][0])){
			apple->ate_apple(obs);
			player_2->add_tail();
		}
		
		obs->collide_snakes(player_1, player_2);
		
        draw_map();  // imprime el mapa o matriz.
    }
}

void Map::save_in_matrix(){  // guarda las posiciones de los objetos en la matriz o mapa.
	for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if (obs->same_pos(i,j))
                matrix[i][j] = 3;
            else if (player_1->same_pos(i,j))
                matrix[i][j] = 1;
            else if (player_2->same_pos(i,j))
                matrix[i][j] = 2;
            else if (apple->same_pos(i,j))
                matrix[i][j] = 4;                
            else
		        matrix[i][j] = 0;
        }
	}  
}

void Map::draw_map(){   // impresion de mapa o matriz.
	save_in_matrix();
	system(" ");
	cout<<"\033[H\033[2J\033[3J";
    for (int i=0; i<size+2;i++) cout<<wall;
    cout<<endl;

	for(int i=0;i<size;i++){
        cout<<wall;
        for(int j=0;j<size;j++){
            switch (matrix[i][j]){
                case 0:cout<<" ";break;
                case 1:cout<<player_1->get_img();break;
                case 2:cout<<player_2->get_img();break;
                case 3:cout<<obs->get_img();break;
                case 4:cout<<apple->get_img();break;
            }
        }
        cout<<wall<<endl;
	}

    for (int i=0; i<size+2;i++) cout<<wall;
    cout<<endl;

}

