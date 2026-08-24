#include "MerkelMain.h"

#include <iostream>
#include <cstdlib>




MerkelMain::MerkelMain(){


}

void MerkelMain::initialize(){
    int input;

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

    int userOption = -1;

    do
        {
            std::cout << "Enter Your Choice: ";
            std::cin >> userOption;
            std::cout << std::endl;

        } while (!userOptionIsValid(userOption));

    std::cout << "======================" << std::endl;
    std::cout << "You Selected Option: " << userOption << std::endl;
    return userOption;
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
    std::cout << "Printing Stats" << std::endl;
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
