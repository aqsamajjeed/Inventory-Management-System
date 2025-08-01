#ifndef INVENTORY_H
#define INVENTORY_H

#include "LinkedList.h"
#include "HashMap.h"
#include <iostream>

using namespace std;

// Manages a list of items in the inventory.
class Inventory {
private:
    LinkedList items;      // Using the Linked Lists Data Structure
    HashMap itemIndex;     // Using the Hash Map Data Structure

public:
    // Constructor with 20 buckets
    Inventory() : itemIndex(20) {}

    // Methods
    void addItem();                // Adds a new item
    void removeItem();             // Removes an item by ID
    void updateItem();             // Updates an existing item
    void displayItems() const;     // Displays all items
    void saveToFile() const;       // Saves inventory to file
    void loadFromFile();           // Loads inventory from file
    void searchByID() const;       // Searches for an item by ID
};

#endif
