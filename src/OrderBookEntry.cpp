#include "OrderBookEntry.h"

#include <string>


OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _type, double _price, double _amount)
        :   timestamp(_timestamp),   
            product(_product),
            type(_type),
            price(_price),
            amount(_amount)
            {
            }
        
        
OrderBookType OrderBookEntry::stringToOrderBookType(std::string string)
{
    if (string == "ask"){
        return OrderBookType::ask;
    }
    if (string == "bid"){
        return OrderBookType::bid;
    }

    return OrderBookType::unknown;

}

bool OrderBookEntry::compareByTimestamp(OrderBookEntry& entry1, OrderBookEntry& entry2)
{
    return entry1.timestamp < entry2.timestamp;
}

bool OrderBookEntry::compareByPriceAscending(OrderBookEntry& entry1, OrderBookEntry& entry2)
{
    return entry1.timestamp < entry2.timestamp;
}

bool OrderBookEntry::compareByPriceDescending(OrderBookEntry& entry1, OrderBookEntry& entry2)
{
    return entry1.timestamp > entry2.timestamp;
}
