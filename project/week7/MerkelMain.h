#pragma once

#include<vector>
#include"OrderBookEntry.h"
#include"OrderBook.h"
#include"Wallet.h"

class MerkelMain{

    public:    
        MerkelMain();
        /** call this at start */
        void init();

    private:
        void printMenu();
        int getUserOption();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void processUserOption(int userOption);
        void exit_program();

        std::string currentTime;
        std::string previousTime ="";

        OrderBook orderBook{"data/test_data.csv"};

        Wallet wallet;

};
