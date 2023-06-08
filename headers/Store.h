/**
 * |-------------------------------------------------------------|
 *  Store.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 * Description:
 * The Store class represents the movie rental shop's automated inventory
 * tracking system. It manages the inventory of items, such as movies, and
 * keeps track of customers and their transaction history. The Store class
 * provides functionality to add or remove quantities of items, add customers,
 * borrow or return items, and print customer transaction history.
 * |-------------------------------------------------------------|
 * Assume:
 * The program assumes that the Item, Customer, and Stock classes have been implemented correctly.
 */

#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <climits>

#include "./Customer.h"
#include "./Stock.h"
#include "./Item.h"

using namespace std;

class Store
{
    static const int CACHE_STOCK_THRESHOLD = 4; // Requires a minimum of 4 interactions before being stored in the cache.

    // Ostream, is responsible for printing the output.
    friend ostream &operator<<(ostream &output, const Store &store);

public:
    // Default Constructor
    Store();
    // Destructor, frees up allocated memory.
    ~Store();

    // Returns the stock object from a given item.
    Stock<Item> *getStock(const Item *item);
    // Returns the stock object from a given sort key. If index is true, it will use the sortKey index instead of
    // accessing storage directly.
    Stock<Item> *getStock(const string &sortKey, bool index = true);

    // Returns the customer from a given customer pointer.
    Customer *getCustomer(const Customer *customer);
    // Returns the customer from a given customer key.
    Customer *getCustomer(const string &key);

    // Adds the specified quantity to the stock of the given item.
    void addQuantity(Item *item, int amount);
    // Removes the specified quantity from the stock of the given item.
    void removeQuantity(Item *item, int amount);

    // Adds the given customer to the store.
    void addCustomer(Customer *customer);

    // Performs the action of borrowing an item from the store.
    void borrowItem(string, string, int, string, int = INT_MAX);
    // Performs the action of returning an item to the store.
    void returnItem(string, string, int, string);

    // Prints customer transcation history from a given key.
    void printCustomerHistory(string key);

private:
    /**
     * The stores below are simulations of different types of databases with different access speeds and storage costs.
     * The intent of this is to simulate a real world scenario where a store would have a database with fast access
     * for frequently accessed items and a database with slow access for infrequently accessed items.
     *
     * Each store also has different storage costs, where the hot store is more expensive to store items in than the cold store. This objects
     * should never be accessed directly, but rather through the getStock() method.
     */
    unordered_map<string, Stock<Item> *> inventory_coldStore; // The inventory_hotStore is a map that keeps track of the frequently accessed items.
    unordered_map<string, Stock<Item> *> inventory_hotStore;  // The inventory_coldStore is a map that keeps track of the infrequently accessed items.

    unordered_map<string, string> inventoryIndex; // Map keeps track of the sort key for each item. The sort key is used to point to the item in the inventory.

    unordered_map<string, Customer *> customers; // Map keeps track of customers.

    void addStock(Item *item);          // Adds a stock to the store.
    void cacheStock(const string &key); // Promotes a stock from the cold store to the hot store.
};

#endif
