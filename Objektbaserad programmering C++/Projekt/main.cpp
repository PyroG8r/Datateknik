#include <iostream>
#include "maze.h"

int main (){
    Maze maze(13,13);
    maze.generate_dfs();
    // maze.generate_bfs();
    maze.print();
    maze.solve();
    maze.print();
}