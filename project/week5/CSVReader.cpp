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

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> strings){
    
    OrderBookEntry obe{"","", OrderBookType::bid, 1,1};
    return obe;

}
