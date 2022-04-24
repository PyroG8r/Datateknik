#include "maze.h"
#include "menu.h"

void menu()
{
    size_t option;
    size_t delay;
    welcome_Screen();


    while (true)
    {
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. Generate a maze \n2. Quit" << std::endl;
        option = input_Option(1, 2);
        
        switch(option)
        {
        case 1:
        {
            std::cout << "Enter the dimensions of the maze (must be odd numbers) ";
            size_t size_X, size_Y;

            std::cout << "Breadth: ";
            size_X = input_Dim();
            std::cout << "Height: ";
            size_Y = input_Dim();
            Maze maze(size_X, size_Y);

            std::cout << "1. Generate a maze using the DFS algorithm \n2. Generate a maze using the BFS algorithm \n3. Quit" << std::endl;
            option = input_Option(1, 3);
            switch (option)
            {
            case 1:
                std::cout << "Do you want to animate the generation? \nEnter the amount of delay to use (recomended 0-10000 ms)" << std::endl;
                delay = input_Positive_Number();
                maze.generate_dfs(delay);
                maze.solve();
                system("clear");
                maze.print();
                break;

            case 2:
                std::cout << "Do you want to animate the generation? \nEnter the amount of delay to use (recomended 0-10000 ms)" << std::endl;
                delay = input_Positive_Number();
                maze.generate_bfs(delay);
                maze.solve();
                system("clear");
                maze.print();
                break;
            case 3:
                exit(0);
            default:
                break;
            }
            break;
        }
        case 2:
            exit(0);
        default:
            break;
        }
    }
}

void welcome_Screen()
{
    std::cout << "██████████████████████████" << std::endl;
    std::cout << "██                      ██" << std::endl;
    std::cout << "██    --------------    ██" << std::endl;
    std::cout << "██        Welcome       ██" << std::endl;
    std::cout << "██    --------------    ██" << std::endl;
    std::cout << "██                      ██" << std::endl;
    std::cout << "██████████████████████████" << std::endl << std::endl;
}

size_t input_Dim()
{
    std::string str;
    // getline(std::cin, str);
    std::cin >> str;
    if (str == ""){ return 11;}
    else{
        while (!IsDigits(str) || !is_Odd(stoi(str)) || stoi(str) < 3){
            std::cout << "You must input a positive odd number over three...";
            std::cin >> str;
        }
        return stoi(str);
    }
}

size_t input_Positive_Number()
{
    std::string str;
    std::cin >> str;
    while (!IsDigits(str))
    {
        std::cout << "You must input a positive number...";
        std::cin >> str;
    }
    return stoi(str);
}
size_t input_Option(size_t from, size_t to)
{
    std::string str;
    std::cin >> str;
    while (!IsDigits(str) || stoi(str) > to || stoi(str) < from)
    {
        std::cout << "Välj ett av alternativen, "<< from <<"-"<< to <<"...\n";
        std::cin >> str;
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