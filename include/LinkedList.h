#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Item.h"
#include <iostream>

using namespace std;

// Nodes are used to represent an element in this project
struct Node {
    Item data;
    Node* next;

    Node(const Item& item) : data(item), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;
public:
    // Constructor and Destructor
    LinkedList();
    ~LinkedList();

    // Methods
    void append(const Item& item); // Adds an item
    void remove(int index);       // Removes an item by index
    Node* getNode(int index) const; // Gets a node by index
    Node* getHead() const;         // Gets the head of the list
    void clear();                  // Clears the list
    int getSize() const;           // Gets size
};

#endif
