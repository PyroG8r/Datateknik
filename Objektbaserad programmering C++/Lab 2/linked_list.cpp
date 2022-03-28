/*
    Emil Jons
    2022-03-28
    Objektbaserad programmering
    Lab 2 - Linked list
*/

#include <iostream>
#include "linked_list.h"

linked_list::linked_list(){
    head = nullptr;
    tail = nullptr;
}
linked_list::node::node(double value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
}

linked_list::linked_list(const linked_list &src){
    head = nullptr;
    tail = nullptr;
    
    *this = src;
}

linked_list::~linked_list(){
    if(!is_empty()){
        node* it = head;
        while(it != nullptr){
            it = it->prev;
            pop_front();
        }
    }
}

//assigns lhs to rhs
linked_list &linked_list::operator=(const linked_list &rhs){
    if (this != &rhs){ //Om lhs och rhs är samma behöver inget hända
        node* it = rhs.head;
        if(is_empty()) { //Om om lhs är tom, pusha alla rhs
            while(it != nullptr){
                push_back(it->value);
                it = it->prev;
            }
        }
        else{   // Om lhs inte är tom, töm den och fyll den med rhs
            while(!is_empty()){
                pop_front();
            }
            while(it != nullptr){
                push_back(it->value);
                it = it->prev;
            }
        }
    }
    return *this;
}

//appends elements from rhs
linked_list &linked_list::operator+=(const linked_list &rhs){
    node* it = rhs.head;
    if(this != &rhs) { 
        while(it != nullptr) {
            push_back(it->value);
            it = it->next;
        }
    }
    else { // Lägger rhs till en temporär lista
        linked_list temp;
        while(it != nullptr) {
            temp.push_back(it->value);
            it = it->prev;
        }
        it = temp.head; // Sätter ihop temp till "this"
        while(it != nullptr) {
            push_back(it->value);
            it = it->prev;
        }
    }
    return *this;
}

//inserting elements
void linked_list::insert(double value, size_t pos){
    // if(pos > size() || pos < 0){
    //     exit(1);
    // }
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
    if(is_empty()){
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

//accessing elements
double linked_list::front() const{
    if(!is_empty()){
        return head->value;
    }
    else {
        std::cout << "There are no elements in the list" << std::endl;
        return NULL;
    }
}

double linked_list::back() const{
    if(!is_empty()){
        return tail->value;
    }
    else {
        std::cout << "There are no elements in the list" << std::endl;
        return NULL;
    }
}

double linked_list::at(size_t pos) const{
    if(!is_empty()){
        if(size() == 0){
            std::cout<<"The list is empty..." << std::endl;
        }
        else if (pos > size()){
            std::cout<<"The given position is out of bounds"<<std::endl;
        }
        else{
            return (find(pos)->value);
        }
    }
    else {
        std::cout << "There are no elements in the list" << std::endl;
        return NULL;
    }


    // return (find(pos)->value);
}

//removing elements
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
    if (size() == 1){
        val = head->value;
        head = nullptr;
        tail = nullptr;
        delete N;
        return val;

    }
    else if (!is_empty()) {
        val = head->value;
        head = N->prev;
        head->next = nullptr;
        delete N;
        return val;
    }
    else{
        std::cout << "There are no elements in the list" << std::endl;
        return NULL;
    }
}

double linked_list::pop_back(){
    double val;
    node* N = tail;
    if(size() == 1){
        val = tail->value;
        head = nullptr;
        tail = nullptr;
        delete N;
        return val;
    }
    else if(!is_empty()){
        val = tail->value;
        tail = N->next;
        tail->prev = nullptr;
        delete N;
        return val;
    }
    else {
        std::cout << "There are no elements in the list" << std::endl;
        return NULL;
    }
}

//status
size_t linked_list::size() const{
    size_t node_counter = 0;

    if(!is_empty()){
        node* it = head;
        while(it != nullptr) {
            node_counter++;
            it = it->next;
        }
    }
    else {
        return node_counter;
    }
}
bool linked_list::is_empty() const{
    if(head == nullptr && tail == nullptr){
        return true;
    }
    else {
        return false;
    }
}

// output
void linked_list::print() const{
    node* it = head;
    std::cout << it->value;
    for(size_t i = 0; i < size(); i++){
        it = it->prev;
        std::cout << it->value;

        if (i == size()-1)
            std::cout << std::endl;
        else {
            std::cout << ", ";
        }
    }
}

void linked_list::print_reverse() const{
    node* it = tail;
    std::cout << it->value;
    for(size_t i = 0; i < size(); i++){
        it = it->next;
        std::cout << it->value;

        if (i == size()-1)
            std::cout << std::endl;
        else {
            std::cout << ", ";
        }
    }
}

linked_list::node* linked_list::find(size_t pos) const {
    node* it = head;
    for(size_t i = 0; i < pos; i++) {
        it = it->prev;
    }
    return it;
}
