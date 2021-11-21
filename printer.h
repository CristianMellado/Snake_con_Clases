#pragma once
#include <iostream>
using namespace std;

class Printer{
	public:
  	    int size;
		string img;

        Printer(int , string );
        virtual ~Printer();
		virtual bool same_pos(int, int);
		string get_img();
};