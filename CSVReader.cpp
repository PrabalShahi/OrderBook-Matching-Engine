#include "CSVReader.h"
#include "OrderBookEntry.h"
#include<fstream>
#include<iostream>

using namespace std;

CSVReader::CSVReader()
= default;

vector<string> CSVReader::tokenise(string csvLine, char separator)
{
    vector<string> tokens;
    signed int end;
    string token;

    signed int start = csvLine.find_first_not_of(separator, 0);

    do
    {
        end = csvLine.find_first_of(separator, start);

        if (start == csvLine.length() || start == end) break;

        if (end >= 0)
        {
            token = csvLine.substr(start, end - start);
        }
        else
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }

        tokens.push_back(token);
        start = end + 1;

    } while (end > 0);
    return tokens;
}

vector<OrderBookEntry> CSVReader::readCSV(string csvFilename)
{
vector<OrderBookEntry> entries;
    ifstream CsvFile{csvFilename};
    string line;
if (CsvFile.is_open())
{

    // auto start = chrono::high_resolution_clock::now();

    cout<<"File has been Opened"<<endl;
    while (getline(CsvFile, line))
    {
        cout<<"Read Line - "<<line<<endl;
        OrderBookEntry OBE = StringsToOBE(tokenise(line, ','));
       // continue;
        entries.push_back(OBE);

    }
    // cout<<"Entry Size: "<<entries.size()<<endl;
    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // cout<<"Execution Time: "<<duration.count()<<" microseconds"<<"\n";

}
else
{
    cout<<"File could not open"<<endl;
}


    return entries;

}

 OrderBookEntry CSVReader::StringsToOBE(vector<string> tokens)
{
    double price;
    double amount;

    if (tokens.size() != 5)
    {
        cout<<"Bad data"<<endl;
        throw exception{};
    }
    try
    {
        price = stod(tokens[3]);
        amount = stod(tokens[4]);
    } catch (const invalid_argument& e)
    {
        cout<<"This line has a problem"<<endl;
       throw;

    }

    OrderBookEntry OBE{price, amount, tokens[0], tokens[1],OrderBookEntry::stringToOBE(tokens[2])};
    return OBE;
}