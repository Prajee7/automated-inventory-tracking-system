/**
 * |-------------------------------------------------------------|
 *  CommondProcesser.h
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The CommandProcesser Class provides functionality to process input data 
 *  text files for customers, items, and commands in the movie rental shop
 *  automated inventory tracking system. It reads the data from the input streams,
 *  parses the information, and performs the corresponding actions in the Store object.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the Store class has been properly defined and included.
*/
#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include <iostream>

#include "./Store.h"

using namespace std;

class CommandProcessor
{
public:
    // Processes the customer data from the input stream and updates the Store object.
    void processCustomers(istream &in, Store &store);

    // Processes the item data from the input stream and updates the Store object.
    void processItems(istream &in, Store &store);

    // Processes the command data from the input stream and performs the actions needed.
    void processCommands(istream &in, Store &store);

private:
    // Trims leading spaces from a string.
    void ltrim(string &str, const string &chars = "\t\n\v\f\r ")
    {
        str.erase(0, str.find_first_not_of(chars));
    }
};

#endif
