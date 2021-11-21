#include "printer.h"

Printer::Printer(int size, string img){
	this->size = size;
	this->img = img;
}

Printer::~Printer(){
}

bool Printer::same_pos(int x, int y){
	return false;
}

string Printer::get_img(){
	return img;
}