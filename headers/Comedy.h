/**
 * |-------------------------------------------------------------|
 *  Comedy.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The Comedy class is a derived class of the Movie class. It represents a
 *  Comedy movie in the movie rental shop's automated inventory tracking system.
 *  Each Comedy object contains information about the movie's title, director,
 *  release year, major actor, and release month.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the Person and Movie classes have been properly defined and included.
 */
#ifndef COMEDY_H
#define COMEDY_H

#include <iostream>
#include <sstream>

#include "./Movie.h"
#include "./Person.h"

using namespace std;

// Movie is the superclass of Comedy.
class Comedy : public Movie
{
public:
    // Constructor for Comedy class that initializes all the members in the parameter.
    Comedy(string title, Person *director, int year);

    // Generates and returns the unique hash code for the Comedy movie.
    string hashCode() const;

    // Gets the sort key to the Comedy movie.
    string sortKey() const;

    // Static method that calculates and returns the unique hash code for a Comedy movie.
    static string deriveSortKey(const string &title, const int year);

    // Prints the details of the Movie.
    ostream &print(ostream &output) const;
};

#endif
