/*
Samuel Greenberg
02/05/2021
DT019G
Labyrint Projekt
Siktar på betyget A
*/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <ctype.h>
#include <vector>

void printMenu(); // Prints GUI menu
void print1();
void print2();
void print3();
void print4();
void resetGUI(); // Clears the GUI

bool menuChoice(); // Menu options to execute
void GenerateMaze(); // Generates a maze
void DFSSOLVER(); // Generates and solves a maze with dfs
void BFSSOLVER(); // Generates and solves a maze with bfs
void play(); // Generates a maze, allows user to try and solve it

std::string sizeOptions();
std::string userInput(); // Getting menu input from user
bool generateOptions(); // Get maze generating algorithm
int getMazeSize(int check); // Gets size for maze to create

#endif