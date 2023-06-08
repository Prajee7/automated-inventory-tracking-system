/**
 * |-------------------------------------------------------------|
 *  Customer.cpp
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
#include "../headers/Customer.h"

/** |----------------------------------------Constructor-------------------------------------------------|
 *   Description: The Customer class constructor is responsible for initializing Customer objects with
 *   their specified data members such as the customer's ID, first name, and last name. The customer's
 *   first and last name is initialized by calling the Person class constructor as the Customer class
 *   inherits from the Person class.
 *  |----------------------------------------------------------------------------------------------------|
*/
Customer::Customer(string id, string firstName, string lastName) : Person(firstName, lastName), id(id)
{
}

/** |-------------------------------------------getID----------------------------------------------------|
 *   Description: The getID method for the Customer class is a getter that returns the id of the
 *   specified customer in the movie rental shop. The customer ID is returned as a string.
 *  |----------------------------------------------------------------------------------------------------|
*/
string Customer::getId() const
{
    return this->id;
}

/** |----------------------------------printTransactionHistory-------------------------------------------|
 *   Description: The printTransactionHistory method for the Customer class is responsible for
 *   printing out the transaction history of a given customer in the movie rental shop. It displays
 *   the customer's name and then iterates over the transactions vector to print out all of the customer's
 *   transactions.
 *  |----------------------------------------------------------------------------------------------------|
*/
void Customer::printTransactionHistory()
{
    cout << "Transaction history for " << this->getFullName() << ":" << endl;

    if (this->transactions.size() == 0)
    {
        cout << "No transactions" << endl;
    }
    else
    {
        for (int i = 0; i < this->transactions.size(); i++)
        {
            cout << this->transactions[i] << endl;
        }
    }
}

/** |--------------------------------------addTransaction------------------------------------------------|
 *   Description: The addTransaction method of the Customer class is used to add a new transaction
 *   to a customer's transaction history. The transaction is passed in through the method as a string
 *   and is added to the transactions vector by using the push_back method.
 *  |----------------------------------------------------------------------------------------------------|
*/
void Customer::addTransaction(string transaction)
{
    this->transactions.push_back(transaction);
}

/** |-----------------------------------------hashCode---------------------------------------------------|
 *   Description: The hashCode method for the Customer class returns the unique hash code for the given
 *   customer in the movie rental shop based on the customer's ID. Their hash code is returned from
 *   the method as a string.
 *  |----------------------------------------------------------------------------------------------------|
*/
string Customer::hashCode() const
{
    return deriveHashCode(this->id);
}

/** |--------------------------------------deriveHashCode------------------------------------------------|
 *   Description: The deriveHashCode method for the Customer class is responsible for deriving the
 *   hash code for each customer in the movie rental shop. The given ID for the customer is used
 *   as their hash code and it is returned from the method.
 *  |----------------------------------------------------------------------------------------------------|
*/
string Customer::deriveHashCode(const string &id)
{
    return id;
}
