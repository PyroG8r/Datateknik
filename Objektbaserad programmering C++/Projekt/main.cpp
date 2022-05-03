#include "maze.h"
#include "menu.h"

/**
 * Frågor till najeb...
 * 
 * Inläsning från labyrint, där det är ett x på en plats där det ska vara en nod.
 * 
 * Ingen tilldeling eller copykontruktor.
 * 
 * Start och på samma plats
 * 
 * Stach eller sluts på olika plats från inläsning till utskrift
 */

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
                std::pair<size_t, size_t> dim = get_Dimensions(v);
                Maze maze(dim.first,get_Dimensions(v).second);
                maze.set(v);
                if (!maze.solve(0)){std::cerr << "Cannot solve maze, invalid maze..." << std::endl; return 0; }
                maze.print(false);
            }
            else {
                std::cout << "error" << std::endl;
            }
        }
    }
    else {
        if(!isatty(STDIN_FILENO)){ std::cerr << "Invalid arguments\nUse \"--solve\" when trying to read a maze from a file..." << std::endl; return 0; } // if there are no arguments but the terminal is associated with a file, exit
        menu();
    }
    return 0;
}

/**
 * @brief Reads file using getline(cin), pushes every line into a vector with strings.
 * handles exepetions if some line is different size, resulting in an illigal maze
 * 
 * @return std::vector<std::string> - vector of strings, every string is one row.
 */
std::vector<std::string> read_File(){
    std::vector<std::string> v;
    std::string str;

    while (std::getline(std::cin, str)){
        if (v.size() > 0 && str.length() != v.back().length()){     // Om raderna är olika långa
            std::cerr << "Invalid dimensions..." << std::endl;
            exit(0);
        }
        v.push_back(str);
    }
    return v;
}

/**
 * @brief Get the Dimensions of the maze given the string vector
 * 
 * @param v string vector
 * @return std::pair<size_t, size_t> size of the maze (X,Y)
 */
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
    if (!is_Odd(size_X) || !is_Odd(size_Y)){    // Om labyrinten inte är udda
        std::cerr << "Invalid dimesions, not odd..." << std::endl;
        exit(0);
    }
    return std::make_pair(size_X, size_Y);
}