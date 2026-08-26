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

    int input;
    currentTime = orderBook.getEarliestTime();

    while(true)
    {
        printMenuOptions();
        input = getUserOption();
        proccessMenuOptions(input);
    }

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

    // 3. Make Ask - (An Ask to sell an asset/item)
    std::cout << "3. Make An Ask" << std::endl;

    // 4. Make Bid - (A bid to purchase an asset/item)
    std::cout << "4. Make A Bid" << std::endl;

    // 5. Print Wallet - (Where assets are stored)
    std::cout << "5. Open Wallet" << std::endl;

    // 6. Continue
    std::cout << "6. Continue" << std::endl;

    std::cout << std::endl;

    std::cout << "Current Time Is " << currentTime << std::endl;

}

int MerkelMain::getUserOption()
{
    std::cout << "======================" << std::endl;

    std::string userOptionInput;
    int userOpt;

    while (true) 
    {
        std::cout << "Enter Your Choice: ";

        std::getline(std::cin, userOptionInput);
        std::cout << std::endl;

        try 
        {
            userOpt = std::stoi(userOptionInput);
        }
        catch(...) 
        {
            std::cerr << "Invalid Option: Cannot Convert Input To Integer" << std::endl;
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
        enterAsk();
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

    for (std::string const& product : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << product << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::bid, product, currentTime);
        std::cout << "Bids Seen " << entries.size() << std::endl;
        std::cout << "Max Bid " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min Bid " << OrderBook::getLowPrice(entries) << std::endl;

    }
  
}

void MerkelMain::enterAsk()
{
    std::cout << "Make an Ask - Format: Product, Price, Amount" << std::endl;
    std::cout << "eg: BTC/ETH, 200, 0.5" << std::endl;
    std::cout << "Product, Price, Amount: ";

    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');

    if (tokens.size() != 3)
    {
        std::cerr << "Error: Does not have 3 tokens: " << input << std::endl;
    } else 
    {
        try
        {
            OrderBookEntry entry = CSVReader::stringToOrderBookEntry(currentTime, tokens[0], OrderBookType::ask, tokens[1], tokens[2]);
            orderBook.insertOrder(entry);
            std::cout << "Your Ask Has Been Submitted: " << entry.timestamp << ", " << entry.product << ", ask, " << entry.price << ", " << entry.amount << std::endl;
        
        }
        catch (const std::exception& exception)
        {
            std::cerr << "enterAsk(): Entry Failed" << std::endl;
        }
    }

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
    std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales Made: " << sales.size() << std::endl;
    for (OrderBookEntry sale : sales)
    {
        std::cout << "Sale Price: " << sale.price << std::endl;
        std::cout << "Sale Amount: " << sale.amount << std::endl;


    }
    currentTime = orderBook.getNextTime(currentTime);
}
