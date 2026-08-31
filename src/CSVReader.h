#ifndef CSV_READER_H
#define CSV_READER_H

#include "OrderBookEntry.h"

#include <vector>
#include <string>

class CSVReader
{
    public:
        CSVReader();

        /** reads in csv File to vector of OrderBookEntry's*/
        static std::vector<OrderBookEntry> readCSV(std::string csvFile);

        /** tokenises string input to token vector at seperator char*/
        static std::vector<std::string> tokenise(std::string csvLine, char seperator);

        /** string inputs used to make an OrderBookEntry*/
        static OrderBookEntry stringToOrderBookEntry(std::string timestamp, std::string product, OrderBookType type, std::string priceString, std::string amountString);

    private:
        /** vector of strings from tokenise function used to make OrderBookEntry*/
        static OrderBookEntry stringToOrderBookEntry(std::vector<std::string> strings);

};


#endif