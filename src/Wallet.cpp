#include "Wallet.h"
#include "CSVReader.h"

#include <iostream>

Wallet::Wallet()
{

}

bool Wallet::containsCurrency(std::string type, double amount)
{
    if (currencies.count(type) == 0)
    {
        return false;
    } else {
        return currencies[type] >= amount;
    }

    return true;
}


void Wallet::insertCurrency(std::string type, double amount)
{
    double balance;
    if (amount < 0)
    {
        throw std::exception{};
    }

    if (!containsCurrency(type, amount))
    {
        balance = 0;
    } else {
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;
}

bool Wallet::removeCurrency(std::string type, double amount)
{
    if (amount < 0) //cant remove negative amounts
    {
        return false;
    } else {
        if (containsCurrency(type, amount)) //only removes if they dont have enough
        {
            currencies[type] -= amount;
            return true;
        }
    }
    return false; //did not have enough to remove amount
}


std::string Wallet::toString()
{
    std::string currencyPair;

    for (std::pair<std::string, double> pair : currencies)
    {
        std::string curency = pair.first;
        double amount = pair.second;
        currencyPair += curency + " : " + std::to_string(amount) + "\n";
    }
    return currencyPair;

}

bool Wallet::canFullfillOrder(OrderBookEntry order)
{
    std::vector<std::string> currencies = CSVReader::tokenise(order.product, '/');

    //ask
    if (order.type == OrderBookType::ask)
    {
        double amount = order.amount;
        std::string currency = currencies[0];
        return containsCurrency(currency, amount);
    }
    //bid
    if (order.type == OrderBookType::bid)
    {
        double amount = order.amount * order.price;
        std::string currency = currencies[1];

        return containsCurrency(currency, amount);
    }

    return false;
}
