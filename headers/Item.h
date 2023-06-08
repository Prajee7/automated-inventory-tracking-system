/**
 * |-------------------------------------------------------------|
 *  Item.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The Item class is an abstract base class that represents an item in
 *  the movie rental shop's automated inventory tracking system. It inherits
 *  from the HashObject class, providing functionality for printing and hashing.
 *  This class serves as the interface for specific item types, and derived classes
 *  must implement the pure virtual methods defined in HashObject.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the HashObject class has been properly defined.
 */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>

#include "./HashObject.h"

using namespace std;

// HashObject is the superclass of Item.
class Item : public HashObject
{
public:
    // Constructor for Item class that initializes all the members in the parameter.
    Item(int priority) : priority(priority){};

    // Destructor, clears the allocated memory.
    virtual ~Item() {}

    // Virtual method to print the Item.
    virtual ostream &print(ostream &output) const
    {
        return HashObject::print(output);
    }

    // Virtual method to hash the item for a sort key.
    virtual string hashCode() const
    {
        throw runtime_error("hashCode() not implemented");
    }

    // Virtual method to get the sort key.
    virtual string sortKey() const
    {
        throw runtime_error("sortKey() not implemented");
    }

    // Virtual method to get the priority of the item.
    virtual int getPriority() const
    {
        return priority;
    }

protected:
    // To get the priority of the item.
    int priority = 0;
};

#endif
