#include <iostream>
#include "maze.h"
#include "menu.h"
#include <limits>
#include <algorithm>
#include <fstream>
#include <stdio.h>
// #include <utility>

std::pair<size_t, size_t> get_Dimensions(std::vector<std::string>);
std::vector<std::string> read_File();
int main(int argc, char** argv)
{  
    if(argc > 1) { 
        std::string argument;
        for(int i = 1; i < argc; i++) {
            argument = argv[i];
            if(argument == "--solve") {
                std::vector<std::string> v = read_File();
                Maze maze(get_Dimensions(v).first,get_Dimensions(v).second);
                maze.set(v);
                maze.solve();
                maze.print();
            }
            else {
                std::cout << "error" << std::endl;
            }
        }
    }
    else {
        menu();
        // Maze maze(81,15);
        
        // maze.generate_dfs(500);
        // // maze.generate_bfs(0);
        // maze.solve();
        // system("clear");
        // maze.print();
    }

    return 0;
}


std::vector<std::string> read_File(){
    std::vector<std::string> v;
    std::string str;

    while (std::getline(std::cin, str)){
        if (v.size() > 0 && str.length() != v.back().length()){
            exit(15);
        }
        v.push_back(str);
    }
    return v;
}

std::pair<size_t, size_t> get_Dimensions(std::vector<std::string> v){
    
    size_t size_X, size_Y;
    size_X = 0;
    size_Y = 0;
    for (auto &s : v){
        size_X = 0;
        for (auto &c : s){
            size_X++;
        }
        size_Y++;
    }
    if (!is_Odd(size_X) || !is_Odd(size_Y)){
        exit(1);
    }
    return std::make_pair(size_X, size_Y);
}