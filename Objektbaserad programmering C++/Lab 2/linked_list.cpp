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
    }
}

//accessing elements
double linked_list::front() const{
    if(!is_empty()){
        return head->value;
    }
    else {
        exit(1);
    }
}

double linked_list::back() const{
    if(!is_empty()){
        return tail->value;
    }
    else {
        exit(1);
    }
}

double linked_list::at(size_t pos) const{
    return (find(pos)->value);
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
    double val = head->value;
    node* N = head;
    head = N->prev;
    N->prev->next = nullptr;
    delete N;
    return val;
}

double linked_list::pop_back(){
    double val = tail->value;
    node* N = tail;
    tail = N->next;
    N->next->prev = nullptr;
    delete N;
    return val;
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





linked_list::node* linked_list::find(size_t pos) const {
    node* it = head;
    for(size_t i = 0; i < pos; i++) {
        it = it->prev;
    }
    return it;
}
