/*
    Emil Jons
    2022-03-28
    Objektbaserad programmering
    Lab 2 - Linked list
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

class linked_list {
    public:
    /**
     * Construct a new linked list object
     */
    linked_list();
    /**
     * Construct a new linked list object 
     * and copies the src list to the new
     * @param src The list to be copied
    */
    linked_list(const linked_list &src);
    /**
     * Destroy the linked list object
     */
    ~linked_list();
    /**
     * Assigns rhs to lhs
     * 
     * @param rhs Right hand side
     * @return linked_list& - Left hand side
    */
    linked_list& operator=(const linked_list &rhs);

    /**
     * Appends elements from rhs to lhs
     * 
     * @param rhs Right hand side
     * @return linked_list& - Left hand side
    */
    linked_list& operator+=(const linked_list &rhs);

    // --- inserting elements ---

    /**
     * Insert a value at the given index of the list
     * 
     * @param value Value to insert
     * @param pos Position of where to insert the value
    */
    void insert(double value, size_t pos);
    /**
     * Push a value at the front of the list 
     * 
     * @param value Value to push
    */
    void push_front(double value);
    /**
     * Push a value at the back of the list 
     * 
     * @param value Value to push
    */
    void push_back(double value);

    // --- accessing elements ---

    /**
     * Returns the value at the front of the list
     * 
     * @return double - Front most value
    */
    double front() const;
    /**
     * Returns the value at the back of the list
     * 
     * @return double - Back most value
    */
    double back() const;
    /**
     * Returns the value of the element at the specified index
     * 
     * @param pos position of the element
     * @return double - Value at the position
    */
    double at(size_t pos) const;

    // --- removing elements ---

    /**
     * Removes the element at the specified index
     * 
     * @param pos position of the element to be removed
    */
    void remove(size_t pos);
    /**
     * Removes and returns the front most value in the list
     * 
     * @return double - Value of the front element
    */
    double pop_front();
    /**
     * Removes and returns the back most value in the list
     * 
     * @return double - Value of the back element
    */
    double pop_back();

    // --- status ---

    /**
     * Returns the size of the list
     * 
     * @return size_t - Size of the list
    */
    size_t size() const;
    /**
     * Returns true or false if the list is empty or not
    */
    bool is_empty() const;

    // --- output ---

    /**
     * Prints all the elements of the list
    */
    void print() const;
    /**
     * Prints all the elements of the list in the reverse order
    */
    void print_reverse() const;
    private:
    struct node{
        node(double value); // konstruktor för noden
        double value;
        node* next;
        node* prev;
    };
    node* head;
    node* tail;

    /**
     * Returns the node at the given index
     * 
     * @param pos position of the desired node
     * @return node* 
    */
    node* find(size_t pos) const;
};

#endif