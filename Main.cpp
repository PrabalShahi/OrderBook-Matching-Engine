#include <iostream>
#include <string>
#include <vector>
#include<chrono>
#include "OrderBookEntry.cpp"
#include "MerkelMain.cpp"
#include "CSVReader.cpp"

using namespace std;

int main()
{

    MerkelMain app{};
    app.init();
   // CSVReader reader;
   // CSVReader::readCSV("Order_Book_CPP.csv");


}