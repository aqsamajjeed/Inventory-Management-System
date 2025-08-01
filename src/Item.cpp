#include "Item.h"
#include <iostream>

using namespace std;

// Will initialize an item with inputted values
Item::Item(int i, const string& n, int q, double p) : id(i), name(n), quantity(q), price(p) {
}

// Getters
int Item::getId() const {
    return id; // Returns the unique identification of the item
}

string Item::getName() const {
    return name; // Returns the name of the item
}

int Item::getQuantity() const {
    return quantity; // Returns the quantity of the item
}

double Item::getPrice() const {
    return price; // Returns the price of the item
}

// Setters
void Item::setName(const string& n) {
    name = n; // Sets a new name for the item
}

void Item::setQuantity(int q) {
    quantity = q; // Sets a new quantity for the item
}

void Item::setPrice(double p) {
    price = p; // Sets a new price for the item
}

void Item::display() const {
    cout << "ID: " << id << ", Name: " << name
         << ", Quantity: " << quantity << ", Price: " << price << "\n";
}
