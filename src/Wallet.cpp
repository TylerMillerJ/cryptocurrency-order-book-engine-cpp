#include "Wallet.h"
#include "CSVReader.h"

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>


Wallet::Wallet()
{

    currencies["USDT"] = 10000.0;
    currencies["BTC"] = 9470.0;
    currencies["LTC"] = 12.0;
    currencies["ETH"] = 200.00;
    currencies["DOGE"] = 1.00;
    currencies["SOL"] = 20.00;

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

bool Wallet::canFulfillOrder(const OrderBookEntry& order)
{
    std::vector<std::string> currenciesVec = CSVReader::tokenise(order.product, '/');

    if (currenciesVec.size() != 2 || currenciesVec[0].empty(), currenciesVec[1].empty())
    {
        std::cerr << "Invalid Product: " << order.product << std::endl;
        return false;
    }

    if (order.amount <= 0 || order.price <= 0)
    {
        std::cerr << "Error: Order Amount and Price Must Be Greater Then 0" << std::endl;
        return false;
    }

    //ask
    if (order.type == OrderBookType::ask)
    {
        double amount = order.amount;
        std::string currency = currenciesVec[0];
        return containsCurrency(currency, amount);
    }
    //bid
    if (order.type == OrderBookType::bid)
    {
        double amount = order.amount * order.price;
        std::string currency = currenciesVec[1];

        return containsCurrency(currency, amount);
    }

    return false;
}

void Wallet::processSale(OrderBookEntry& sale)
{
        std::vector<std::string> currenciesVec = CSVReader::tokenise(sale.product, '/');

    //ask
    if (sale.type == OrderBookType::asksale)
    {
        double outgoingAmount = sale.amount;
        std::string outgoingCurrency = currenciesVec[0];
        
        double incomingAmount = sale.amount * sale.price;
        std::string incomingCurrency = currenciesVec[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;

    }
    //bid
    if (sale.type == OrderBookType::bidsale)
    {
        double incomingAmount = sale.amount;
        std::string incomingCurrency = currenciesVec[0];
        
        double outgoingAmount = sale.amount * sale.price;
        std::string outgoingCurrency = currenciesVec[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;

    }
}

void Wallet::printWallet()

{
    std::cout << "Opening Wallet..." << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Wallet:" << std::endl;
    std::cout << Wallet::toString() << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;

}


void Wallet::makeDeposit()
{

    printSupportedCurrencies();

    std::cout << "Enter Currency Name, Amount" << std::endl;
    std::cout << "Example: BTC, 1000" << std::endl;
    std::cout << "Make Deposit:";

    std::string input;
    
    if (!std::getline(std::cin, input))
    {
        std::cout << "End Of File Detected - Exiting Gracefully"
                << std::endl;

        std::exit(0);
    }
    std::vector<std::string> depositTokens = CSVReader::tokenise(input, ',');

    if (depositTokens.size() != 2)
    {
        std::cerr << "Invalid Input: Tokens Not Equal To 2" << std::endl;
        return;
    } 
    
    try 
    {
        double amount = std::stod(depositTokens[1]);
        insertCurrency(depositTokens[0], amount);

        std::cout << "Successfully Deposited: " << amount << " " << depositTokens[0] << std::endl;
        printWallet();
        return;
    } catch (const std::exception& exception)
        {
            std::cerr << "makeDeposit() Failed" << std::endl;
        }
    }

const std::vector<std::string> Wallet::supportedCurrencies =
{
    "USDT",
    "BTC",
    "LTC",
    "ETH",
    "DOGE",
    "SOL"
};
bool Wallet::isSupportedCurrency(const std::string& currency)
{
    return std::find(supportedCurrencies.begin(), supportedCurrencies.end(), currency) != supportedCurrencies.end();
}

void Wallet::printSupportedCurrencies()
{
    std::cout << "Supported Currencies: ";
    for (std::size_t i = 0; i < supportedCurrencies.size() - 1; ++i)
    {
        std::cout << supportedCurrencies[i] << ", ";
    }
        std::cout << supportedCurrencies.back() << std::endl;

}