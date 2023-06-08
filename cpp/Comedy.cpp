/**
 * |-------------------------------------------------------------|
 *  Comedy.cpp
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The Comedy class is a derived class of the Movie class. It represents a
 *  Comedy movie in the movie rental shop's automated inventory tracking system.
 *  Each Comedy object contains information about the movie's title, director,
 *  release year, major actor, and release month. The Comedy.cpp implementation
 *  file includes the implementation for all of the methods of the Comedy class.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the Person and Movie classes have been properly defined and included.
 */
#include "../headers/Comedy.h"

/** |----------------------------------------Constructor-------------------------------------------------|
 *   Description: The Comedy class constructor is responsible for initializing each Comedy object,
 *   which represents a comedy movie in the movie rental shop. Each Comedy object is initialized
 *   by calling the Movie class constructor with the given title, director, and release year of
 *   the comedy movie.
 *  |----------------------------------------------------------------------------------------------------|
 */
Comedy::Comedy(string title, Person *director, int year) : Movie(title, director, year, 1)
{
}

/** |------------------------------------------hashCode--------------------------------------------------|
 *   Description: The hashCode method for the Comedy class returns the unique hash code for the
 *   comedy movie in the movie rental shop. The deriveHashCode method is called to retrieve the
 *   hash code, which is returned as a string.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Comedy::hashCode() const
{
    return Movie::hashCode();
}

/** |------------------------------------------sortKey---------------------------------------------------|
 *   Description: The sortKey method for the Comedy class is responsible for creating a unique sort
 *   key for each comedy movie in the movie rental shop, which will be used to sort the movies based
 *   on their movie title and release year.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Comedy::sortKey() const
{
    return deriveSortKey(title, year);
}

/** |----------------------------------------deriveSortKey-----------------------------------------------|
 *   Description: The deriveSortKey method for the Comedy class derives the unique sort key for each
 *   comedy movie by concatenating the movie's title with its release year.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Comedy::deriveSortKey(const string &title, const int year)
{
    return title + to_string(year);
}

/**
 * |------------------------------------------print----------------------------------------------------|
 * Description: The print method for the Comedy class.
 * |----------------------------------------------------------------------------------------------------|
 */
ostream &Comedy::print(ostream &output) const
{
    output << "Comedy ";
    Movie::print(output);
    return output;
}