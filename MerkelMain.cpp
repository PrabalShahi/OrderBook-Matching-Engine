#include<iostream>
#include<vector>
#include "MerkelMain.h"
#include "CSVReader.h"
#include "OrderBookEntry.h"

using namespace std;

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
  int input;

    LoadOrderBook();
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
        // if (input == 2)
        // {
        //     printMarketStats();
        // }
    }
}

void MerkelMain::LoadOrderBook()
{
     orders =  CSVReader::readCSV("Order_Book_CPP.csv");


//    vector<OrderBookEntry> orders;
    // Vector of Object
    // We can use "emplace_back" instead of making a seperate object and copying it into the Vector
    // orders.push_back(OrderBookEntry{10000, 0.02, "BTC/USDT", OrderBookType::bid});
    //
    // orders.push_back(OrderBookEntry{20000, 0.04,
    //                     "2020/03/17 17:01:24.884492", OrderBookType::bid});

}


void MerkelMain::printMenu()
{
    cout<<"=======Menu======="<<::endl;
    // 1. print help
    cout << "1. Print Help"<< ::endl;
    // 2. print exchange stats
    cout << "2. Print exchange stats"<< ::endl;
    // 3. make an offer
    cout << "3. Make an offer"<< ::endl;
    // 4. make a bid
    cout << "4. Make a Bid"<< ::endl;
    // 5. print wallet
    cout << "5. Print my Wallet"<< ::endl;
    // 6. continue
    cout <<"6. Continue"<< ::endl;

    cout<<"==============="<< ::endl;
}

void MerkelMain::InvalidChoice()
{
    cout<< "Invalid choice. Choose 1-6"<< ::endl;

}

void MerkelMain::printHelp()
{
    cout<< "Help - Your aim is to make money. Analyze the market and bids and offers."<< endl;
}

void MerkelMain::printMarketStats()
{
    cout<< "OrderBook contains: "<<orders.size()<<" "<<"entries"<< endl;
    unsigned int bids = 0;
    unsigned int asks = 0;

    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == OrderBookType::bid)
        {
            bids++;
        }
        if (e.orderType == OrderBookType::ask)
        {
            asks++;
        }
    }

    cout<<"Bids: "<<bids<<endl;
    cout<<"Asks: "<<asks<<endl;
}

void MerkelMain::printBid()
{
    cout<< "Make an offer - Enter the amount"<< endl;

}

void MerkelMain::printOffer()
{
    cout<< "Make a Offer - Enter the amount"<< endl;
}

void MerkelMain::printWallet()
{
    cout<< "Your Wallet is Empty."<< endl;
}

void MerkelMain::TimeFrame()
{
    cout<< "Going to next time frame."<< endl;
}

int MerkelMain::getUserOption()
{
    int useroption;
    cout<<"Type in 1-6"<< endl;
    cin>>useroption;
    if (useroption >= 1 && useroption <= 6)
    {
        cout<<"You entered: "<<useroption<<endl;
        return useroption;

    } else { cout<<"Invalid Input"<<"\n"; }
    return useroption;
}

void MerkelMain::processUserOption(int useroption)
{
    switch (useroption)
    {
    case 1:
        {
            printHelp();
            break;
        }

    case 2:
        {
            printMarketStats();
            break;
        }

    case 3:
        {
            printBid();
            break;
        }

    case 4:
        {
            printOffer();
            break;
        }

    case 5:
        {
            printWallet();
            break;
        }

    case 6:
        {
            TimeFrame();
            break;
        }
    }

}