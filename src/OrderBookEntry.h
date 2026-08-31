#ifndef ORDER_BOOK_ENTRY_H
#define ORDER_BOOK_ENTRY_H

#include <string>

enum class OrderBookType{bid, ask, asksale, bidsale, unknown};

class OrderBookEntry
{
        public:
        /** timestamp when the order was created */
        std::string timestamp;

        /** trading pair for the order */
        std::string product;

        /** type of order */
        OrderBookType type;

        /** price of the order */
        double price;

        /** amount of the product in the order */
        double amount;

        /** compare two orders by timestamp */
        static bool compareByTimestamp(OrderBookEntry& entry1, OrderBookEntry& entry2);

        /** compare two orders by ascending price */
        static bool compareByPriceAscending(OrderBookEntry& entry1, OrderBookEntry& entry2);

        /** compare two orders by descending price */
        static bool compareByPriceDescending(OrderBookEntry& entry1, OrderBookEntry& entry2);

        /** construct an order book entry */
        OrderBookEntry(
            std::string timestamp,
            std::string product,
            OrderBookType type,
            double price,
            double amount,
            std::string username = "dataset"
        );

        /** convert a string into an OrderBookType */
        static OrderBookType stringToOrderBookType(std::string string);

        /** username of the simulationUser/person who placed the order */
        std::string username;
};


#endif