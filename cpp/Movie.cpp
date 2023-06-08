/**
 * |-------------------------------------------------------------|
 *  Movie.cpp
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
#include "../headers/Movie.h"
#include "../headers/Person.h"

#include <sstream>

/** |----------------------------------------Constructor-------------------------------------------------|
 *   Description: The Movie class constructor is responsible for initializing Movie objects,
 *   which represent each movie in the movie rental shop. Each Movie object is initialized with a title,
 *   represented by a string variable, a director that is represented by a Person pointer, and a release
 *   year, which is represented by an integer variable.
 *  |----------------------------------------------------------------------------------------------------|
 */
Movie::Movie(string title, Person *director, int year, int priority) : Item(priority)
{
    this->title = title;
    this->director = director;
    this->year = year;
}

/** |----------------------------------------Destructor--------------------------------------------------|
 *   Description: The Movie class destrutor is responsible for deallocating memory that was allocated
 *   by a Movie object. This is done by deleting the Person pointer director, which was dynamically
 *   allocated. This method ensures that memory that was allocated within the Movie class is properly
 *   deallocated to prevent memory leaks.
 *  |----------------------------------------------------------------------------------------------------|
 */
Movie::~Movie()
{
    delete director;
}

/** |-----------------------------------------getTitle---------------------------------------------------|
 *   Description: The getTitle method for the Movie class is a getter method that is responsible for
 *   retrieving the title of the movie. It returns the given movie's title as a string.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Movie::getTitle() const
{
    return this->title;
}

/** |----------------------------------------getDirector-------------------------------------------------|
 *   Description: The getDirector method for the Movie class is a getter method that is responsible for
 *   retrieving the director of the movie. It calls the getFullName() method to retrieve the director's
 *   first and last name and returns it as a string.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Movie::getDirector() const
{
    return this->director->getFullName();
}

/** |------------------------------------------getYear---------------------------------------------------|
 *   Description: The getYear method for the Movie class is a getter method that is responsible for
 *   retrieving the release year of a given movie in the movie rental shop.
 *  |----------------------------------------------------------------------------------------------------|
 */
int Movie::getYear() const
{
    return this->year;
}

/** |------------------------------------------hashCode--------------------------------------------------|
 *   Description: The hashCode method for the Movie class is responsible for creating a unique hash
 *   code for each movie in the movie rental shop. The hash code for each Movie object is created by
 *   using a stringstream object 'ss' to concatenate the title, director's name, and the release year
 *   of the movie.
 *  |----------------------------------------------------------------------------------------------------|
 */
string Movie::hashCode() const
{
    stringstream ss;
    ss << this->title << " " << this->director->getFullName() << " " << this->year;
    return ss.str();
}

/** |-------------------------------------------print----------------------------------------------------|
 *   Description: The print method for the Movie class is responsible for printing out the movie details
 *   to the output stream. It prints out the movie's title, release year, and director's first and last
 *   name to the output stream.
 *  |----------------------------------------------------------------------------------------------------|
 */
ostream &Movie::print(ostream &output) const
{
    output << "Movie: " << this->title << " (" << this->year << ") by " << this->director->getFullName();
    return output;
}
