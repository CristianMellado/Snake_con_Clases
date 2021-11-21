#pragma once  // para tener los archivos .h en paralelo
#include <iostream>
using namespace std;

class Printer{
	public:
  	    int size;
		string img;

        Printer(int , string );
        virtual ~Printer();  // usamos el virtual para que los hijos de esta clase puedan modificar esta función
		virtual bool same_pos(int, int);
		string get_img();
};
