#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include "OrderBookEntry.h"
#include "CSVReader.h"

#include <string>
#include <vector>
#include <map>


class OrderBook
{
    public:
        /** construct, reading a csv datafile */
            OrderBook(std::string filename);
        /** return vecotr of all known products in dataset */
            std::vector<std::string> getKnownProducts();
        /** return vector of Orders according to the sent filters */
            std::vector<OrderBookEntry>  getOrders(OrderBookType type, std::string product, std::string timestamp);
    
            static double getHighPrice(std::vector<OrderBookEntry>& orders);
            static double getLowPrice(std::vector<OrderBookEntry>& orders);

    private:
        std::vector<OrderBookEntry> orders;
};


#endif