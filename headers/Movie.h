/**
 * |-------------------------------------------------------------|
 *  Movie.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 * Description:
 * The Movie class is an abstract base class that represents a movie in the
 * movie rental shop's automated inventory tracking system. It inherits from
 * the Item class and provides functionality for storing information about the
 * movie, such as its title, director, and release year. Derived movie genre
 * classes can be created from this base class to represent specific movie genres.
 * |-------------------------------------------------------------|
 * Assume:
 * The program assumes that the Item and Person classes have been properly implemented.
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <sstream>

#include "./Item.h"
#include "./Person.h"

using namespace std;

// The Item class is superclass of Movie.
class Movie : public Item
{

protected:
    Person *director; // The director of the movie.
    string title;     // The title of the movie.
    int year;         // The year the movie was released.

public:
    // Constructor that initializes the Movie private members through values from the parameters.
    Movie(string title, Person *director, int year, int priority);

    // Destructor, frees up the memory allocated in this class.
    virtual ~Movie();

    // returns the name of the Movie.
    string getTitle() const;

    // returns the name of the Director.
    string getDirector() const;

    // returns the year the Movie was released.
    int getYear() const;

    // Generates and returns the unique hash code for the Movie.
    virtual string hashCode() const;

    // Prints the details of the Movie.
    virtual ostream &print(ostream &output) const;
};

#endif
