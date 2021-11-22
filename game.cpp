#include "game.h"

void run_game(){
    int size;
	char op;
	
	while(1){
		do{
			cout<<"\n Enter size(min 3 - max ?): ";cin>>size;     // validación de tamaño de mapa.
		}while(size < 3);

		Map *mapa = new Map(size);    // reservamos memoria para el objeto Map.
		mapa->run_map();
		
		cout<<"\n Do you want to play again ? (yes: y / no: any key): ";cin>>op;
		if (op != 'y') break;
		
		delete mapa;    // liberamos la memoria del objeto mapa.
	}
	
}
