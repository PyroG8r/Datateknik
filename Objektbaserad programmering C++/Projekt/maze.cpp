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

Maze::node::node(){ 
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

/**
 * @brief Generates the maze using the DFS algorithm, using a stack
 * 
 * @param delay The amount of delay between every new step taken in the generation (ms)
 */
void Maze::generate_dfs(size_t delay){
    std::vector<node*> node_stack;
    size_t direction;
    node* N = begin;
    N->visited = true;
    node_stack.push_back(N);
    
    while(!node_stack.empty()){
        direction = rand() % 4;
        N = node_stack.back();
        node_stack.pop_back();
        if(has_Neighbour(N)){
            node_stack.push_back(N);
            while(!go_Dir(N, node_stack, direction)){
                direction = rand() % 4;
            }
            
            if (!delay == 0){
                system("clear");
                print(true);
                usleep(delay);
            }
        }
    }
}


/**
 * @brief Generates the maze using the BFS algorithm, using a queue
 * 
 * @param delay The amount of delay between every new step taken in the generation (ms)
 */
void Maze::generate_bfs(size_t delay){
    std::vector<node*> node_queue;
    size_t direction;
    node* N = begin;
    N->visited = true;
    node_queue.push_back(N);

    while(!node_queue.empty()){

        N = node_queue.front();
        node_queue.erase(node_queue.begin());
        direction = rand() % 4;
        if(has_Neighbour(N)){
            node_queue.push_back(N);
            while(!go_Dir(N, node_queue, direction)){
                direction = rand() % 4;
            }
            if (!delay == 0){
                system("clear");
                print(true);
                usleep(delay);
            }
        }
    }
}


/**
 * Sets the atributes of the maze given a vector with strings, 
 * where each string in the vector represents a row in the maze.
 * 
 * handles exeptions if there are too many beginings or endings or none at all.
 * 
 * if the character is a space (" ") treat it as a pasage.
 * if the character is an e or E treat it as an ending
 * if the character is an s or S treat is as a start.
 * everything else is a wall. 
 * 
 * @param v
 */
void Maze::set(std::vector<std::string> v){
    std::string str;
    node* kolumn = head;
    node* rows = kolumn;
    size_t nr_begin = 0;
    size_t nr_end = 0;
    for (auto &s : v){
        for (auto &c : s){
            if (c == ' '){
                kolumn->visited = true;
            }
            else {
                if (c == 'e' || c == 'E'){
                    if (nr_end > 1){std::cerr << "Not a valid maze, too many endings..." << std::endl; exit(0);}
                    if(kolumn->up == nullptr){end = kolumn->down; }
                    else if(kolumn->right == nullptr){end = kolumn->left; }
                    else if(kolumn->down == nullptr){end = kolumn->up; }
                    else if(kolumn->left == nullptr){end = kolumn->right; }
                    else{ std::cerr << "Ending is not on an edge" << std::endl; exit(0); }
                    nr_end++;
                }
                else if (c == 's' || c == 'S'){
                    if (nr_begin > 1){std::cerr << "Not a valid maze, too many starts..." << std::endl; exit(0);}
                    if(kolumn->up == nullptr){begin = kolumn->down; }
                    else if(kolumn->right == nullptr){begin = kolumn->left; }
                    else if(kolumn->down == nullptr){begin = kolumn->up; }
                    else if(kolumn->left == nullptr){begin = kolumn->right; }
                    else{ std::cerr << "Start is not on an edge" << std::endl; exit(0); }
                    nr_begin++;
                }
            }
            kolumn = kolumn->right;
        }
        rows = rows->down;
        kolumn = rows;

        
    }
    if (nr_begin == 0 || nr_end == 0){std::cerr << "Start or ending is missing" << std::endl; exit(0);}
}

/**
 * @brief Solves the maze using the DFS algorithm, 
 *  
 */
bool Maze::solve() {
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
    if (path_stack.size() == 0){return false;}
    for (node *n : path_stack) {    //when finished the stack "path_stack" contains the way to the finish...
        n->way = true;              //sets the correct atribute to all the nodes in the stack
    }
    return true;
}


/**
 * @brief Given a node that is adjacent to a edge, return the edge node.
 * This is used to print out start and finish, making it look like its an
 * opening in the edge of the maze
 * @param N Given node
 * @return Node* edge node
 */
Maze::node* Maze::edge_Node(node* N) const{
    node* p;
    if(N == begin){
        if(N->up->up == nullptr){ p = N->up; }
        else if(N->down->down == nullptr){ p = N->down; }
        else if(N->left->left == nullptr){ p = N->left; }
        else if(N->right->right == nullptr){ p = N->right; }
    }
    else if (N == end){
        if(N->right->right == nullptr){ p = N->right; }
        else if(N->left->left == nullptr){ p = N->left; }
        else if(N->down->down == nullptr){ p = N->down; }
        else if(N->up->up == nullptr){ p = N->up; }
    }
    return p;
}

/**
 * @brief Gets a node from the circumference of the node grid
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

/**
 * @brief Checks if the node in the direction is not nullptr and not visited
 * sets the node and the passage to visited and pushes the node to the vector
 * 
 * @param N origin node from which to go from
 * @param node_container container, containing previous nodes and the new traversed node
 * @param dir direction to traverse
 */
bool Maze::go_Dir(node* &N, std::vector<node*> &node_container, size_t dir){

    if(dir == up && N->up->up != nullptr && N->up->up->visited == false){
        N->up->up->visited = true; // node
        N->up->visited = true; // passage
        node_container.push_back(N->up->up);
        return true;
    }
    else if(dir == right && N->right->right != nullptr && N->right->right->visited == false){
        N->right->right->visited = true;
        N->right->visited = true;
        node_container.push_back(N->right->right);
        return true;
    }
    else if(dir == down && N->down->down != nullptr && N->down->down->visited == false){
        N->down->down->visited = true;
        N->down->visited = true;
        node_container.push_back(N->down->down);
        return true;
    }
    else if(dir == left && N->left->left != nullptr && N->left->left->visited == false){
        N->left->left->visited = true;
        N->left->visited = true;
        node_container.push_back(N->left->left);
        return true;
    }
    else {
        return false;
    }
}


/**
 * @brief A print function that prints the.
 * maze to the cmd prompt, in its current state. 
 * Start and end are represented by green and red flags "⚑".
 * Walls are represented by "██", showing up as white in the cmd.
 * Passages are represented by "  " two spaces, showing up as black in the cmd.
 * Solution is represented by "⬤ " blue balls, leading to the end.
 * 
 * @param bool console, if it prints to console or not, changes format accordingly
 */
void Maze::print(bool console) const{
    node* kolumn = head;
    node* row = head;
    while(row != nullptr){
        while(kolumn != nullptr){
            if (!kolumn->visited){
                if (kolumn == edge_Node(begin)){
                    if (console){std::cout << "\033[1;32m⚑ \033[0m";}
                    else{std::cout << "S ";}
                    
                }
                else if ( kolumn == edge_Node(end)){
                    if (console){std::cout << "\033[1;31m⚑ \033[0m";}
                    else {std::cout << "E ";}
                    
                }
                else {
                std::cout << "██";
                }
            }
            else {
                    if(kolumn->way){
                        if (console){std::cout << "\033[1;94m⬤ \033[0m";}
                        else {std::cout << "* ";}
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
    surround = (size_X - 1) + ((((size_Y-1)/2)-2)*2);
    if ( surround == 0){surround = 1;} // exeption if its an 3x3 maze with only one node.
}