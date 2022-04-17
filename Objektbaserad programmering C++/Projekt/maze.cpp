#include "maze.h"

Maze::Maze(){   // default generate 11 x 11 maze;
    begin = nullptr;
    end = nullptr;
    head = nullptr;

    srand (time(NULL));
    structure(11,11);
}

Maze::Maze(size_t size_X, size_t size_Y){
    begin = nullptr;
    end = nullptr;
    head = nullptr;

    srand (time(NULL));
    structure(size_X,size_Y);
}
Maze::~Maze(){
    /*node* it = head;
        while(it != nullptr){   //Poppar varje nod
            delete();
        }*/
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
    // size_X = (size_X <- 1) / 2;
    // size_Y = (size_Y - 1) / 2;>
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
    size_t surround = (size_X * 2) + (size_Y * 2);
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
    std::stack<node*> node_stack;
    node* N = begin;
    N->visited = true;
    node_stack.push(N);

    size_t direction;

    while(!node_stack.empty()){
        direction = rand() % 4; // problem att den väljer ett slumpmässigt håll som kanske redan är valt och då inte leder någon stans
        N = node_stack.top();
        if(has_Neighbours(N)){
            // node_stack.push(N);
            if(direction == up) {go_Up(N, node_stack);}
            if(direction == right) {go_Right(N, node_stack);}
            if(direction == down) {go_Down(N, node_stack);}
            if(direction == left) {go_Left(N, node_stack);}
            // N = node_stack.top();
        }
        else{

            node_stack.pop();
            // N = node_stack.top();
        }
    }



}

//returns the adress of the start node
// Maze::node* Maze::startNode() const {

// }

//creates start position
Maze::node* Maze::getNodeFromSurround(size_t surround){
    node* N = head;
    for(size_t i = 0; i < surround; i++){
        if (N->up == nullptr && N->right != nullptr){
            N = N->right;
        }
        else if (N->right == nullptr && N->down != nullptr){
            N = N->down;
        }
        else if (N->down == nullptr && N->left != nullptr){
            N = N->left;
        }
        else if (N->left == nullptr && N->up != nullptr){
            N = N->up;
        }
    }
    return N;
}


//checks if the the node has any neighbours that is not visited
bool Maze::has_Neighbours(const node* N) const{
    if(N->up != nullptr && N->up->visited == 0){
        return true;
    }
    else if (N->right != nullptr && N->right->visited == 0){
        return true;
    }
    else if (N->down != nullptr && N->down->visited == 0){
        return true;
    }
    else if (N->left != nullptr && N->left->visited == 0){
        return true;
    }
    return false;
}

void Maze::go_Up(node* &N, std::stack<node*> &node_stack){
    if(N->up != nullptr && N->up->visited == false){
        N->up->visited = true;
        node_stack.push(N->up);
        system("clear");
        print();
        usleep(50000);
    }
    

}
void Maze::go_Right(node* &N, std::stack<node*> &node_stack){
    if(N->right != nullptr && N->right->visited == false){
        N->right->visited = true;
        node_stack.push(N->right);
        system("clear");
        print();
        usleep(50000);
    }
    
}
void Maze::go_Down(node* &N, std::stack<node*> &node_stack){
    if(N->down != nullptr && N->down->visited == false){
        N->down->visited = true;
        node_stack.push(N->down);
        system("clear");
        print();
        usleep(50000);
    }
    
}
void Maze::go_Left(node* &N, std::stack<node*> &node_stack){
    if(N->left != nullptr && N->left->visited == false){
        N->left->visited = true;
        node_stack.push(N->left);
        system("clear");
        print();
        usleep(50000);
    }
    
}

void Maze::print() const{
    node* kolumn = head;
    node* row = head;
    // while(kolumn != nullptr){ 
    //     std::cout << "██" << std::flush;
    //      kolumn = kolumn->right;
    // }
    // std::cout << std::endl;
    // kolumn = head;
    while(row != nullptr){
        // std::cout << "██" << std::flush;
        while(kolumn != nullptr){
            if (!kolumn->visited){
                std::cout << "██" << std::flush;
            }
            else {
                if (kolumn == begin){
                    std::cout << "S" << std::flush;
                }
                else if ( kolumn == end){
                    std::cout << "E" << std::flush;
                }
                else{
                    if(kolumn->path){
                        std::cout << "+" << std::flush;
                    }
                    else{
                        std::cout << "+" << std::flush; //"　"
                    }
                }
            }
            kolumn = kolumn->right;
        }
        
        std::cout << std::endl;
        row = row->down;
        kolumn = row;
    }

}