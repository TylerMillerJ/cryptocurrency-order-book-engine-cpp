#ifndef ORDER_BOOK_ENTRY_H
#define ORDER_BOOK_ENTRY_H

#include <string>

enum class OrderBookType{bid, ask, asksale, bidsale, unknown};

class OrderBookEntry
{
    public:
        std::string timestamp;
        std::string product;
        OrderBookType type;
        double price;
        double amount;

        static bool compareByTimestamp(OrderBookEntry& entry1, OrderBookEntry& entry2);

        static bool compareByPriceAscending(OrderBookEntry& entry1, OrderBookEntry& entry2);
        static bool compareByPriceDescending(OrderBookEntry& entry1, OrderBookEntry& entry2);

        OrderBookEntry(std::string timestamp, std::string product, OrderBookType type, double price, double amount, std::string username = "dataset");
        static OrderBookType stringToOrderBookType(std::string string);
        std::string username;
};


#endif