#include <iostream>
#include "maze.h"

int main (){
    Maze maze(83,23);
    maze.generate_dfs();
    // maze.generate_bfs();
    maze.print();
    maze.solve();
    maze.print();
}