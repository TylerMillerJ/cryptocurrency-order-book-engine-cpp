#include "OrderBook.h"
#include "CSVReader.h"



OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;

    std::map<std::string, bool> prodMap;

    for (OrderBookEntry& order : orders)
    {
        prodMap[order.product] = true;
    }

    for (auto const& product : prodMap)
    {
        products.push_back(product.first);
    }

    return products; 
}

std::vector<OrderBookEntry>  OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> ordersSub;

    return ordersSub;
}
