/**
 * |-------------------------------------------------------------|
 *  Drama.cpp
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The Drama class is a derived class of the Movie class. It represents a
 *  Drama movie in the movie rental shop's automated inventory tracking system.
 *  Each Drama object contains information about the movie's title, director,
 *  release year, major actor, and release month. The Drama.cpp implementation
 *  file includes the implementation for all of the methods of the
 *  Drama class.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the Person and Movie classes have been properly defined and included.
 */
#include "../headers/Drama.h"

/** |----------------------------------------Constructor-------------------------------------------------|
 *   Description: The Drama class constructor is responsible for initializing Drama objects and their
 *   data members, such as the title, director, and release year of each drama movie. The Drama class
 *   constructor calls the Movie class constructor to initialize its member variables.
 *  |----------------------------------------------------------------------------------------------------|
 */
Drama::Drama(string title, Person *director, int year) : Movie(title, director, year, 2)
{
}

/** |-----------------------------------------hashCode---------------------------------------------------|
 *   Description: The hashCode method for the Drama class returns the hash code of the drama movie
 *   as a string by calling the deriveHashCode method with the specified member variables of the
 *   drama movie: director's first and last name, and movie title.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Drama::hashCode() const
{
    return Movie::hashCode();
}

/** |-----------------------------------------sortKey----------------------------------------------------|
 *   Description: The sortKey method for the Drama class is responsible for generating a unique sort key
 *   for each drama movie in the movie rental shop, this sort key will be used to sort the movies
 *   by the director's first and last name, and by their title.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Drama::sortKey() const
{
    return deriveSortKey(director->getFirstName(), director->getLastName(), title);
}

/** |--------------------------------------deriveSortKey-------------------------------------------------|
 *   Description: The deriveSortKey method for the Drama class derives the unique sort key for
 *   each drama movie that is stored in the movie rental shop. The sort key for each drama movie
 *   is generated by concatenating the director's first and last name with the title of the movie.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Drama::deriveSortKey(const string &directorFirstName, const string &directorLastName, const string &title)
{
    return directorFirstName + directorLastName + title;
}

/**
 * |------------------------------------------print----------------------------------------------------|
 * Description: The print method for the Drama class.
 * |----------------------------------------------------------------------------------------------------|
 */
ostream &Drama::print(ostream &output) const
{
    output << "Drama ";
    Movie::print(output);
    return output;
}