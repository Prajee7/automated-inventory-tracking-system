/**
 * |-------------------------------------------------------------|
 *  Store.cpp
 *  David Schurer, Philip Vu, Prajeet Pounraj
 *  CSS 343 - Prof. Rahman
 *  1st June, 2023
 * |-------------------------------------------------------------|
 * Description:
 * The Store class represents the movie rental shop's automated inventory
 * tracking system. It manages the inventory of items, such as movies, and
 * keeps track of customers and their transaction history. The Store class
 * provides functionality to add or remove quantities of items, add customers,
 * borrow or return items, and print customer transaction history.
 * |-------------------------------------------------------------|
 * Assume:
 * The program assumes that the Item, Customer, and Stock classes have been implemented correctly.
 */
#include <vector>
#include <algorithm>

#include "../headers/Store.h"
#include "../headers/Item.h"
#include "../headers/Stock.h"

/**
 * Default constructor for Store.
 */
Store::Store()
{
}

/**
 * Destructor for Store deleting all items in inventory
 * and all customers.
 */
Store::~Store()
{
    for (auto &i : this->inventory_hotStore)
        delete i.second;
    for (auto &i : this->inventory_coldStore)
        delete i.second;

    for (auto &c : this->customers)
        delete c.second;
}

/**
 * Get the stock for an item by accessing directly
 * from the item object and storage.
 */
Stock<Item> *Store::getStock(const Item *item)
{
    return getStock(item->sortKey());
}

/**
 * Get the stock for an item hashCode.
 */
Stock<Item> *Store::getStock(const string &sortKey, bool index)
{
    string key;

    // If index is true, use the sortKey index to find the item.
    // Otherwise, use the sortKey directly to access storage.
    if (index)
    {
        if (this->inventoryIndex.find(sortKey) == this->inventoryIndex.end())
            return nullptr;
        key = this->inventoryIndex[sortKey];
    }
    else
    {
        key = sortKey;
    }

    if (!(this->inventory_hotStore.find(key) == this->inventory_hotStore.end()))
        return this->inventory_hotStore[key];

    if (!(this->inventory_coldStore.find(key) == this->inventory_coldStore.end()))
        return this->inventory_coldStore[key];

    return nullptr;
}

/**
 * Get the customer by Customer object.
 */
Customer *Store::getCustomer(const Customer *customer)
{
    if (this->customers.find(customer->hashCode()) == this->customers.end())
        return nullptr;

    return this->customers[customer->hashCode()];
}

/**
 * Get Customer by customer hashCode.
 */
Customer *Store::getCustomer(const string &key)
{
    if (this->customers.find(key) == this->customers.end())
        return nullptr;

    return this->customers[key];
}

/**
 * Move a stock from cold storage to hot storage.
 *
 * The key must be a valid item in cold storage.
 */
void Store::cacheStock(const string &key)
{
    Stock<Item> *stock = getStock(key, false);

    if (stock == nullptr)
        throw invalid_argument("Item not found");

    this->inventory_coldStore.erase(key);
    this->inventory_hotStore[key] = stock;
}

/**
 * Add an item to the inventory by creating a new stock and storing it
 * in cold storage.
 *
 * Will not re-add stock if it already exists. Will add a sort key.
 */
void Store::addStock(Item *item)
{
    string hashCode = item->hashCode();

    // Item has already been added.
    if (this->inventoryIndex.find(item->sortKey()) != this->inventoryIndex.end())
        return;

    this->inventoryIndex[item->sortKey()] = hashCode;

    // If the item is already in the inventory, don't add it again.
    if ((this->inventory_coldStore.find(hashCode) == this->inventory_coldStore.end() && this->inventory_hotStore.find(hashCode) == this->inventory_hotStore.end()))
    {
        this->inventory_coldStore[hashCode] = new Stock<Item>(item);
    }
    else
    {
        delete item;
    }
}

/**
 * Add a quantity of an item to the inventory. If it doesn't exist,
 * create a new stock and store it in cold storage.
 */
void Store::addQuantity(Item *item, int amount)
{
    if (amount <= 0)
        throw invalid_argument("Must add positive amount");

    string hashCode = item->hashCode();

    // Will attempt to add the stock, will not add the stock if it is already present.
    // Needs to get called to add the sort key. Will discard the item if it already exists.
    addStock(item);

    Stock<Item> *stock = getStock(hashCode, false);

    stock->addInventory(amount);
}

/**
 * Remove a quantity of an item from the inventory.
 */
void Store::removeQuantity(Item *item, int amount)
{
    Stock<Item> *stock = getStock(item);

    if (stock == nullptr)
        throw invalid_argument("Item not found");

    stock->removeInventory(amount);
}

/**
 * Add a customer to the store by storing it in the customers map using its
 * hashCode as the key.
 */
void Store::addCustomer(Customer *customer)
{
    this->customers[customer->hashCode()] = customer;
}

/**
 * Borrow an item from the store. If the item is not found, throw an exception.
 * If the customer is not found, throw an exception. If there is not enough
 * inventory, throw an exception. Otherwise, borrow the item and add the
 * transaction to the customer.
 *
 * If the stock has been interacted with more than CACHE_STOCK_THRESHOLD,
 * move it from cold storage to hot storage.
 *
 * If the limit is greater than 0, check if the customer has borrowed too many
 * items from this stock. If so, throw an exception.
 */
void Store::borrowItem(string item, string customerKey, int amount, string transaction, int limit)
{
    Stock<Item> *stock = getStock(item);
    Customer *customer = getCustomer(customerKey);

    if (customer == nullptr)
        throw invalid_argument("Customer not found: " + customerKey);

    customer->addTransaction(transaction);

    if (stock == nullptr)
        throw invalid_argument("Item not found: " + item);

    if (stock->getInventory() < amount)
        throw invalid_argument("Not enough inventory");

    if (limit > 0 && stock->getBorrowed(customerKey) >= limit)
        throw invalid_argument(customer->getFullName() + " has borrowed too many items from this stock (" + to_string(stock->getBorrowed(customerKey)) + "/" + to_string(limit) + ")");

    stock->borrowInventory(customerKey, amount);

    if (stock->getInteractionCount() > Store::CACHE_STOCK_THRESHOLD)
        cacheStock(stock->hashCode());
}

/**
 * Return an item to the store. If the item is not found, throw an exception.
 * If the customer is not found, throw an exception. Otherwise, return the
 * item and add the transaction to the customer.
 *
 * If the stock has been interacted with more than CACHE_STOCK_THRESHOLD,
 * move it from cold storage to hot storage.
 */
void Store::returnItem(string item, string customerKey, int amount, string transaction)
{
    Stock<Item> *stock = getStock(item);
    Customer *customer = getCustomer(customerKey);

    if (customer == nullptr)
        throw invalid_argument("Customer not found");

    customer->addTransaction(transaction);

    if (stock == nullptr)
        throw invalid_argument("Item not found");

    stock->returnInventory(customer->hashCode(), amount);

    if (stock->getInteractionCount() > Store::CACHE_STOCK_THRESHOLD)
        cacheStock(stock->hashCode());
}

/**
 * Print a customer's history. If the customer is not found, throw an exception.
 */
void Store::printCustomerHistory(string customerKey)
{
    Customer *customer = getCustomer(customerKey);

    if (customer == nullptr)
        throw invalid_argument("Customer not found");

    customer->printTransactionHistory();
}

/**
 * Print the inventory of the store. This is done by printing the inventory
 * of the hot store, then the cold store.
 */
ostream &operator<<(ostream &out, const Store &store)
{
    out << "Inventory:" << endl;

    vector<Stock<Item> *> items;

    for (auto &i : store.inventory_hotStore)
        items.push_back(i.second);
    for (auto &i : store.inventory_coldStore)
        items.push_back(i.second);

    // Sort the items by the priority on the item
    sort(items.begin(), items.end(), [](Stock<Item> *a, Stock<Item> *b)
         { return a->getItem().getPriority() < b->getItem().getPriority(); });

    for (auto &i : items)
        out << *i << endl;

    return out;
}
