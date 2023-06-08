#include "./cpp/CommandProcessor.cpp"

#include <iostream>
#include <istream>

using namespace std;

int main()
{
    ifstream customers("data4customers.txt");
    ifstream movies("data4movies.txt");
    ifstream commands("data4commands.txt");

    CommandProcessor cm;
    Store *store = new Store();

    cm.processCustomers(customers, *store);
    cm.processItems(movies, *store);
    cm.processCommands(commands, *store);

    delete store;

    return 0;
}