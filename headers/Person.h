/**
 * |-------------------------------------------------------------|
 *  Person.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 * Description:
 * The Person class represents a person in the movie rental shop's automated
 * inventory tracking system. It inherits from the HashObject class and provides 
 * functionality to store the first name and last name of a person. Derived classes
 * can be created from this base class to represent specific types of persons, such 
 * as customers or directors.
 * |-------------------------------------------------------------|
 * Assume:
 * The program assumes that the HashObject class have been properly implemented.
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "./HashObject.h"

using namespace std;

// Person class is the child class of HashObject.
class Person : HashObject
{
public:
    // Constructor assigns the Person's first and last name through the values from the parameters.
    Person(string, string);

    // returns the first name of the person.
    string getFirstName() const;

    // returns the last name of the person.
    string getLastName() const;

    // returns the full name of the person.
    string getFullName() const;

    // Generates and returns the unique hash code for a Person.
    virtual string hashCode() const;

protected:
    string firstName; // the first name of the person.
    string lastName; // the last name of the person.
};

#endif
