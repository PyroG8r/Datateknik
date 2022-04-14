
#ifndef MAZE_H
#define MAZE_H

#include <iostream>


class Maze{
    public:

    Maze(); 

    Maze(const Maze &src);

    ~Maze();

    Maze& operator=(const Maze &rhs);

    void print() const;

    void generate(Maze &maze);

    private:
    struct node{
        node(bool visited, bool path);
        node* up;
        node* right;
        node* down;
        node* left;
    };
    node* head;
};

#endif