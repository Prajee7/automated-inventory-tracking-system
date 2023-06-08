/**
 * |-------------------------------------------------------------|
 *  Stock.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 * Description:
 * The Stock class represents the stock of an item in the movie rental shop's
 * automated inventory tracking system. It is a templated class that can work
 * with any type of item. It inherits from the HashObject class and provides
 * functionality to manage the inventory of the item, such as adding or removing
 * inventory and borrowing or returning inventory. It also keeps track of the borrowed
 * items and their quantities.
 * |-------------------------------------------------------------|
 * Assume:
 * The program assumes the HashObject class has been implemented correctly.
 */

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <fstream>
#include <unordered_map>

#include "./HashObject.h"
#include "./Item.h"

using namespace std;
// Templatized class that allows any type of item to be stored.
template <typename T>
// Stock is a child class of HashObject.
class Stock : public HashObject
{
public:
    // Constructors, Creates a Stock object for the given item.
    Stock(T *);

    // Constructor, Creates a Stock object for the given item with the initial inventory.
    Stock(T *, const int);

    // Destructor, frees up allocated memory.
    ~Stock();

    // get the item of the stock.
    T getItem() const;

    // adds the given item to current stock.
    void addInventory(int);
    // removes the given item from current stock.
    void removeInventory(int);

    // keeps track of borrowed inventory.
    void borrowInventory(string, int);
    // keeps track of returned inventory.
    void returnInventory(string, int);

    // returns the current stock.
    int getInventory() const;
    // returns the number of transactions.
    int getInteractionCount() const;
    // returns the borrowed items.
    int getBorrowed(string) const;

    // Generates and returns the unique hash code for a specific Stock.
    string hashCode() const;
    // Prints the details of current Stock.
    ostream &print(ostream &output) const;

private:
    int amount;                          // amount of stock.
    unordered_map<string, int> borrowed; // map that keeps track of borrowed items.
    T *item;                             // templatized stock.
    int interactionCount;                // keeps track of the number of transactions.
};

#endif
