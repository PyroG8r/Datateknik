
#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>


class Maze{
    public:
    Maze(); // konstruktor
    ~Maze();    // dekontruktor
    Maze(size_t size_X, size_t size_Y); //parametiserad konstruktor
    Maze(const Maze &src);  //copy konstruktor

    Maze& operator=(const Maze &rhs);   //tilldelning

    void generate_dfs();     //generate maze via dfs
    void generate_bfs();     //generate maze via bfs
    void solve();

    void print() const;

    private:
    enum Direction{up, right, down, left};
    struct node{
        node(/*bool visited, bool path*/);
        bool visited;
        bool path;
        bool way;
        node* up;
        node* right;
        node* down;
        node* left;
    };
    node* head;
    node* begin;
    node* end;


    void structure(size_t size_X, size_t size_Y);

    void go_Up(node* &N, std::vector<node*> &node_stack);
    void go_Right(node* &N, std::vector<node*> &node_stack);
    void go_Down(node* &N, std::vector<node*> &node_stack);
    void go_Left(node* &N, std::vector<node*> &node_stack);

    node* cornerNode(node* N) const;
    node* getNodeFromSurround(size_t surround);

    bool has_Neighbours(const node*) const;
};

#endif