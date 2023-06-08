/**
 * |-------------------------------------------------------------|
 *  Customer.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The Customer class provides functionality to represent a customer in the
 *  movie rental shop automated inventory tracking system. It inherits from the
 *  Person class and stores information about the customer, such as their ID,
 *  first name, last name, and transaction history.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the Person class has been properly defined.
 */
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>

#include "./Person.h"

using namespace std;

class Customer : public Person
{
public:
    // Constructor, initializes a Customer object with the given ID, first name, and last name.
    Customer(string id, string firstName, string lastName);

    // Prints the transaction history of the customer.
    void printTransactionHistory();

    // Adds a transaction to the customer's transaction history.
    void addTransaction(string transaction);

    // returns customer ID
    string getId() const;

    // Generates and returns the unique hash code for the customer.
    string hashCode() const;

    // Static method that calculates and returns the unique hash code for a customer.
    static string deriveHashCode(const string &id);

private:
    vector<string> transactions; // Transaction history of the customer
    string id;                   // Customer ID
};

#endif
