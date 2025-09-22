/*\
| | Introduction to Object Oriented Programming in C++
| | Week 2 Lab 1 - Refactored week 1 to use functions for menu calls
| | Week 3 Lab 1 - Modelling data
| | Week 3 Lab 2 - Modelling data as a class
| | Week 4 Header file patterns for OrderBookEntry class
| | Week 5 MerkleMain class
\*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "OrderBookEntry.h"
#include "MerkelMain.h"

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
//Week 3 Orderbook entry class and functions to access vectors

  

std::vector<OrderBookEntry> entries;

void PrintOrderBookEntry(std::vector<OrderBookEntry>& entries){   
    for (unsigned int i = 0; i < entries.size(); ++i){ 
    std::cout << std::fixed << std::setprecision(8); 
    std::cout << entries[i].timestamp;
    std::cout <<",";
    std::cout << entries[i].product;
    std::cout <<",";
    std::cout << orderBookTypeToString(entries[i].orderType);
    std::cout <<",";
    std::cout << entries[i].price;
    std::cout <<",";
    std::cout << entries[i].amount <<std::endl;
    }
    
}

double computeAveragePrice(std::vector<OrderBookEntry>& entries){
    double sum = 0;
    // double average_price = 0;
    for (OrderBookEntry& entry : entries){
        // access price[i]
        // add the value to sum variable
        // divide sum variable by number of vectors
        sum += entry.price;
    }

    //double average_price = entries.empty() ? 0 : sum / entries.size();
    //
    double average_price =  sum / entries.size();
    return average_price;

}

double computeLowPrice(std::vector<OrderBookEntry>& entries){
    // set lowPrice Variable 
   // assign  0th price to it
  // compare i + 1 to variable if lower store
     double lowest_price;
     for (unsigned int i = 0; i < entries.size(); ++i){ 
        if (i == 0){
            lowest_price = entries.at(0).price;
        }
        if (i+1 == entries.size()) {
            return lowest_price;
        }  else {
            if(entries.at(i+1).price < lowest_price){
                lowest_price = entries.at(i+1).price;
            } 
        } 
        
    }
     return lowest_price;
}

double computeHighPrice(std::vector<OrderBookEntry>& entries){

    double highest_price;
     for (unsigned int i = 0; i < entries.size(); ++i){ 
        if (i == 0){
            highest_price = entries.at(0).price;
        }
        if (i+1 == entries.size()) {
            return highest_price;
        }  else {
            if(entries.at(i+1).price > highest_price){
                highest_price = entries.at(i+1).price;
            } 
        } 
        
    }
     return highest_price;
    return 0;
}

double lowestPrice;
double highestPrice;
double priceSpread;

double computePriceSpread(std::vector<OrderBookEntry>& entries){
    double price_spread = highestPrice - lowestPrice;
    return price_spread;
}

// Week 2 refactored menu and user input Functions
void printMenu() {
    // main menu printout to console
    std::cout << " 1 : Print help" << std::endl;
    std::cout << " 2 : Print exchange stats" << std::endl;
    std::cout << " 3 : Place an ask" << std::endl;
    std::cout << " 4 : Place a bid" << std::endl;
    std::cout << " 5 : Print wallet" << std::endl;
    std::cout << " 6 : Continue" << std::endl;
    std::cout << " 7 : Exit " << std::endl;
    std::cout << " ************************ " << std::endl;
    std::cout << " Type a number 1-6" << std::endl;
}

int getUserOption()
{
    // get input value and return it
    int userOption;
    std::cin >> userOption;
    std::cout << " You chose: " << userOption << std::endl;
    return userOption;
}

void printHelp(){
    std::cout << " 1: Matt Olsen's rip off crypto currency exchange" << std::endl;
    std::cout << " 1: But, Sell, Give me your Cash" << std::endl;
    std::cout << " " << std::endl;

}

void printMarketStats(){
    std::cout << " 2: Exchange Statistics" << std::endl;
    std::cout << " " << std::endl;
}

void enterAsk(){
    std::cout << " 3: Ask for exchange" << std::endl;
    std::cout << " " << std::endl;
}

void enterBid(){
    std::cout << " 4: Bid for an exchange" << std::endl;
    std::cout << " " << std::endl;
}

void printWallet(){
    std::cout << " 5: Wallet print out" << std::endl;
    std::cout << " " << std::endl;
}

void gotoNextTimeframe(){
    std::cout << " 6: Continue to next time frame " << std::endl;
    std::cout << " " << std::endl;
}

void exit(){
    std::cout << " 7: Exit the exchange" << std::endl;
    std::cout << " " << std::endl;
    exit(0);
}
/** Function to process user input. Uses switch statement not if staements and I have added an exit() function  */
void processUserOption(int userOption)
{
    switch (userOption){

    case 1:
        printHelp();
        break;
    case 2:
        printMarketStats();

        break;
    case 3:
        enterAsk();
        break;
    case 4:
        enterBid();
        break;
    case 5:
        void printWallet();
        break;
    case 6:
        gotoNextTimeframe();
        break;
    case 7:
        exit();
    default:
        std::cout << " Invalid number" << std::endl;
        break;
    }
}

std::string orderBookTypeToString(OrderBookType type) {
    switch (type) {
        case OrderBookType::bid: return "bid";
        case OrderBookType::ask: return "ask";
        default: return "unknown";
    }
}

int main()
{
    
    /**while (true){

        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }*/

    /** Dataset - the first 5 lines from course CSV dataset
    "01:24.9","ETH/BTC",OrderBookType::bid,0.02187308,7.44564869
    "01:24.9","ETH/BTC",OrderBookType::bid,0.02187307,3.467434
    "01:24.9","ETH/BTC",OrderBookType::bid,0.02187305,6.85567013
    "01:24.9","ETH/BTC",OrderBookType::bid,0.021873,1
    "01:24.9","ETH/BTC",OrderBookType::bid,0.02187163,0.03322569
     */

    // InstantiateOrderBook Entry vectors for experimentation
    std::vector<OrderBookEntry> entries;
    entries.push_back( OrderBookEntry { "01:24.9","ETH/BTC",OrderBookType::bid,0.02187308,7.44564869} );
    entries.push_back( OrderBookEntry { "01:24.9","ETH/BTC",OrderBookType::bid,0.02187307,3.467434} );
    entries.push_back( OrderBookEntry { "01:24.9","ETH/BTC",OrderBookType::bid,0.02187305,6.85567013} );
    entries.push_back( OrderBookEntry { "01:24.9","ETH/BTC",OrderBookType::bid,0.021873,1} );
    entries.push_back( OrderBookEntry { "01:24.9","ETH/BTC",OrderBookType::bid,0.02187163,0.03322569} );
   
    lowestPrice = computeLowPrice(entries);
    highestPrice = computeHighPrice(entries);
    priceSpread = computePriceSpread(entries);

    // test  print out formatted vector[0]
    std::cout << " " << std::endl;
    std::cout << "Here is a print out of the 5 vectors created for this exercise :" << std::endl;
    PrintOrderBookEntry(entries);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Average price is  " << computeAveragePrice(entries) << std::endl;
    std::cout << " " << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Lowest price is  " << lowestPrice << std::endl;
    std::cout << " " << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Highest price is  " << highestPrice << std::endl;
    std::cout << " " << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "The price Spread is  " << priceSpread << std::endl;
    std::cout << " " << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    return 0;
}