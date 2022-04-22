#include <iostream>
#include "maze.h"
#include <limits>
#include <algorithm>
#include <fstream>
#include <stdio.h>

void inputMaze(FILE *__stream);
int main(int argc, char** argv)
{  
    if(argc > 1) { 
        std::string argument;
        for(int i = 1; i < argc; i++) {
            argument = argv[i];
            if(argument == "--solve") {
                inputMaze(stdin);

                
            }
            else {
                std::cout << "error" << std::endl;
            }
        }
    }
    else {
        Maze maze(81,15);
        
        maze.generate_dfs(500);
        // maze.generate_bfs(0);
        maze.solve();
        system("clear");
        maze.print();
    }

    return 0;
}

void inputMaze(FILE *__stream){
    rewind(__stream);
    std::string str;
    Maze maze;
    while(std::getline(std::cin, str)){
        maze.set(str);
    }
    maze.print();
    fclose(__stream);
}