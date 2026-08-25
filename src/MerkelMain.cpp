#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>

MerkelMain::MerkelMain(){

}

void MerkelMain::initialize(){

    loadOrderBook();

    int input;

    while(true)
    {
        printMenuOptions();
        input = getUserOption();
        proccessMenuOptions(input);
    }

}

void MerkelMain::loadOrderBook(){
       orders = CSVReader::readCSV("20200317.csv");
}



void MerkelMain::printMenuOptions()
{
    std::cout<< std::endl;
    std::cout << "Enter One Of The Following Menu Options:" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    // 0. Exit
    std::cout << "0. Exit Program" << std::endl;

    // 1. Print Help
    std::cout << "1. Print Help Menu" << std::endl;

    // 2. Print Exchange Stats
    std::cout << "2. Print Exchange Statistics" << std::endl;

    // 3. Make Offer - (An offer to sell an asset/item)
    std::cout << "3. Make An Offer" << std::endl;

    // 4. Make Bid - (A bid to purchase an asset/item)
    std::cout << "4. Make A Bid" << std::endl;

    // 5. Print Wallet - (Where assets are stored)
    std::cout << "5. Open Wallet" << std::endl;

    // 6. Continue
    std::cout << "6. Continue" << std::endl;

}

int MerkelMain::getUserOption()
{
    std::cout << "======================" << std::endl;

    std::string userOptionInput;
    int userOpt;

    while (true) 
    {
        std::cout << "Enter Your Choice: ";
        std::cin >> userOptionInput;
        std::cout << std::endl;

        try 
        {
            userOpt = std::stoi(userOptionInput);
        }
        catch(...) 
        {
            std::cerr << "Invalid Option: Please enter 0-6" << std::endl;
            continue;
        }
        
        if (userOptionIsValid(userOpt)){
            std::cout << "======================" << std::endl;
            std::cout << "You Selected Option: " << userOpt << std::endl;
            return userOpt;
        } else {
            std::cerr << "Invalid Option: Please enter 0-6" << std::endl;
            continue;        
        }
    }
}




//error handling //validateChoice()
bool MerkelMain::userOptionIsValid(int userOption)
{
    if (userOption <= 6  && userOption >= 0)
    {
        return true;
    } else
    {
        std::cerr << userOption << " Is an Invalid Choice. Please enter a value between 1-6." << std::endl;
        printMenuOptions();
        return false;
    }

}

void MerkelMain::proccessMenuOptions(int userOption)
{
    switch (userOption)
    {
    case 0:
        std::exit(0);
        break;

    case 1:
        printHelpMenu();
        break;

    case 2:
        printExchangeStatistics();
        break;

    case 3:
        enterOffer();
        break;

    case 4:
        enterBid();
        break;

    case 5:
        printWallet();
        break;

    case 6:
        continueToNextTimeFrame();
        break;

    default:
        std::cerr << "Case Statement Error" << std::endl;
    }
}

void MerkelMain::printHelpMenu()
{
    std::cout << "1. Help Menu" << std::endl;
}

void MerkelMain::printExchangeStatistics()
{
    long unsigned int asks = 0;
    long unsigned int bids = 0;

    for (const OrderBookEntry& entry : orders)
    {
        if (entry.type == OrderBookType::ask)
        {
            asks++;
        } else if (entry.type == OrderBookType::bid)
        {
            bids++;
        }
    }

    std::cout << "Order Book Contains " << orders.size() << " Orders" <<  std::endl;
    std::cout << "Order Book Contains " << bids << " Bids" <<  std::endl;
    std::cout << "Order Book Contains " << asks << " Asks" <<  std::endl;

}

void MerkelMain::enterOffer()
{
    std::cout << "Making an Offer" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Making a bid" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Opening Wallet..." << std::endl;
}

void MerkelMain::continueToNextTimeFrame()
{
    std::cout << "Continuing forward in time" << std::endl;
}
