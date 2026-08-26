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

    for (OrderBookEntry& entry : orders)
    {
        if (entry.type == type && entry.product == product && entry.timestamp == timestamp)
        {
            ordersSub.push_back(entry);
        }
    }

    return ordersSub;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double max = orders[0].price;

    for (OrderBookEntry& entry : orders)
    {
        if (entry.price > max)
        {
            max = entry.price;
        }
    }
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].price;

    for (OrderBookEntry& entry : orders)
    {
        if (entry.price < min)
        {
            min = entry.price;
        }
    }
    return min;
}