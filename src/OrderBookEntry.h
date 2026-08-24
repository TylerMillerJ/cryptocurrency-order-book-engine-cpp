#ifndef ORDER_BOOK_ENTRY_H
#define ORDER_BOOK_ENTRY_H

#include <string>

enum class OrderBookType{bid, ask};

class OrderBookEntry
{
    private:
        std::string timestamp;
        std::string product;
        OrderBookType type;
        double price;
        double amount;

    public:
        OrderBookEntry(std::string timestamp, std::string product, OrderBookType type, double price, double amount);
};


#endif