#include "CSVReader.h"
#include "OrderBookEntry.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>




CSVReader::CSVReader()
{

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    std::vector<OrderBookEntry> entries;

    std::ifstream csvFile{csvFilename};
    std::string line; 

    if(csvFile.is_open())
    {
        while(std::getline(csvFile, line))
        {
            try
            {
            OrderBookEntry entry = stringToOrderBookEntry(tokenise(line, ','));
            entries.push_back(entry);
            } catch(const std::exception&  e){
                std::cerr << "CSVReader::readCSV Passed Bad Line" << std::endl;
            }
        } //endwhile
        std::cout <<"CSVReader::readCSV read " << entries.size() << " entries." <<std::endl;
    }

    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char seperator)
{

    std::vector<std::string> tokens;
    long  unsigned int start, end;
    std::string token;

    //The first thing which is not the seperator, starting at index 0
    start = csvLine.find_first_not_of(seperator, 0);

    do {
 
        end = csvLine.find_first_of(seperator, start);

        if (start == csvLine.length() || start == end){
            break;
        }

        if (end == std::string::npos){
            token = csvLine.substr(start);
        } else {
            token = csvLine.substr(start, end - start);
        }

        tokens.push_back(token);
        start = end + 1;

    } while (end != std::string::npos);

    return tokens;

}
OrderBookEntry CSVReader::stringToOrderBookEntry(std::vector<std::string> tokens)
{   
    if (tokens.size() != 5)
    {
        std::cerr << "Bad Line" << std::endl;
        throw std::exception{};
    }

        std::string timeStamp = tokens[0];
        std::string product = tokens[1];

        OrderBookType type = OrderBookEntry::stringToOrderBookType(tokens[2]);
        double price;
        double amount;
    try 
    {
        price = stod(tokens[3]);
        amount = stod(tokens[4]);
        
    } catch (...)
    {
        std::cerr << "Bad Float: " << tokens[3] << " OR  " << tokens[4] << std::endl; 
        throw;
    }

    OrderBookEntry orderBookEntry{timeStamp, product, type, price, amount};

    return orderBookEntry;
}
