/*
    Emil Jons
    2022-03-28
    Objektbaserad programmering
    Lab 2 - Linked list
*/

#include "linked_list.h"

//Constructor
linked_list::linked_list(){ 
    head = nullptr;
    tail = nullptr;
}

//Copy constructor
linked_list::linked_list(const linked_list &src){
    
    if (!is_empty()){      // Så länge den inte är tom
        head = nullptr;
        tail = nullptr;
        *this = src;       // Anväder sig av assignment operatorn
    }
    else{      // Om src är tom, måste fortfarande en länkad lista skapas. 
        head = nullptr;
        tail = nullptr;
    }
}

//Destructor
linked_list::~linked_list(){    
    if(!is_empty()){
        node* it = head;
        while(it != nullptr){   //Poppar varje nod
            it = it->prev;
            pop_front();
        }
    }
}

linked_list::node::node(double value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
}

//Assignment operator
linked_list &linked_list::operator=(const linked_list &rhs){
    if (this != &rhs){ //Om lhs och rhs är samma behöver inget hända
        node* it = rhs.head;
        while(!is_empty()){ //Tömmer lhs varje gång 
            pop_front();
        }
        while(it != nullptr){  //Fyller lhs med rhs
                push_back(it->value);
                it = it->prev;
        }
    }
    return *this;
}


linked_list &linked_list::operator+=(const linked_list &rhs){
    node* it = rhs.head;

    while(it != nullptr) {    // Appendar varje nod till lhf
        push_back(it->value);
        it = it->prev;
    }
    return *this;
}

//------inserting elements------
void linked_list::insert(double value, size_t pos){
    if (pos == size()){
        push_back(value);
    }
    else if (pos == 0){
        push_front(value);
    }
    else{
        node* N = new node(value);
        node* ptr= find(pos);
        N->prev = ptr;
        N->next = ptr->next;
        (ptr->next)->prev = N;
        ptr->next = N;
    }
}

void linked_list::push_back(double value){
    node* N = new node(value);
    if(is_empty()){ //Om listan är tom, sätt både head och tail till noden
        head = N;
        tail = N;
    }
    else {  
        N->next = tail;
        tail->prev = N;
        tail = N;
        tail->prev = nullptr;
    }
}
void linked_list::push_front(double value){
    node* N = new node(value);
    if(is_empty()){
        head = N;
        tail = N;
    }
    else {
        N->prev = head;
        head->next = N;
        head = N;
        head->next = nullptr;
    }
}

//------accessing elements------
double linked_list::front() const{
    if(!is_empty()){
        return head->value;
    }
    else {
        std::cout << "Failed to call front function, there are no elements in the list" << std::endl;
        exit(1);
    }
}

double linked_list::back() const{
    if(!is_empty()){
        return tail->value;
    }
    else {
        std::cout << "Failed to call back function, there are no elements in the list" << std::endl;
        exit(1);
    }
}

double linked_list::at(size_t pos) const{
    if(!is_empty()){
        if(size() == 0){
            std::cout<<"The list is empty..." << std::endl;
            exit(1);
        }
        else if (pos > size()){
            std::cout<<"The given position is out of bounds"<<std::endl;
            exit(1);
        }
        else{
            return (find(pos)->value);  
        }
    }
    else {
        std::cout << "Failed to call at function, there are no elemets in the list" << std::endl;
        exit(1);
    }
}

//------removing elements------
void linked_list::remove(size_t pos) {

    if(pos == 0){
        pop_front();
    }
    else if(pos == size()){
        pop_back();
    }
    else {
        node* N = find(pos);
        N->next->prev=N->prev;
        N->prev->next=N->next;
        delete N;
    }
}

double linked_list::pop_front(){
    double val;
    node* N = head;
    if (is_empty()){
        std::cout << "Cannot pop front, there are no elements in the list" << std::endl;
        exit(1);
    }
    else if (size() == 1){  // Specialfall om det bara finns en nod kvar, sätter head och tail till nullptrs
        val = head->value;
        head = nullptr;
        tail = nullptr;
        delete N;
        return val;

    }
    else {
        val = head->value;
        head = head->prev;
        head->next = nullptr;
        delete N;
        return val;
    }
    
}

double linked_list::pop_back(){
    double val;
    node* N = tail;
    if (is_empty()){
        std::cout << "Cannot pop back, there are no elements in the list" << std::endl;
        exit(1);
    }
    else if (size() == 1){  // Specialfall om det bara finns en nod kvar, sätter head och tail till nullptrs
        val = tail->value;
        head = nullptr;
        tail = nullptr;
        delete N;
        return val;
    }
    else {
        val = tail->value;
        tail = N->next;
        tail->prev = nullptr;
        delete N;
        return val;
    }
    
}

//------status------
size_t linked_list::size() const{
    size_t node_counter = 0;

    if(!is_empty()){
        node* it = head;
        while(it != nullptr) {
            node_counter++;
            it = it->prev;
        }
    }
    return node_counter;
}
bool linked_list::is_empty() const{
    if(head == nullptr && tail == nullptr){
        return true;
    }
    else {
        return false;
    }
}

// ------output------
void linked_list::print() const{
    node* it = head;
    while(it != nullptr){
        std::cout << it->value << " ";
        it = it->prev;
    }
    std::cout << std::endl;
}

void linked_list::print_reverse() const{
    node* it = tail;
    while(it != nullptr){
        std::cout << it->value << " ";
        it = it->next;
    }
    std::cout << std::endl;
}

//------Private find function used in other functions------
linked_list::node* linked_list::find(size_t pos) const {
    node* it = head;
    for(size_t i = 0; i < pos; i++) {
        it = it->prev;
    }
    return it;
}
