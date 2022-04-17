#include <iostream>
#include "maze.h"

int main (){
    Maze maze(9,9);
    maze.generate_dfs();
}