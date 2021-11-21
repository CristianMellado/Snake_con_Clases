#pragma once
#include <iostream>
#include "snake.cpp"
#include "apple.cpp"
#include "obstacle.cpp"

using namespace std;

class Map{
    public:
        int **matrix, size;
        char wall;
        Snake *player_1, *player_2;
        Apple *apple;
        Obs *obs;

        Map(int size);
        ~Map();
        void run_map();
        void save_in_matrix();
        void draw_map();
};