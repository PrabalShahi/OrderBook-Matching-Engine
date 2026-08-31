#include "OrderBook.h"
#include "CSVReader.h"
#include <iostream>

using namespace std;

OrderBook::OrderBook(string filename)
{

    orders = CSVReader::readCSV(filename);

}

vector<string> OrderBook::getKnownProducts()
{
    vector<string> knownProducts;
    return knownProducts;

}

vector<string> OrderBook::getOrders(OrderBookType OrderType, string product, string timestamps)
{
       vector<string> orders;
        return orders;

}
