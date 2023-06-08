/**
 * |-------------------------------------------------------------|
 *  Drama.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The Drama class is a derived class of the Movie class. It represents a
 *  Drama movie in the movie rental shop's automated inventory tracking system.
 *  Each Drama object contains information about the movie's title, director,
 *  release year, major actor, and release month.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the Person and Movie classes have been properly defined and included.
 */
#ifndef DRAMA_H
#define DRAMA_H

#include <iostream>
#include <sstream>

#include "./Movie.h"
#include "./Person.h"

using namespace std;

// Movie is the superclass of Drama.
class Drama : public Movie
{
public:
    // Constructor, initializes all the members from the parameters.
    Drama(string title, Person *director, int year);

    // Generates and returns the unique hash code for the Drama movie.
    string hashCode() const;

    // Gets the sort key to the Drama movie.
    string sortKey() const;

    // Static method that calculates and returns the unique hash code for a Drama movie.
    static string deriveSortKey(const string &directorFirstName, const string &directorLastName, const string &title);

    // Prints the details of the Movie.
    ostream &print(ostream &output) const;
};

#endif
