#ifndef CSV_READER_H
#define CSV_READER_H

#include "OrderBookEntry.h"

#include <vector>
#include <string>

class CSVReader
{
    public:
        CSVReader();

        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
        static std::vector<std::string> tokenise(std::string csvLine, char seperator);
        static OrderBookEntry stringToOrderBookEntry(std::string timestamp, std::string product, OrderBookType type, std::string priceString, std::string amountString);

    private:
        static OrderBookEntry stringToOrderBookEntry(std::vector<std::string> strings);

};


#endif