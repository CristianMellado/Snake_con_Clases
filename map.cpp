#include "map.h"

Map::Map(int size=0){
    this->size = size;
    wall = char(254);

    matrix = new int *[size];
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


    player_1 = new Snake(size, "@", 1);
    player_2 = new Snake(size, "&", 2);
	
	string img_app = "\033[31m";
	img_app.push_back(char(254));
	img_app+= "\033[0m";
    apple = new Apple(size, img_app);
	
    obs = new Obs(size, "#");
}

Map::~Map(){
	for(int i=0;i<size;i++){
		delete[] matrix[i];       
	}
	delete[] matrix;

    delete player_1;
    delete player_2;
    delete apple;
    delete obs;
}

void Map::run_map(){
    while(1){
		char key = 'x';
		if (kbhit()){
			key = getch();
			if (key == 'q' || key == 'Q') break;
		}
		
		if (obs->get_n_obs() > 4) break;
		
		player_1->snake_controller(obs, key);
		player_2->snake_controller(obs, key);
		
		apple->appear_apple(obs);
		
		if(apple->same_pos(player_1->snake[0][1], player_1->snake[0][0])){
			apple->ate_apple();
			player_1->add_tail();
		}
		else if (apple->same_pos(player_2->snake[0][1], player_2->snake[0][0])){
			apple->ate_apple();
			player_2->add_tail();
		}
		
		obs->collide_snakes(player_1, player_2);
		
        draw_map();
    }
}

void Map::save_in_matrix(){
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

void Map::draw_map(){
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

