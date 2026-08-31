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

        /** initialize simulation*/
        void initialize();

private:

    /** load order book */
    void loadOrderBook();

    /** print menu options */
    void printMenuOptions();

    /** get user option */
    int getUserOption();

    /** check if user option is valid */
    bool userOptionIsValid(int userOption);

    /** process menu options */
    void proccessMenuOptions(int userOption);

    /** print help menu */
    void printHelpMenu();

    /** print exchange statistics */
    void printExchangeStatistics();

    /** enter ask order */
    void enterAsk();

    /** enter bid order */
    void enterBid();

    /** continue to next time frame */
    void continueToNextTimeFrame();

    /** current simulated time */
    std::string currentTime;

    /** order book data */
    OrderBook orderBook{"20200317.csv"};

    /** user's wallet */
    Wallet wallet{};
 
};



#endif