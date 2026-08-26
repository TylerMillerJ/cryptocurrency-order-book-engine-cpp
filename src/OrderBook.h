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
    
        /** return the earliest time in the orderbook */
            std::string getEarliestTime();
        /** return the next time after the sent time in the orderbook; if none, wraps around to start */
            std::string getNextTime(std::string timestamp);

        /** search the highest price in the vector of OrderBookEntry's */
            static double getHighPrice(std::vector<OrderBookEntry>& orders);
        /** search the lowest price in the vector of OrderBookEntry's */
            static double getLowPrice(std::vector<OrderBookEntry>& orders);

            void insertOrder(OrderBookEntry& order);

        std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);
   
        private:
        std::vector<OrderBookEntry> orders;
};


#endif