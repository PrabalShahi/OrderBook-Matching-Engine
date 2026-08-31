#include "OrderBookEntry.h"
#include <vector>
#include <string>


using namespace std;

class OrderBook
{
public:
    OrderBook(string filename); // R3eading CSV data file
    static    vector<string> getKnownProducts(); // return Vector of KnownProducts
    static vector<string> getOrders(OrderBookType type, string product, string timestamps); // return Vector containing information which includes type, product and timestamps

private:
    vector<OrderBookEntry> orders;

};