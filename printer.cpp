/**
Snake2.0


Departamento de Ciencia de la Computación
Prof: D.Sc. Manuel Eduardo Loaiza Fernández

Alumnos:
 - Cristian Mellado Baca
 - Marcelo Torres Acuña
 - Alexander Carpio Mamani
*/



#include "printer.h"

Printer::Printer(int size, string img){
	this->size = size;   // this para señalar que esta variable es propia de la clase y diferenciarlas de los parametros
	this->img = img;
}

Printer::~Printer(){
}

bool Printer::same_pos(int x, int y){
	return false;
}

string Printer::get_img(){  // retornara una cade de string
	return img;
}
