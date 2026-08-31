#ifndef WALLET_H
#define WALLET_H

#include "OrderBookEntry.h"

#include <string>
#include <map>
#include <vector>


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
        bool canFulfillOrder(const OrderBookEntry& order);
        
        /** processes sale input*/
        void processSale(OrderBookEntry& sale);

        /** print the currencies and balances in the wallet */
        void printWallet();

        /** deposit funds into the wallet */
        void makeDeposit();
        
        /** checks supported currencies */
        static bool isSupportedCurrency(const std::string& currency);
        
        /** prints all supported currencies */
        static void printSupportedCurrencies();


    private:
        /** currencies and their corresponding balances */
        std::map<std::string, double> currencies;
        
        /** supported currencies on this platform*/
        static const std::vector<std::string> supportedCurrencies;

};




#endif