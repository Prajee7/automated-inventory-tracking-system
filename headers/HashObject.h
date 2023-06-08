/**
 * |-------------------------------------------------------------|
 *  HashObject.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The HashObject classclass is an abstract base class that serves as the interface
 *  for objects that can be hashed and printed. It defines two pure virtual
 *  methods: print() and hashCode(). Classes derived from HashObject must
 *  implement these methods to provide the desired functionality.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes their might be runtime issues, and will handle them appropriately.
 */

#ifndef HASH_OBJECT_H
#define HASH_OBJECT_H

#include <iostream>

using namespace std;

class HashObject
{

public:
    // Virtual method to print the HashObject.
    virtual ostream &print(ostream &output) const
    {
        throw runtime_error("print() not implemented");
    }

    // virtual method to generate the hash code for the HashObject.
    virtual string hashCode() const
    {
        throw runtime_error("hashCode() not implemented");
    }

    // virtual method to generate the sort key for the HashObject.
    virtual string sortKey() const
    {
        throw runtime_error("sortKey() not implemented");
    }

    // Operator overloading for the output stream.
    friend ostream &operator<<(ostream &output, const HashObject &hashObject)
    {
        return hashObject.print(output);
    }
};

#endif
