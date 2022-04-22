
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

    void set(std::string);
    void generate_dfs(size_t delay);     //generate maze via dfs
    void generate_bfs(size_t delay);     //generate maze via bfs
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
    node* head;      // top left of the maze
    node* begin;     // begin of the maze
    node* end;       // end of the maze
    size_t surround;
    size_t size_X, size_Y;

    void set_Surround();
    void structure();

    void go_Dir(node* &N, std::vector<node*> &node_container, size_t dir);
    // void go_Up(node* &N, std::vector<node*> &node_container);
    // void go_Right(node* &N, std::vector<node*> &node_container);
    // void go_Down(node* &N, std::vector<node*> &node_container);
    // void go_Left(node* &N, std::vector<node*> &node_container);

    node* cornerNode(node* N) const;
    node* getNodeFromSurround(size_t surround);

    bool has_Neighbour(const node*) const;
};

#endif