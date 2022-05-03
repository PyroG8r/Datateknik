#include "maze.h"
#include "menu.h"

void menu(){
    size_t option;
    size_t delay = 0;
    size_t size_X = 11 , size_Y = 11;
    std::string generation_algorthm = "DFS";
    welcome_Screen();
    while (option != 6){
        std::cout << "What do you want to do? Select input option (1-6) \n"; 
        std::cout << "1. Generate a default maze, 11 x 11 with fixed begin & end \n";
        std::cout << "2. Generate a maze with specified dimensions \n";
        std::cout << "3. Specify dimensions, currently: " << size_X << " x " << size_Y << ".\n";
        std::cout << "4. Select generation algorithm: " << generation_algorthm << ".\n";
        std::cout << "5. Enter amount of delay to use when animating the generation of the maze: " << delay << "ms.\n";
        std::cout << "6. Quit... \n";
        option = input_Option(1, 6);
        switch(option)
        {
        case 1:
        {
            Maze maze;
            maze.generate_dfs(delay);
            maze.solve(delay);
            system("clear");
            maze.print(true);
            break;
        }
        case 2:{
            Maze maze(size_X, size_Y);
            if (generation_algorthm == "DFS") { maze.generate_dfs(delay); }
            else if (generation_algorthm == "BFS") { maze.generate_bfs(delay); }
            maze.solve(delay);
            system("clear");
            maze.print(true);
            break;
        }
        case 3:{
            std::cout << "Enter the dimensions of the maze (must be odd numbers) ";
            std::cout << "Width: ";
            size_X = input_Dim();
            std::cout << "Height: ";
            size_Y = input_Dim();
            std::cout << std::endl;
            break;
        }
        case 4:{
            std::cout << "What algorithm to use when generating the maze: \n1. DFS\n2. BFS\n";
            option = input_Option(1, 2);
            if (option == 1){generation_algorthm = "DFS";}
            else {generation_algorthm = "BFS";}
            break;
        }
        case 5:{
            std::cout << "Enter amount of delay to use when animating the generation of the maze: " << delay << ".\n";
            delay = input_Positive_Number();
            break;
        }
        case 6:{
            std::cout << "Quitting... \n";
            exit(0);
        }
        default:
            break;
        }
    }
}

void welcome_Screen()
{
    std::cout << "/----------------------------------------------\\" << std::endl;
    std::cout << " __    __       _                              " << std::endl;
    std::cout << "/ / /\\ \\ \\ ___ | |  ___  ___   _ __ ___    ___ " << std::endl;
    std::cout << "\\ \\/  \\/ // _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\" << std::endl;
    std::cout << " \\  /\\  /|  __/| || (__| (_) || | | | | ||  __/" << std::endl;
    std::cout << "  \\/  \\/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|" << std::endl;
    std::cout << "                                               " << std::endl;
    std::cout << "\\----------------------------------------------/" << std::endl;
}

size_t input_Dim()
{
    std::string str;
    getline(std::cin, str);
    // std::cin >> str;
    
    while (!IsDigits(str) || str.length() == 0 || !is_Odd(stoi(str)) || stoi(str) < 3){
        std::cout << "You must input a positive odd number over three...";
        getline(std::cin, str);
    }
    return stoi(str);
}

size_t input_Positive_Number()
{
    std::string str;
    getline(std::cin, str);
    while (!IsDigits(str) || str.length() == 0)
    {
        std::cout << "You must input a positive number...";
        getline(std::cin, str);
    }
    return stoi(str);
}
size_t input_Option(size_t from, size_t to)
{
    std::string str;
    getline(std::cin, str);
    while (!IsDigits(str) || str.length() == 0 || stoi(str) > to || stoi(str) < from)
    {
        std::cout << "Välj ett av alternativen, "<< from << "-" << to <<"...\n";
        getline(std::cin, str);
    }
    return stoi(str);
}

bool IsDigits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool is_Odd(const size_t &n){
    if (n % 2 == 1){ return true;}
    else { return false;}
}