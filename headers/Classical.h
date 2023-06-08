/**
 * |-------------------------------------------------------------|
 *  Classical.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The Classical class is a derived class of the Movie class. It represents a
 *  classical movie in the movie rental shop's automated inventory tracking system.
 *  Each Classical object contains information about the movie's title, director,
 *  release year, major actor, and release month.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the Person and Movie classes have been properly defined and included.
 */
#ifndef CLASSICAL_H
#define CLASSICAL_H

#include <iostream>
#include <sstream>

#include "./Movie.h"
#include "./Person.h"

using namespace std;

// Movie is the superclass of Classical.
class Classical : public Movie
{
public:
    // Constructor, initializes all the data members with default values.
    Classical(string title, Person *director, int year, Person *actor, int month);

    // Destructor, frees all the data members to free resources(memory allocated).
    ~Classical();

    // Generates and returns the unique hash code for the Classical movie.
    string hashCode() const;

    // Gets the sort key to the Drama movie.
    string sortKey() const;

    // Static method that calculates and returns the unique hash code for a Classical movie.
    static string deriveSortKey(const string &firstName, const string &lastName, int month, int year);

    // Prints the details of the Movie.
    ostream &print(ostream &output) const;

private:
    Person *actor; // The actor variable points to the actor starring in the Classical movie.
    int month;     // The release month of the classical movie.
};

#endif
