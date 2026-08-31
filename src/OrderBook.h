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
    
        /** return the earliest time in the order book */
        std::string getEarliestTime();

        /** return the next time after the sent time in the order book; if none, wraps around to start */
        std::string getNextTime(std::string timestamp);

        /** search for the highest price in the vector of OrderBookEntry objects */
        static double getHighPrice(std::vector<OrderBookEntry>& orders);

        /** search for the lowest price in the vector of OrderBookEntry objects */
        static double getLowPrice(std::vector<OrderBookEntry>& orders);

        /** insert an order into the order book */
        void insertOrder(OrderBookEntry& order);

        /** match asks to bids for a product at a given timestamp */
        std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

    private:
        /** collection of orders in the order book */
        std::vector<OrderBookEntry> orders;
};

#endif