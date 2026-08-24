#ifndef ORDER_BOOK_ENTRY_H
#define ORDER_BOOK_ENTRY_H

#include <string>

enum class OrderBookType{bid, ask};

class OrderBookEntry
{
    private:
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType type;

    public:
        OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _type);
};


#endif