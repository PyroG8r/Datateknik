
#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <unistd.h>


class Maze{
    public:
    Maze(); // konstruktor
    ~Maze();    // dekontruktor
    Maze(size_t size_X, size_t size_Y); //parametiserad konstruktor
    Maze(const Maze &src);  //copy konstruktor

    Maze& operator=(const Maze &rhs);   //tilldelning

    void generate_dfs();     //generate maze via dfs
    void generate_bfs();     //generate maze via bfs

    void print() const;

    private:
    enum Direction{up, right, down, left};
    struct node{
        node(/*bool visited, bool path*/);
        bool visited;
        bool path;
        node* up;
        node* right;
        node* down;
        node* left;
    };
    node* head;
    node* begin;
    node* end;


    void structure(size_t size_X, size_t size_Y);

    void go_Up(node* &N, std::stack<node*> &node_stack);
    void go_Right(node* &N, std::stack<node*> &node_stack);
    void go_Down(node* &N, std::stack<node*> &node_stack);
    void go_Left(node* &N, std::stack<node*> &node_stack);

    // node* startNode() const;
    // node* endNode() const;
    node* getNodeFromSurround(size_t surround);

    bool has_Neighbours(const node*) const;
};

#endif