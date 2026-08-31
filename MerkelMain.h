// #pragma once //To stop including Header files Multiple Times

#include<vector>
#include "OrderBook.h"

class MerkelMain
{
public:
    MerkelMain();
    // Call this to start the Sim.
    void init();

private:
    void LoadOrderBook();
    void printMenu();
    void InvalidChoice();
    void printHelp();
    void printMarketStats();
    void printBid();
    void printOffer();
    void printWallet();
    void TimeFrame();
    int  getUserOption();
    void processUserOption(int useroption);

   vector<OrderBookEntry> orders;// Object Scope
   // OrderBook orderBook{"Order_Book_CPP.csv"};

};
