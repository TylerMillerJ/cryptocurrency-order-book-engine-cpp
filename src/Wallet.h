#ifndef WALLET_H
#define WALLET_H

#include "OrderBookEntry.h"

#include <string>
#include <map>

class Wallet
{
    public:
        Wallet();

        /** check if the wallet contains this much currency or more*/
        bool containsCurrency(std::string type, double amount);
        
        /** insert currency to the wallet */
        void insertCurrency(std::string type, double amount);
        
        /** remove currency to the wallet */
        bool removeCurrency(std::string type, double amount);
        
        /** generate string representation of the wallet*/
        std::string toString();

        /** checks if the wallet can fullfill this ask/bid*/
        bool canFullfillOrder(OrderBookEntry order);
        
        /** processes sale input*/
        void processSale(OrderBookEntry& sale);

        /** print the currencies and balances in the wallet */
        void printWallet();

        /** deposit funds into the wallet */
        void makeDeposit();

    private:
        /** currencies and their corresponding balances */
        std::map<std::string, double> currencies;

};




#endif