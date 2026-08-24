#ifndef MERKEL_MAIN_H
#define MERKEL_MAIN_H

#include <iostream>
#include <cstdlib>


class MerkelMain{
    public:
        MerkelMain();
        void initialize();
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

};



#endif