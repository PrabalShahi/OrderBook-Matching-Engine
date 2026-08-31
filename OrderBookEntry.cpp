#include "OrderBookEntry.h"

using namespace std;

OrderBookEntry::OrderBookEntry(double _price,
      double _amount,
      string _timestamps,
      string _product,
      OrderBookType _orderType)

      : price(_price), amount(_amount),
        timestamps(_timestamps), product(_product),
        orderType(_orderType)
{ }

OrderBookType OrderBookEntry::stringToOBE(string s)
{
    if (s == "ask")
    {
        return OrderBookType::ask;
    }
    if (s == "bid")
    {
        return OrderBookType::bid;
    }

    return OrderBookType::unknown;
}