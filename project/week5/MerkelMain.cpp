#include<iostream>
#include<vector>
#include"MerkelMain.h"
#include"OrderBookEntry.h"
#include "CSVReader.h"

MerkelMain::MerkelMain(){

}

void MerkelMain::init(){

    int input;
    while(true){
            printMenu();
            input = getUserOption();
            processUserOption(input);
    }
}



// Week 2 refactored menu and user input Functions
void MerkelMain::printMenu() {
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

int MerkelMain::getUserOption()
{
    // get input value and return it
    int userOption;
    std::cin >> userOption;
    std::cout << " You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::printHelp(){
    std::cout << " 1: Matt Olsen's rip off crypto currency exchange" << std::endl;
    std::cout << " 1: But, Sell, Give me your Cash" << std::endl;
    std::cout << " " << std::endl;

}

void MerkelMain::printMarketStats(){


    for(std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                p, "01:24.9");
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout<< "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout<< "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;

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
    std::cout << " 3: Ask for exchange" << std::endl;
    std::cout << " " << std::endl;
}

void MerkelMain::enterBid(){
    std::cout << " 4: Bid for an exchange" << std::endl;
    std::cout << " " << std::endl;
}

void MerkelMain::printWallet(){
    std::cout << " 5: Wallet print out" << std::endl;
    std::cout << " " << std::endl;
}

void MerkelMain::gotoNextTimeframe(){
    std::cout << " 6: Continue to next time frame " << std::endl;
    std::cout << " " << std::endl;
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
        void printWallet();
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