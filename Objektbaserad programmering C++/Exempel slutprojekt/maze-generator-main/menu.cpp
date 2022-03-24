/*
Samuel Greenberg
02/05/2021
DT019G
Labyrint Projekt
Siktar på betyget A
*/

#include "menu.h"
#include "maze.h"

void printMenu() { // Printing menu
    std::cout << "=====================================================" << std::endl <<
    "Maze Program" << std::endl <<
    "=====================================================" << std::endl <<
    "1. Generate Maze" << std::endl <<
    "2. DFS Solver" << std::endl <<
    "3. BFS Solver" << std::endl <<
    "4. Play" << std::endl <<
    "5. Quit" << std::endl;
}

void print1() {
    system("clear");
    std::cout << "=====================================================" << std::endl <<
    "Generate Maze" << std::endl << 
    "=====================================================" << std::endl;
}

void print2() {
    system("clear");
    std::cout << "=====================================================" << std::endl <<
    "DFS Solver" << std::endl << 
    "=====================================================" << std::endl;
}

void print3() {
    system("clear");
    std::cout << "=====================================================" << std::endl <<
    "BFS Solver" << std::endl << 
    "=====================================================" << std::endl;
}

void print4() {
    system("clear");
    std::cout << "=====================================================" << std::endl <<
    "Play" << std::endl << 
    "=====================================================" << std::endl;
}

void resetGUI() {
    std::cout << "Press [ENTER] to return to main menu... ";
    std::cin.get();
    system("clear");
    printMenu();
}

bool menuChoice() { // Menu system
    std::string choice = userInput(); // Makes sure userinput is a valid option

    if(choice == "1") { // Generates a maze
        GenerateMaze();
    }

    else if(choice == "2") { // Generates a maze and solves it with Depth-First search
        DFSSOLVER();
    }

    else if(choice == "3") { // Generates a maze and solves it with Breadth-First search
        BFSSOLVER();
    }

    else if(choice == "4") {
        play();
    }

    else if(choice == "5") { // Terminates the program
        system("clear");
        std::cout << "Exiting Maze Program." << std::endl;
        return false;
    }

    return true;
}

void GenerateMaze() {
    print1();
    bool generator = generateOptions();
    print1();
    std::string size = sizeOptions();

    maze myMaze;
    if(size == "2") {
        print1();
        int x = getMazeSize(0); // Gets width of maze from user
        int y = getMazeSize(1); // Gets height of maze from user
        std::cin.ignore();
        myMaze.generate(x, y); // Builds a grid of given width, height
    }
    else if(size == "1") {
        myMaze.generate(11, 11);
    }
    myMaze.pathGenerator(generator); // Grid done, now filling paths
    system("clear");
    myMaze.print();
    // Makes user interface cleaner
    resetGUI();
}

void DFSSOLVER() {
    print2();
    bool generator = generateOptions();
    print2();
    std::string size = sizeOptions();

    maze myMaze;
    if(size == "2"){
        print2();
        int x = getMazeSize(0); // Gets width of maze from user
        int y = getMazeSize(1); // Gets height of maze from user
        std::cin.ignore();
        myMaze.generate(x, y); // Builds a grid of given width, height
    }
    else if(size == "1") {
        myMaze.generate(11, 11);
    }

    myMaze.pathGenerator(generator); // Grid done, now filling paths
    std::cout << "Press [ENTER] to see DFS solution.";
    std::cin.get();

    // Generates solution
    myMaze.DFS();
    // Makes user interface cleaner
    resetGUI();
}

void BFSSOLVER(){
    print3();
    bool generator = generateOptions();
    print3();
    std::string size = sizeOptions();

    maze myMaze;
    if(size == "2") {
        print3();
        int x = getMazeSize(0); // Gets width of maze from user
        int y = getMazeSize(1); // Gets height of maze from user
        std::cin.ignore();
        myMaze.generate(x, y); // Builds a grid of given width, height
    }
    else if(size == "1") {
        myMaze.generate(11, 11);
    }
    myMaze.pathGenerator(generator); // Grid done, now filling paths
    // Generates solution
    myMaze.BFS();
        
    std::cout << "Press [ENTER] to see shortest solution.";
    std::cin.get();

    myMaze.printBFS();
    //Makes user interface cleaner
    resetGUI();
}

void play() {
    print4();
    bool generator = generateOptions();
    print4();
    std::string size = sizeOptions();

    maze myMaze;
    if(size == "2") {
        print4();
        int x = getMazeSize(0); // Gets width of maze from user
        int y = getMazeSize(1); // Gets height of maze from user
        std::cin.ignore();
        myMaze.generate(x, y); // Builds a grid of given width, height
    }
    else if(size == "1") {
        myMaze.generate(11, 11);
    }
    myMaze.pathGenerator(generator); // Grid done, now filling paths
    std::cout << "Press [ENTER] to start game";
    std::cin.get();

    myMaze.startGame();

    system("clear");
    printMenu();
}

std::string sizeOptions() {
    std::cout << "1. Default Size" << std::endl <<
    "2. Custom Size" << std::endl;
    std::string input;
    while(getline(std::cin, input)) {
        if(input == "1" || input == "2") {
            break;
        }
        else {
            std::cerr << "Invalid menu command!" << std::endl <<
            "Try Again!" << std::endl;
        }
    }
    return input;

}

std::string userInput() { // Gets a user input for the menu options
    std::string choice;
    bool badInput = true;
    while(badInput) {
        getline(std::cin, choice); // Gets input
        if(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") { // Checking if it's valid
            badInput = false;
        }
        else { // Bad input
            system("clear");
            printMenu();
            std::cerr << "Invalid menu command!" << std::endl <<
            "Try Again!" << std::endl;
        }
    }
    return choice;
}

bool generateOptions() {
    std::cout << "1. DFS Generator" << std::endl <<
    "2. BFS Generator" << std::endl;
    std::string input;
    while(getline(std::cin, input)) {
        if(input == "1" || input == "2") {
            if(input == "1") {
                return true;
            }
            break;
        }
        else {
            std::cerr << "Invalid menu command!" << std::endl <<
            "Try Again!" << std::endl;
        }
    }
    return false;
}

int getMazeSize(int check) { // Get a size for maze width or height
    if(check == 0) { // Checks if it's asking for width or height to adjust the cout accordingly
    std::cout << "Please specify a width for the maze: ";
    }
    else {
        std::cout << "Please specify a height for the maze: ";
    }
    int x = 3; // Gives x a valid option to ignore the first if statement once
    do {
        if(x % 2 == 0 || x <= 1) { // Given number is invalid
            std::cerr << "Invalid size given, it needs to be an odd number greater than 1." << std::endl <<
            "Try again: ";
        }
        std::cin >> x;
        while(std::cin.fail()) { // Input isn't a number
            std::cerr << "ERROR" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> x;
        }
    } while(x % 2 == 0 || x <= 1); // Repeat if given number is invalid
    
    return x;
}