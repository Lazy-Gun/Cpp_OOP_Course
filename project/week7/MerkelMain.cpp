#include<iostream>
#include<vector>
#include<iomanip>
#include<limits>
#include"MerkelMain.h"
#include"OrderBookEntry.h"
#include "CSVReader.h"
#include"Wallet.h"



MerkelMain::MerkelMain(){

}

void MerkelMain::init(){

    int input;
    currentTime = orderBook.getEarliestTime();
    previousTime = currentTime;
    // wallet.insertCurrency("BTC", 10);


    while(true){
            printMenu();
            input = getUserOption();
            processUserOption(input);
    }
}



// Week 2 refactored menu and user input Functions
void MerkelMain::printMenu() {
    // main menu printout to console
    
    std::cout << " ************************ " << std::endl;
    std::cout << " 1 : Print help" << std::endl;
    std::cout << " 2 : Print exchange stats" << std::endl;
    std::cout << " 3 : Place an ask" << std::endl;
    std::cout << " 4 : Place a bid" << std::endl;
    std::cout << " 5 : Print wallet" << std::endl;
    std::cout << " 6 : Continue" << std::endl;
    std::cout << " 7 : Exit " << std::endl;
    std::cout << " ************************ " << std::endl;
    std::cout << " Current time is  " << currentTime << std::endl;
    //std::cout << " Type a number 1-6" << std::endl;
}

int MerkelMain::getUserOption()
{
    // get input value and return it
    int userOption{0};
    std::string line;
    std::cout << " Type a number 1-6" << std::endl;
    std::getline(std::cin, line);
    try {userOption = std::stoi(line);
    }catch(const std::exception& e){
        // caught
    }
    std::cout << " You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::printHelp(){
    std::cout << " 1: Matt Olsen's rip off crypto currency exchange" << std::endl;
    std::cout << " 1: But, Sell, Give me your Cash" << std::endl;
    std::cout << " " << std::endl;

}

void MerkelMain::printMarketStats(){
    std::cout << "Current time is  " << currentTime << std::endl;
    std::cout << "previous time is  " <<previousTime << std::endl;

    for(std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                p, currentTime);

        std::vector<OrderBookEntry> previousEntries = orderBook.getOrders(OrderBookType::ask,
                                                                p, previousTime);                                                               

        std::vector<OrderBookEntry> entriesBid = orderBook.getOrders(OrderBookType::bid,
                                                                p, previousTime);      

        std::vector<OrderBookEntry> previousEntriesBid = orderBook.getOrders(OrderBookType::bid,
                                                                p, previousTime);      
        
        std::cout << "Asks seen: " << entries.size() << std::endl;
        double max_ask = OrderBook::getHighPrice(entries);
        double min_ask = OrderBook::getLowPrice(entries);
        double mean = OrderBook::computeMean(entries);
        double previous_mean = OrderBook::computeMean(previousEntries);
        double percentage_change = OrderBook::percentageChange(entries, previousEntries);
        std::cout<< "Max ask: " << max_ask << std::endl;
        std::cout<< "Min ask: " << min_ask << std::endl;
        std::cout<< "Spread: " << max_ask - min_ask << std::endl;
        std::cout<< "Mean ask: " << mean << std::endl;
        std::cout<< "Previous Mean ask: " << previous_mean << std::endl;
        std::cout<< std::showpos << "Percentage change:  " << percentage_change << " %" << std::noshowpos << std::endl;

        std::cout<< "" <<  std::endl;

        std::cout << "Bids seen: " << entriesBid.size() << std::endl;
        double max_bid = OrderBook::getHighPrice(entriesBid);
        double min_bid = OrderBook::getLowPrice(entriesBid);
        double mean_bid = OrderBook::computeMean(entriesBid);
        double previous_mean_bid = OrderBook::computeMean(previousEntriesBid);
        double percentage_change_bid = OrderBook::percentageChange(entriesBid, previousEntriesBid);
        std::cout<< "Max bid: " << max_bid << std::endl;
        std::cout<< "Min bid: " << min_bid << std::endl;
        std::cout<< "Spread: " << max_bid - min_bid << std::endl;

        std::cout<< "Mean bid: " << mean_bid << std::endl;
        std::cout<< "Previous Mean bid: " << previous_mean_bid << std::endl;
        std::cout<< std::showpos << "Percentage change:  " << percentage_change_bid << " %" << std::noshowpos << std::endl;


        std::cout<< "" <<  std::endl;

    }

    /*
    std::cout << " 2: OrderBook contains : " << orders.size() << " orders" << std::endl;
    unsigned int bids = 0;
    unsigned int asks = 0;
    for(OrderBookEntry& e : orders){
        if (e.orderType == OrderBookType::ask ){
            asks ++;
        }
        if (e.orderType == OrderBookType::bid ){
            bids ++;
        }

    }
    std::cout << " 2: OrderBook contains : " << asks << " asks, and " << bids << " bids" << std::endl;
    std::cout << " " << std::endl;*/
}

void MerkelMain::enterAsk(){
    std::cout << " 3: Ask for exchange - Enter: product, price, amount, eg ETH/BTC, 200, 0.5" << std::endl;
    std::string input;
    // Function to clean up input string
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3) 
    {
    std::cout << "MerkelMain::enterAsk Bad Input! "<< input << std::endl;
    }
    else{
        try{
        OrderBookEntry obe = CSVReader::stringsToOBE(
            currentTime,
            tokens[0],
            OrderBookType::ask,
            tokens[1],
            tokens[2]
        );

        if(wallet.canFulFillOrder(obe))
        {
            std::cout << "wallet looks good" << std::endl;
            orderBook.insertOrder(obe);
        }
        else
        {
            std::cout << "wallet has insufficient funds" << std::endl;
        }
        orderBook.insertOrder(obe);
        }catch(const std::exception& e)
        {
            std::cout << "MerkelMain::enterAsk Bad input : "<< input << std::endl;
        }
        }
   
    std::cout << "You typed: "<< input << std::endl;
}

void MerkelMain::enterBid(){
    std::cout << " 4: Bid for an exchange - Enter: product, price, amount, eg ETH/BTC, 289, 0.4" << std::endl;
    std::string input;
    // Function to clean up input string
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3) 
    {
    std::cout << " MerkelMain::enterBid Bad Input! "<< input << std::endl;
    }
    else{
        try{
        OrderBookEntry obe = CSVReader::stringsToOBE(
            currentTime,
            tokens[0],
            OrderBookType::bid,
            tokens[1],
            tokens[2]
        );
if(wallet.canFulFillOrder(obe))
        {
            std::cout << "wallet looks good" << std::endl;
            orderBook.insertOrder(obe);
        }
        else
        {
            std::cout << "wallet has insufficient funds" << std::endl;
        }
        orderBook.insertOrder(obe);
        }catch(const std::exception& e)
        {
            std::cout << "MerkelMain::enterAsk Bad input : "<< input << std::endl;
        }
        }
   
    std::cout << "You typed: "<< input << std::endl;
}

void MerkelMain::printWallet(){
    std::cout << " 5: Wallet print out" << std::endl;
    std::cout << wallet.toString()<< std::endl;
    std::cout << " " << std::endl;
}

void MerkelMain::gotoNextTimeframe(){
    std::cout << " 6: Continue to next time frame " << std::endl;
        for(std::string& p: orderBook.getKnownProducts()){
            std::cout << "Matching " << p << std::endl;
            std::vector<OrderBookEntry> sales = orderBook.matchAskToBid(p,currentTime);
            std::cout << "Sales: "<< sales.size() << std::endl;
            for(OrderBookEntry& sale :sales){
                std::cout << "Sale Price: " << sale.price <<" amount "<< sale.amount <<std::endl;

            } 

        }
    std::cout << " " << std::endl;
    previousTime = currentTime;
    currentTime = orderBook.getNextTime(currentTime);

}

void MerkelMain::exit_program(){
    std::cout << " 7: Exit the exchange" << std::endl;
    std::cout << " " << std::endl;
    exit(0);
}
/** Function to process user input. Uses switch statement not if staements and I have added an exit() function  */
void MerkelMain::processUserOption(int userOption)
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
        printWallet();
        break;
    case 6:
        gotoNextTimeframe();
        break;
    case 7:
        exit_program();
    default:
        std::cout << " Invalid number" << std::endl;
        break;
    }
}

