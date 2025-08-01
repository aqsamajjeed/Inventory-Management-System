#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

// Represents individual item in the inventory.
class Item {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    // Constructor
    Item(int i, const string& n, int q, double p);

    // Getters
    int getId() const;
    string getName() const;
    int getQuantity() const;
    double getPrice() const;

    // Setters
    void setName(const string& n);
    void setQuantity(int q);
    void setPrice(double p);

    void display() const;
};

#endif
