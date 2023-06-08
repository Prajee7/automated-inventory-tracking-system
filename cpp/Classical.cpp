/**
 * |-------------------------------------------------------------|
 *  Classical.cpp
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The Classical class is a derived class of the Movie class. It represents a
 *  classical movie in the movie rental shop's automated inventory tracking system.
 *  Each Classical object contains information about the movie's title, director,
 *  release year, major actor, and release month. The Classical.cpp implementation
 *  file contains the implementation for all of the methods of the Classical class.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the Person and Movie classes have been properly defined and included.
 */
#include "../headers/Classical.h"

/** |----------------------------------------Constructor-------------------------------------------------|
 *   Description: The Classical class constructor is responsible for initializing the data members of the Classical class,
 *   such as each Classical class's movie title, director, release year and month, and the movie's major actor. The parameters
 *   for the class's constructor is the title of the classical movie, represented by a string, A person pointer that
 *   represents the director of the classical movie and a person pointer that represents the major actor, as well as
 *   integer variables that represent the release year and month of the movie.
 *  |----------------------------------------------------------------------------------------------------|
 */
Classical::Classical(string title, Person *director, int year, Person *actor, int month) : Movie(title, director, year, 3)
{
    this->actor = actor;
    this->month = month;
}

/** |-----------------------------------------Destructor-------------------------------------------------|
 *   Description: The Classical class destructor is responsible for freeing up any memory that was
 *   allocated by the Classical class and ensures that the memory that was allocated is properly
 *   freed when the Classical object is destroyed by the destructor.
 *  |----------------------------------------------------------------------------------------------------|
 */
Classical::~Classical()
{
    delete actor;
}

/** |------------------------------------------hashCode--------------------------------------------------|
 *   Description: The hashCode method for the Classical class is responsible for generating the
 *   hash code for each classical movie in the movie rental shop. The unique hash code will be
 *   returned from the method for the given classical movie.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Classical::hashCode() const
{
    return Movie::hashCode();
}

/** |------------------------------------------sortKey---------------------------------------------------|
 *   Description: The sortKey method in the Classical class is responsible for creating a sort key
 *   for each classical movie in the movie rental shop, the sort key will be used to sort the movies
 *   by their genre, actor's name, and release month and year. This method calls the deriveSortKey
 *   method to create the unique sort key for each classical movie.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Classical::sortKey() const
{
    return deriveSortKey(actor->getFirstName(), actor->getLastName(), month, year);
}

/** |---------------------------------------deriveSortKey------------------------------------------------|
 *   Description: The deriveSortKey method is responsible for deriving the sort key for each
 *   classical movie in the movie rental shop. Each unique sort key is derived by concatenating
 *   the major starring actor's first and last name with the release month and year of the classical
 *   movie.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Classical::deriveSortKey(const string &actorFirstName, const string &actorLastName, int month, int year)
{
    return actorFirstName + actorLastName + to_string(month) + to_string(year);
}

/**
 * |------------------------------------------print----------------------------------------------------|
 * Description: The print method is responsible for printing the information about the classical movie.
 * |----------------------------------------------------------------------------------------------------|
 */
ostream &Classical::print(ostream &output) const
{
    output << "Classical ";
    Movie::print(output);
    return output;
}