/*
    Emil Jons
    2022-03-28
    Objektbaserad programmering
    Lab 2 - Linked list
*/
#include "linked_list.h"
#include <time.h>
#include <stdlib.h>

void print_list(linked_list l);
linked_list merge(linked_list&, linked_list&);
bool is_sorted(const linked_list&);

int main(){
    linked_list list1, list2, list3, list4;

//------------Test 1------------
    std::cout << "Test 1: Filling two lists with 50 random numbers" << std::endl;
    double rand_num;
    srand (time(NULL));
    for (size_t i = 0; i < 50; i++) {
        if (i == 0){
            list1.push_back(0);
            list2.push_back(0);
        }
        else{
            list1.push_back(list1.back() + (rand()%5));
            list2.push_back(list2.back() + (rand()%5));
        }

    }
    list1.print();
    list2.print();

//------------Test 2------------
    std::cout << std::endl;
    std::cout << "Test 2: Remove the largerst 25th element of both lists, if equal, remove from list 1" << std::endl;
    double num1 = list1.at(24);
    double num2 = list2.at(24);
    if (num1 > num2){
        list1.remove(24);
        std::cout << "Comparing " << num1 << " & " << num2 << " then removing: " << num1 << " in list 1 " << std::endl;
    }
    else if (num1 < num2){
        list2.remove(24);
        std::cout << "Comparing " << num1 << " & " << num2 << " then removing: " << num2 << " in list 2 " << std::endl;
    }
    else{
        list1.remove(24);
    }
    
//------------Test 3------------
    std::cout << std::endl;
    std::cout << "Test 3: The now smallest list in reverse: " << std::endl;
    // linked_list list3;
    if (list1.size() < list2.size()) list3 = list1;
    else list3 = list2;
    list3.print_reverse();

//------------Test 4------------
    std::cout << std::endl;
    std::cout << "Test 4: Removing every other element from list with 50 elements " << std::endl;
    if(list1.size() == 50) {
        std::cout << "Before: ";
        list1.print();
        for(size_t i = 0; i < 25; i++){
            list1.pop_back();
            list1.push_front(list1.pop_back());
        }
        std::cout << "After: ";
        list1.print();
    }
    else{
        std::cout << "Before: ";
        list2.print();
        for(size_t i = 0; i < 25; i++){
            list2.pop_back();
            list2.push_front(list2.pop_back());
        }
        std::cout << "After: ";
        list2.print();
    }

//------------Test 5------------
    std::cout << std::endl;
    std::cout << "Test 5: Printing the shortened list using the \"print_list()\" function " << std::endl;
    if(list1.size() == 25) print_list(list1);
    else print_list(list1);

//-----------Test 6------------
    std::cout << std::endl;
    // std::cout << list1.size() << std::endl;
    // std::cout << list2.size() << std::endl;
    std::cout << "Test 6: Merging the first two lists... new list is: " << std::endl;
    // linked_list 
    list4 = merge(list1, list2);
    list4.print();
    // std::cout << list4.size() << std::endl;

//------------Test 7------------
    std::cout << std::endl;
    std::cout << "Test 7: Is the merged list sorted? ";
    if (is_sorted(list4)) std::cout << "Yes." << std::endl;
    else std::cout << "No." << std::endl;

}

void print_list(linked_list l){
    l.print();
}

linked_list merge(linked_list& list1, linked_list& list2){
    linked_list merged_list;
    
    while(!list1.is_empty() && !list2.is_empty()){
        if (list1.front() < list2.front()){
            merged_list.push_back(list1.pop_front());
        }
        else {
            merged_list.push_back(list2.pop_front());
        }
    }
    // merged_list += list1;
    // merged_list += list2;
    while(!list1.is_empty()){
        merged_list.push_back(list1.pop_front());
    }
    while(!list2.is_empty()){
        merged_list.push_back(list2.pop_front());
    }
    return merged_list;
}

bool is_sorted(const linked_list& list){
    for(size_t i = 0; i < list.size(); i++){
        if(i == list.size() - 1) { 
            break;
        }
        if(list.at(i + 1) < list.at(i)) {
            return false;
        }
    }
    return true;
}

