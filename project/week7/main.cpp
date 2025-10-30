/*\
| | Introduction to Object Oriented Programming in C++
| | Week 2 Lab 1 - Refactored week 1 to use functions for menu calls
| | Week 3 Lab 1 - Modelling data
| | Week 3 Lab 2 - Modelling data as a class
| | Week 4 Header file patterns
\*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"

/**
* Dataset : taken from the first 5 line of course datasetCSV
*"01:24.9","ETH/BTC",OrderBookType::bid,0.02187308,7.44564869
*"01:24.9","ETH/BTC",OrderBookType::bid,0.02187307,3.467434
*"01:24.9","ETH/BTC",OrderBookType::bid,0.02187305,6.85567013
*"01:24.9","ETH/BTC",OrderBookType::bid,0.021873,1
*"01:24.9","ETH/BTC",OrderBookType::bid,0.02187163,0.03322569
 */

// Prototypes and declartions for functions below

std::string orderBookTypeToString(OrderBookType type);

int main()
{
    MerkelMain app;
    app.init();
    CSVReader::readCSV("crypto_dataset.csv");

    // Wallet wallet;
    // wallet.insertCurrency("BTC", 10);
    // wallet.insertCurrency("USDT", 10000);
    // std::cout << "Wallet has BTC " << wallet.containsCurrency("USDT", 10) <<std::endl;
    // wallet.removeCurrency("USDT", 1000);
    // std::cout << wallet.toString() << std::endl;


}