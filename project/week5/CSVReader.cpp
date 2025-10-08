#include <iostream>
#include "CSVReader.h"

CSVReader::CSVReader(){


}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile){

    std::vector<OrderBookEntry> entries;
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator){

    std::vector<std::string> tokens;
    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens){
    
    double price, amount;

    if(tokens.size() != 5){
            std::cout << "bad csv line" << std::endl;
            throw std::exception{};
        }
        try{
            price = std::stod(tokens[3]);
            amount = std::stod(tokens[4]);

            //std::cout << std::fixed << std::setprecision(8); 
            std::cout << price <<" : " << amount << std::endl;
        }catch(const std::exception& e){
             std::cout << "Bad float" << tokens[3] << std::endl;
             std::cout << "Bad float" << tokens[4] << std::endl;
             throw;
          
        }
    OrderBookEntry obe{ tokens[0],
        tokens[1], 
        OrderBookEntry::stringToOrderBookType(tokens[2]),
         price,
         amount};
    
    return obe;

}
