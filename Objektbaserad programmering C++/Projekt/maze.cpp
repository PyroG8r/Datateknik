#include "maze.h"

Maze::Maze(){   // default generate 11 x 11 maze;
    begin = nullptr;
    end = nullptr;
    head = nullptr;

    srand (time(NULL));
    structure(11,11);
}

Maze::Maze(size_t size_X, size_t size_Y){   // parametiserad konstruktor som tar in x & y 
    begin = nullptr;
    end = nullptr;
    head = nullptr;

    srand (time(NULL));
    structure(size_X,size_Y);
}

Maze::~Maze(){

    node* kolumn = head;
    node* row = head;
    node* it;
    while(row != nullptr){
        while(kolumn != nullptr){
            it = kolumn;
            kolumn = kolumn->right;
            delete it;
        }
        row = row->down;
        kolumn = row;
    }
}

Maze::node::node(/*bool visited, bool path*/){ 
    visited = false;
    path = false;
    up = nullptr;
    right = nullptr;
    down = nullptr;
    left = nullptr;
}


void Maze::structure(size_t size_X, size_t size_Y){
    node* kolumn = new node();
    node* row;
    head = kolumn;
    for(size_t i = 0; i < size_X - 1; i++){
        node* N = new node();
        kolumn->right = N;
        N->left = kolumn;
        kolumn = N;
    }
    for(kolumn = head, row = head; kolumn != nullptr; kolumn = kolumn->right){
        for(size_t i = 0; i < size_Y - 1; i++){
            node* N = new node();
            row->down = N;
            N->up = row;
            row = N;
        }
        row = kolumn->right;
    }
    kolumn = head;
    row = head;
    while(kolumn->right != nullptr){
        while(row->down != nullptr){
            row->down->right = row->right->down;
            row->right->down->left = row->down;
            row = row->down;
        }
        kolumn = kolumn->right;
        row = kolumn;
    }
    size_X = (size_X - 1) / 2;
    size_Y = (size_Y - 1) / 2;
    size_t surround = (size_X * 2) + ((size_Y-2) * 2);
    size_t begin_pos, end_pos;
    begin_pos = 1 + rand() % surround;
    end_pos = 1 + rand() % surround;
    while(begin_pos == end_pos){    //så länge begin och end är lika, gör en ny end;
        end_pos = 1 + rand() % surround;
    }

    begin = getNodeFromSurround(begin_pos);
    end = getNodeFromSurround(end_pos);
}

void Maze::generate_dfs(){
    std::vector<node*> node_stack;
    node* N = begin;
    N->visited = true;
    node_stack.push_back(N);

    size_t direction;

    while(!node_stack.empty()){
        direction = rand() % 4; // problem att den väljer ett slumpmässigt håll som kanske redan är valt och då inte leder någon stans
        N = node_stack.back();
        if(has_Neighbours(N)){
            if(direction == up) {go_Up(N, node_stack);}
            if(direction == right) {go_Right(N, node_stack);}
            if(direction == down) {go_Down(N, node_stack);}
            if(direction == left) {go_Left(N, node_stack);}
            // system("clear");
            // print();
            // usleep(50);
        }
        else{

            node_stack.pop_back();
        }
    }



}
void Maze::generate_bfs(){
    std::vector<node*> node_queue;
    node* N = begin;
    N->visited = true;
    node_queue.push_back(N);

    size_t direction;

    while(!node_queue.empty()){
        direction = rand() % 4; // problem att den väljer ett slumpmässigt håll som kanske redan är valt och då inte leder någon stans
        N = node_queue.front();
        if(has_Neighbours(N)){
            // node_stack.push(N);
            if(direction == up) {go_Up(N, node_queue);}
            if(direction == right) {go_Right(N, node_queue);}
            if(direction == down) {go_Down(N, node_queue);}
            if(direction == left) {go_Left(N, node_queue);}
            // N = node_stack.top();
        }
        else{

            node_queue.pop_back();

            // N = node_stack.top();
        }
    }



}

void Maze::solve()
{
    node *path;
    path = begin;
    std::vector<node *> path_stack;
    path_stack.push_back(path);
    path_stack.push_back(path);
    path->path = true;
    while (!path_stack.empty()){
        path = path_stack.back();

        if (path == end){
            break;
        }

        else if (path->up->visited == true && !path->up->path){
            path->up->up->path = true;
            path->up->path = true;
            path_stack.push_back(path->up);
            path_stack.push_back(path->up->up);
        }
        else if (path->right->visited == true && !path->right->path){
            path->right->right->path = true;
            path->right->path = true;
            path_stack.push_back(path->right);
            path_stack.push_back(path->right->right);
        }
        else if (path->down->visited == true && !path->down->path){
            path->down->down->path = true;
            path->down->path = true;
            path_stack.push_back(path->down);
            path_stack.push_back(path->down->down);
        }
        else if (path->left->visited == true && !path->left->path){
            path->left->left->path = true;
            path->left->path = true;
            path_stack.push_back(path->left);
            path_stack.push_back(path->left->left);
        }
        else{
            if (path_stack.size() == 1){path_stack.pop_back();}
            else{path_stack.resize(path_stack.size() - 2);} // remove last 2 elements
        }
    }
    for (node *n : path_stack)
    {
        n->way = true;
    }
}

Maze::node* Maze::cornerNode(node* N) const{
    node* p;
    if(N->left->left == nullptr){ p = N->left; }
    else if(N->right->right == nullptr){ p = N->right; }
    else if(N->up->up == nullptr){ p = N->up; }
    else if(N->down->down == nullptr){ p = N->down; }
    
    return p;
}

//gets a node in the surrounding maze, used for end and start position
Maze::node* Maze::getNodeFromSurround(size_t surround){
    node* N = head->down->right;
    for(size_t i = 0; i < surround; i++){
        if (N->up->up == nullptr && N->right->right != nullptr){
            N = N->right->right;
        }
        else if (N->right->right == nullptr && N->down->down != nullptr){
            N = N->down->down;
        }
        else if (N->down->down == nullptr && N->left->left != nullptr){
            N = N->left->left;
        }
        else if (N->left->left == nullptr && N->up->up != nullptr){
            N = N->up->up;
        }
    }
    return N;
}



//checks if the the node has any neighbours that is not visited
bool Maze::has_Neighbours(const node* N) const{
    if(N->up->up != nullptr && N->up->up->visited == 0){
        return true;
    }
    else if (N->right->right != nullptr && N->right->right->visited == 0){
        return true;
    }
    else if (N->down->down != nullptr && N->down->down->visited == 0){
        return true;
    }
    else if (N->left->left != nullptr && N->left->left->visited == 0){
        return true;
    }
    return false;
}


void Maze::go_Up(node* &N, std::vector<node*> &node_stack){
    if(N->up->up != nullptr && N->up->up->visited == false){
        N->up->up->visited = true;
        N->up->visited = true;
        node_stack.push_back(N->up->up);
    }
}
void Maze::go_Right(node* &N, std::vector<node*> &node_stack){
    if(N->right->right != nullptr && N->right->right->visited == false){
        N->right->right->visited = true;
        N->right->visited = true;
        node_stack.push_back(N->right->right);
    }
    
}
void Maze::go_Down(node* &N, std::vector<node*> &node_stack){
    if(N->down->down != nullptr && N->down->down->visited == false){
        N->down->down->visited = true;
        N->down->visited = true;
        node_stack.push_back(N->down->down);
    }
    
}
void Maze::go_Left(node* &N, std::vector<node*> &node_stack){
    if(N->left->left != nullptr && N->left->left->visited == false){
        N->left->left->visited = true;
        N->left->visited = true;
        node_stack.push_back(N->left->left);
    }
    
}


void Maze::print() const{
    node* kolumn = head;
    node* row = head;
    while(row != nullptr){
        while(kolumn != nullptr){
            if (!kolumn->visited){
                if (kolumn == cornerNode(begin)){
                    std::cout << "S ";
                }
                else if ( kolumn == cornerNode(end)){
                    std::cout << "E ";
                }
                else {
                std::cout << "██";
                }
            }
            else {
                    if(kolumn->way){
                        std::cout << "\033[1;36m⬤ \033[0m";
                    }
                    else{
                        std::cout << "　"; //"　"
                    }
                
            }
            kolumn = kolumn->right;
        }
        
        std::cout << std::endl;
        row = row->down;
        kolumn = row;
    }

}