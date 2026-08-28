#ifndef MERKEL_MAIN_H
#define MERKEL_MAIN_H

#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>

class MerkelMain{
    public:
        MerkelMain();
        void initialize();

    private:
        void loadOrderBook();
        void printMenuOptions();
        int getUserOption();
        bool userOptionIsValid(int userOption);
        void proccessMenuOptions(int userOption);
        void printHelpMenu();
        void printExchangeStatistics();
        void enterAsk();
        void enterBid();
        void printWallet();
        void continueToNextTimeFrame();

        std::string currentTime;
        OrderBook orderBook{"20200317.csv"};
        Wallet wallet{};    
};



#endif