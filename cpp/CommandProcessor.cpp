/**
 * |-------------------------------------------------------------|
 *  CommandProcessor.cpp
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 *  Description:
 *  The CommandProcessor Class provides functionality to process input data
 *  text files for customers, items, and commands in the movie rental shop
 *  automated inventory tracking system. It reads the data from the input streams,
 *  parses the information, and performs the corresponding actions in the Store object.
 * |-------------------------------------------------------------|
 *  Assume:
 *  The program assumes that the Store class has been properly defined and included.
 */
#include "../headers/CommandProcesser.h"

#include "../cpp/Movie.cpp"
#include "../cpp/Person.cpp"
#include "../cpp/Customer.cpp"
#include "../cpp/Classical.cpp"
#include "../cpp/Store.cpp"
#include "../cpp/Stock.cpp"
#include "../cpp/Drama.cpp"
#include "../cpp/Comedy.cpp"

#include <sstream>

/** |--------------------------------------processCustomers----------------------------------------------|
 *   Description: The processCustomers method for the CommandProcessor class is responsible for
 *   reading the data4customers.txt text file, which contains the customer information, and processes
 *   the data of each customer in the movie rental shop. It reads lines from the input stream object 'in'
 *   and uses a stringstream object 'ss' to read in the values for the customer's id, first, and last name,
 *   which is then used to create a new customer object by calling the addCustomer method of the store object
 *   that is passed in.
 *  |----------------------------------------------------------------------------------------------------|
 */
void CommandProcessor::processCustomers(istream &in, Store &store)
{
    string line;

    while (getline(in, line))
    {
        stringstream ss(line);
        string id, first, last;

        ss >> id >> first >> last;

        store.addCustomer(new Customer(id, first, last));
    }
}

/** |----------------------------------------processItems------------------------------------------------|
 *   Description: The processItems method for the CommandProcessor class is responsible for reading
 *   the data4movies.txt text file, which contains the information about each movie. This method processes
 *   the components of each movie from the text file, such as the movie's type, quantity,
 *   director name, title, and other data. If the movie's type is "D" it is stored as a Drama movie, if it
 *   is of type "F", it is stored as a Comedy movie, and if it is of type "C", it is stored as a classical
 *   movie. If the movie type is invalid, an error message is printed out to the output screen.
 *  |----------------------------------------------------------------------------------------------------|
 */
void CommandProcessor::processItems(istream &in, Store &store)
{
    string line;

    while (getline(in, line))
    {
        stringstream ss(line);
        string temp, type, directorFirstName, directorLastName, title, data;
        int amount;

        getline(ss, type, ',');

        getline(ss, temp, ',');
        amount = stoi(temp);

        getline(ss, temp, ',');
        stringstream director(temp);
        director >> directorFirstName >> directorLastName;

        getline(ss, title, ','), ltrim(title);

        getline(ss, data);

        if (type == "D")
        {
            int year = stoi(data);
            store.addQuantity(new Drama(title, new Person(directorFirstName, directorLastName), year), amount);
        }
        else if (type == "F")
        {
            int year = stoi(data);
            store.addQuantity(new Comedy(title, new Person(directorFirstName, directorLastName), year), amount);
        }
        else if (type == "C")
        {
            stringstream actorAndRelease(data);
            string actorFirstName, actorLastName;

            int month, year;

            actorAndRelease >> actorFirstName >> actorLastName;
            actorAndRelease >> month >> year;

            store.addQuantity(new Classical(title, new Person(directorFirstName, directorLastName), year, new Person(actorFirstName, actorLastName), month), amount);
        }
        else
        {
            cout << "Invalid item type: " << type << endl
                 << endl;
        }
    }
}

/** |---------------------------------------processCommands----------------------------------------------|
 *   Description: The processCommands method for the CommandProcessor class is responsible for reading
 *   the data4commands.txt text file, which contains different commands that the method will process
 *   such as Borrow, Return, Inventory, and History. The processCommands method calls different methods
 *   of the Store class on the Store object that is passed in through the method to execute different
 *   actions in the system. The processCommands method also handles bad input and will display error
 *   messages for invalid movie genres, actions, or item types that are read in through the text file.
 *  |----------------------------------------------------------------------------------------------------|
 */
void CommandProcessor::processCommands(istream &in, Store &store)
{
    string line;

    while (getline(in, line))
    {
        stringstream ss(line);
        char action;
        ss >> action;

        if (action == 'I')
        {
            cout << store << endl;
        }
        else if (action == 'H')
        {
            string userId;
            ss >> userId;

            try
            {
                store.printCustomerHistory(userId);
                cout << endl;
            }
            catch (const exception &e)
            {
                cout << e.what() << endl
                     << endl;
            }
        }
        else if (action == 'R' || action == 'B')
        {
            string userId, itemType, temp;

            ss >> userId >> itemType;

            if (itemType == "D")
            {
                string movieGenre, movieKey;
                ss >> movieGenre;

                if (movieGenre == "F")
                {
                    string title;
                    int year;
                    getline(ss, title, ','), ltrim(title);
                    ss >> year;
                    movieKey = Comedy::deriveSortKey(title, year);
                }
                else if (movieGenre == "C")
                {
                    string actorFirstName, actorLastName;
                    int month, year;

                    ss >> month >> year >> actorFirstName >> actorLastName;

                    movieKey = Classical::deriveSortKey(actorFirstName, actorLastName, month, year);
                }
                else if (movieGenre == "D")
                {
                    string directorFirstName, directorLastName, title;

                    getline(ss, temp, ',');
                    stringstream director(temp);
                    director >> directorFirstName >> directorLastName;

                    getline(ss, title, ','), ltrim(title);

                    movieKey = Drama::deriveSortKey(directorFirstName, directorLastName, title);
                }
                else
                {
                    cout << "Invalid movie genre: " << movieGenre << endl
                         << endl;
                    continue;
                }

                try
                {
                    if (action == 'R')
                    {
                        store.returnItem(movieKey, userId, 1, line);
                    }
                    else if (action == 'B')
                    {
                        store.borrowItem(movieKey, userId, 1, line, 1);
                    }
                    else
                    {
                        cout << "Invalid action: " << action << endl
                             << endl;
                    }
                }
                catch (const exception &e)
                {
                    cout << e.what() << endl
                         << endl;
                }
            }
            else
            {
                cout << "Invalid item type: " << itemType << endl
                     << endl;
            }
        }
    }
}
