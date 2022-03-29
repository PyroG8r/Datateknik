/*
    Emil Jons
    2022-03-28
    Objektbaserad programmering
    Lab 2 - Linked list
*/

#include "linked_testing.h"
#include <time.h>
#include <stdlib.h>

void push_back_test(linked_list &list1, linked_list &list2){
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
}
void at_remove_test(linked_list &list1, linked_list &list2){
    double num1 = list1.at(24);
    double num2 = list2.at(24);
    if (num1 > num2){
        list1.remove(24);
        std::cout << "Removing " << num1 << " in list 1 " << std::endl;
    }
    else if (num1 < num2){
        list2.remove(24);
        std::cout << "Removing " << num2 << " in list 2 " << std::endl;
    }
    else{
        list1.remove(24);
    }
}








// void print_list(linked_list l){

// }
// linked_list merge(linked_list&, linked_list&){
//     linked_list merged;


//     return merged;
// }
// bool isSorted(const linked_list l){
//     return false;
// }