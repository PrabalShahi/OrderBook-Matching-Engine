#pragma once
#include<string>
#pragma once

using namespace std;

enum class OrderBookType{bid, ask, unknown};

class OrderBookEntry
{
public:

    double price;
    double amount;
    string timestamps;
    string product;
    OrderBookType orderType;

    OrderBookEntry(double _price,
        double _amount,
        string _timestamps,
        string _product,
        OrderBookType _orderType);

   static OrderBookType stringToOBE(string s);

};