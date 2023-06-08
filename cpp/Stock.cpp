/**
 * |-------------------------------------------------------------|
 *  Stock.cpp
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

#include "../headers/Stock.h"

#include "../headers/Item.h"
#include "../headers/Movie.h"

template <typename T>
// Templatized class that allows any type of item to be stored.

// Constructors, Creates a Stock object for the given item.
Stock<T>::Stock(T *item) : item(item), amount(0), interactionCount(0)
{
}

/**
 * Constructor, Creates a Stock object for the given item with the initial inventory.
 */
template <typename T>
Stock<T>::Stock(T *item, const int inventory) : item(item), amount(inventory), interactionCount(0)
{
}

/**
 * Destructor, frees up allocated memory.
 */
template <typename T>
Stock<T>::~Stock()
{
    delete item;
}

/**
 * returns the current stock.
 */
template <typename T>
int Stock<T>::getInventory() const
{
    return this->amount;
}

/**
 * returns the item of the stock.
 */
template <typename T>
T Stock<T>::getItem() const
{
    return *this->item;
}

/**
 * returns the borrowed items count.
 */
template <typename T>
int Stock<T>::getBorrowed(string key) const
{
    if (this->borrowed.find(key) == this->borrowed.end())
        return 0;

    return this->borrowed.at(key);
}

/**
 * returns the number of transactions.
 */
template <typename T>
int Stock<T>::getInteractionCount() const
{
    return this->interactionCount;
}

/**
 * adds the given item to current stock.
 */
template <typename T>
void Stock<T>::addInventory(int amount)
{
    if (amount < 0)
        throw invalid_argument("Must be positive amount");

    this->amount += amount;
    this->interactionCount++;
}

/**
 * removes the given item from current stock. and throws error incase of edge cases.
 */
template <typename T>
void Stock<T>::removeInventory(int amount)
{
    if (amount < 0)
        throw invalid_argument("Must be positive amount");

    if (this->amount - amount < 0)
        throw invalid_argument("Inventory cannot be negative");

    this->amount -= amount;
}

/**
 * keeps track of borrowed inventory.
 */
template <typename T>
void Stock<T>::borrowInventory(string key, int amount)
{
    if (this->borrowed.find(key) == this->borrowed.end())
        this->borrowed[key] = 0;

    removeInventory(amount);
    this->borrowed[key] += amount;
    this->interactionCount++;
}

/**
 * keeps track of returned inventory.
 */
template <typename T>
void Stock<T>::returnInventory(string key, int amount)
{
    if (this->borrowed.find(key) == this->borrowed.end())
        throw invalid_argument("No stock borrowed");

    if (this->borrowed[key] - amount < 0)
        throw invalid_argument("Cannot return more stock than borrowed");

    this->borrowed[key] -= amount;
    addInventory(amount);
}

/**
 * Generates and returns the unique hash code for a specific Stock.
 */
template <typename T>
string Stock<T>::hashCode() const
{
    return this->item->hashCode();
}

/**
 * Prints the details of current Stock.
 */
template <typename T>
ostream &Stock<T>::print(ostream &output) const
{
    output << *this->item << " (" << this->amount << ")";
    return output;
}