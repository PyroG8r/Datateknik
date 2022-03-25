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

void linked_list::push_back(double value){

}