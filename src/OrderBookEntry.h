#ifndef ORDER_BOOK_ENTRY_H
#define ORDER_BOOK_ENTRY_H

#include <string>

enum class OrderBookType{bid, ask, unknown};

class OrderBookEntry
{
    private:

    public:
        std::string timestamp;
        std::string product;
        OrderBookType type;
        double price;
        double amount;

        static bool compareByTimestamp(OrderBookEntry& entry1, OrderBookEntry& entry2);

        OrderBookEntry(std::string timestamp, std::string product, OrderBookType type, double price, double amount);
        static OrderBookType stringToOrderBookType(std::string string);
};


#endif