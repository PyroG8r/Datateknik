
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

    void set(std::vector<std::string>);
    void generate_dfs(size_t delay);     //generate maze via dfs
    void generate_bfs(size_t delay);     //generate maze via bfs
    bool solve(size_t delay);

    void print(bool console) const; //print

    private:
    enum Direction{up, right, down, left};
    struct node{
        node();
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

    void structure();
    void set_Surround();
    void random_Begin_End();

    void set_unvisited();

    bool go_Dir(node* &N, std::vector<node*> &node_container, size_t dir);

    node* edge_Node(node* N) const;
    node* get_Node_From_Surround(size_t surround);

    bool has_Neighbour(const node*) const;

    void remove_Maze();
};

#endif