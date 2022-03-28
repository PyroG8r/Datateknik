#include <iostream>
#include "linked_list.h"



linked_list::linked_list(){
    head = nullptr;
    tail = nullptr;
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


bool linked_list::is_empty() const{
    if(head == nullptr && tail == nullptr){
        return true;
    }
    else {
        return false;
    }
}
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

linked_list::node::node(double value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
}

linked_list::node* linked_list::find(size_t pos) const {
    node* it = head;
    for(size_t i = 0; i < pos; i++) {
        it = it->prev;
    }
    return it;
}
