#ifndef MERKEL_MAIN_H
#define MERKEL_MAIN_H

#include "OrderBookEntry.h"

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
        void enterOffer();
        void enterBid();
        void printWallet();
        void continueToNextTimeFrame();

        std::vector<OrderBookEntry> orders;

};



#endif