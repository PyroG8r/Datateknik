#include "maze.h"

Maze::Maze(){
}

Maze::node::node(bool visited, bool path){ 
    visited = false;
    path = false;
    up = nullptr;
    right = nullptr;
    down = nullptr;
    left = nullptr;
}


void Maze::generate(Maze &maze){

}

void Maze::print() const{

}