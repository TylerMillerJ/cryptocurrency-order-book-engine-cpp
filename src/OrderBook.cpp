#include "OrderBook.h"
#include "CSVReader.h"

#include <algorithm>


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

std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string nextTimestamp;

    for (const OrderBookEntry& entry : orders)
    {
        if (entry.timestamp > timestamp)
        {
            nextTimestamp = entry.timestamp;
            break;
        }
    }
    if (nextTimestamp == "")
    {
        nextTimestamp = orders[0].timestamp;
    }
    return nextTimestamp;
}


void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);

    std::vector<OrderBookEntry> sales;

    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAscending);
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDescending);

    for (OrderBookEntry& ask :  asks)
    {
        for (OrderBookEntry& bid : bids)
        {
            if (bid.price >= ask.price)
            {
                OrderBookEntry sale{timestamp, product, OrderBookType::asksale, ask.price, 0};
                
                if (bid.username == "simulationUser")
                {
                    sale.username = "simulationUser";
                    sale.type = OrderBookType::bidsale;
                }
                if (ask.username == "simulationUser")
                {
                    sale.username = "simulationUser";
                    sale.type = OrderBookType::asksale;;

                }
        
                if (bid.amount == ask.amount)
                {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0;
                    break;

                } else if (bid.amount > ask.amount)
                {  
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = bid.amount - ask.amount;
                    break;
                    
                } else if (bid.amount < ask.amount && bid.amount > 0)
                {
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    ask.amount = ask.amount - bid.amount;
                    bid.amount = 0;
                    continue;
                }


            }

        }
    }
    return sales;
}
