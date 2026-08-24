#include "OrderBookEntry.h"

#include <string>


OrderBookEntry::OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _type)
        :   price(_price),
            amount(_amount),
            timestamp(_timestamp),
            product(_product),
            type(_type) 
            {
            }
