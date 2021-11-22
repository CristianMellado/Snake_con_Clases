/**
Snake2.0


Departamento de Ciencia de la Computación
Prof: D.Sc. Manuel Eduardo Loaiza Fernández

Alumnos:
 - Cristian Mellado Baca
 - Marcelo Torres Acuña
 - Alexander Carpio Mamani
*/

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
		delete mapa;    // liberamos la memoria del objeto mapa.
		
		cout<<"\n Do you want to play again ? (yes: y / no: any key): ";cin>>op;
		if (op != 'y') break;
	}
	
}
