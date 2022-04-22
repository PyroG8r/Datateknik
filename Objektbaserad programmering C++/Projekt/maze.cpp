#include "maze.h"

Maze::Maze(){   // default generate 11 x 11 maze;
    begin = nullptr;
    end = nullptr;
    head = nullptr;
    this->size_X = 11;
    this->size_Y = 11;
    set_Surround();

    srand (time(NULL));
    structure();
}

Maze::Maze(size_t size_X, size_t size_Y){   // parametiserad konstruktor som tar in x & y 
    begin = nullptr;
    end = nullptr;
    head = nullptr;
    this->size_X = size_X;
    this->size_Y = size_Y;
    set_Surround();

    srand (time(NULL));
    structure();
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
    way = false;
    up = nullptr;
    right = nullptr;
    down = nullptr;
    left = nullptr;
}


/**
 * @brief Creates new nodes and connects them resulting in a two dimensional linked data structure
 * where each node points to the four connecting nodes. 
 * The edges points to nullptrs and the 
 * size of the matrix is determined by the maze members size_X and size_Y 
 */
void Maze::structure(){
    node* kolumn = new node();
    node* row;
    head = kolumn;
    for(size_t i = 0; i < size_X - 1; i++){ // expands the structure in the x axis - to the right                                   
        node* N = new node();
        kolumn->right = N;
        N->left = kolumn;
        kolumn = N;
    }
    for(kolumn = head, row = head; kolumn != nullptr; kolumn = kolumn->right){  // expands the structure in the y axis - down      
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
    while(kolumn->right != nullptr){  // connects the remainding nodes
        while(row->down != nullptr){
            row->down->right = row->right->down;
            row->right->down->left = row->down;
            row = row->down;
        }
        kolumn = kolumn->right;
        row = kolumn;
    }
    size_t begin_pos, end_pos;
    begin_pos = rand() % surround;
    end_pos = rand() % surround;
    while(begin_pos == end_pos){    //så länge begin och end är lika, gör en ny end;
        if(size_X == 3 && size_Y == 3){break;} // undantag om det är en 3x3 labyrint
        end_pos = rand() % surround;
    }

    begin = getNodeFromSurround(begin_pos);
    end = getNodeFromSurround(end_pos);
}


void Maze::generate_dfs(size_t delay){
    std::vector<node*> node_stack;
    size_t direction;
    node* N = begin;
    N->visited = true;
    node_stack.push_back(N);
    
    while(!node_stack.empty()){
        direction = rand() % 4; // problem att den väljer ett slumpmässigt håll som kanske redan är valt och då inte leder någon stans
        N = node_stack.back();
        if(has_Neighbour(N)){
            go_Dir(N, node_stack, direction);
            if (!delay == 0){
                system("clear");
                print();
                usleep(delay);
            }
        }
        else{
            node_stack.pop_back();
        }
    }
}

void Maze::generate_bfs(size_t delay){
    std::vector<node*> node_queue;
    size_t direction;
    node* N = begin;
    N->visited = true;
    node_queue.push_back(N);

    while(!node_queue.empty()){

        int randomElement = rand() % node_queue.size();
        N = node_queue.at(randomElement);
        // node_queue.erase(node_queue.begin() + randomElement);


        direction = rand() % 4;
        // N = node_queue.front();
        if(has_Neighbour(N)){
            // node_stack.push(N);
            go_Dir(N, node_queue, direction);
            if (!delay == 0){
                system("clear");
                print();
                usleep(delay);
            }
        }
        else{

            N = node_queue.front();
            node_queue.erase(node_queue.begin());
        }
    }
}


void Maze::set(std::string str){

}


/**
 * @brief Solves the maze using the DFS algorithm, 
 *  
 */
void Maze::solve() {
    node *path = begin;
    path->path = true;
    std::vector<node*> path_stack;
    path_stack.push_back(path);

    while (!path_stack.empty()){
        path = path_stack.back();

        if (path == end){ break; }  // if the path reaches the end, break
        
        else if (path->up->visited == true && !path->up->path) {
            path->up->up->path = true;
            path->up->path = true;
            path_stack.push_back(path->up);
            path_stack.push_back(path->up->up);
        }
        else if (path->right->visited == true && !path->right->path) {
            path->right->right->path = true;
            path->right->path = true;
            path_stack.push_back(path->right);
            path_stack.push_back(path->right->right);
        }
        else if (path->down->visited == true && !path->down->path) {
            path->down->down->path = true;
            path->down->path = true;
            path_stack.push_back(path->down);
            path_stack.push_back(path->down->down);
        }
        else if (path->left->visited == true && !path->left->path) {
            path->left->left->path = true;
            path->left->path = true;
            path_stack.push_back(path->left);
            path_stack.push_back(path->left->left);
        }
        else{
            if (path_stack.size() == 1){ path_stack.pop_back(); } //remove first element
            else { path_stack.resize(path_stack.size() - 2); } // remove last 2 elements
        }
    }
    for (node *n : path_stack) {    //when finished the stack "path_stack" contains the way to the finish...
        n->way = true;              //sets the correct atribute to all the nodes in the stack
    }
}


/**
 * @brief Given a node that is adjacent to a corner, return the corner node.
 * This is used to print out start and finish, making it look like its an
 * opening in the corners of the maze
 * @param N Given node
 * @return Node* Corner node
 */
Maze::node* Maze::cornerNode(node* N) const{
    node* p;
    if(N->left->left == nullptr){ p = N->left; }
    else if(N->right->right == nullptr){ p = N->right; }
    else if(N->up->up == nullptr){ p = N->up; }
    else if(N->down->down == nullptr){ p = N->down; }
    
    return p;
}

/**
 * @brief gets a node from the surrounding corners of the maze in 
 * order to visualize the openings for the begining and the ending
 * 
 * @param surround the circumference of the maze
 * @return Maze::node* 
 */
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


/**
 * @brief checks if the the node parameter has any unvisited neighbours
 * 
 * @param N the node to check
 * @return true if it's available
 * @return false if it's unavailable
 */
bool Maze::has_Neighbour(const node* N) const {
    if(N->up->up != nullptr && N->up->up->visited == 0){ return true; }
    else if (N->right->right != nullptr && N->right->right->visited == 0){ return true; }
    else if (N->down->down != nullptr && N->down->down->visited == 0){ return true; }
    else if (N->left->left != nullptr && N->left->left->visited == 0){ return true; }
    else { return false; }
}

// ---- Traversal functions for maze generation ---- 
/**
 * @brief Checks if the node in the direction is not nullptr and not visited
 * sets the node and the passage to visited and pushes the node to the vector
 * 
 * @param N origin node from which to go from
 * @param node_container container, containing previous nodes and the new traversed node
 * @param dir direction to traverse
 */
void Maze::go_Dir(node* &N, std::vector<node*> &node_container, size_t dir){

    if(dir == up && N->up->up != nullptr && N->up->up->visited == false){
        N->up->up->visited = true; // node
        N->up->visited = true; // passage
        node_container.push_back(N->up->up);
    }
    else if(dir == right && N->right->right != nullptr && N->right->right->visited == false){
        N->right->right->visited = true;
        N->right->visited = true;
        node_container.push_back(N->right->right);
    }
    else if(dir == down && N->down->down != nullptr && N->down->down->visited == false){
        N->down->down->visited = true;
        N->down->visited = true;
        node_container.push_back(N->down->down);
    }
    else if(dir == left && N->left->left != nullptr && N->left->left->visited == false){
        N->left->left->visited = true;
        N->left->visited = true;
        node_container.push_back(N->left->left);
    }
}


/**
 * @brief A print function that prints the.
 * maze to the cmd prompt, in its current state. 
 * Start and end are represented by green and red flags "⚑".
 * Walls are represented by "██", showing up as white in the cmd.
 * Passages are represented by "  " two spaces, showing up as black in the cmd.
 * Solution is represented by "⬤ " blue balls, leading to the end.
 */
void Maze::print() const{
    node* kolumn = head;
    node* row = head;
    while(row != nullptr){
        while(kolumn != nullptr){
            if (!kolumn->visited){
                if (kolumn == cornerNode(begin)){
                    std::cout << "S ";
                    // std::cout << "\033[1;32m⚑ \033[0m";
                }
                else if ( kolumn == cornerNode(end)){
                    std::cout << "E ";
                    // std::cout << "\033[1;31m⚑ \033[0m";
                    
                }
                else {
                std::cout << "██";
                }
            }
            else {
                    if(kolumn->way){
                        std::cout << "⬤ ";
                        // std::cout << "\033[1;94m⬤ \033[0m";
                    }
                    else{
                        std::cout << "  ";
                    }
                
            }
            kolumn = kolumn->right;
        }
        
        std::cout << std::endl;
        row = row->down;
        kolumn = row;
    }

}
/**
 * @brief Sets the surround value to the circumference of the maze accordingly
 */
void Maze::set_Surround() {
    surround = (size_X - 1) + ((((size_Y-1) / 2)-2)*2);
    if ( surround == 0){surround = 1;}
}