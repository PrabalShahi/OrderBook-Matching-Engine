#pragma once
#include<vector>
#include<string>
#include "OrderBookEntry.h"


using namespace std;

class CSVReader
{
private:
    static vector<string> tokenise(string csvLine, char separator);

public:
    CSVReader();
    static vector<OrderBookEntry> readCSV(string csvFile);
    static OrderBookEntry StringsToOBE(vector<string> strings);

};