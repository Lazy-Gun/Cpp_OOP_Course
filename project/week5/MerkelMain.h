#pragma once

#include<vector>
#include"OrderBookEntry.h"

class MerkelMain{

    public:    
        MerkelMain();
        /** call this at start */
        void init();

    private:
        void loadOrderBook();
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

        std::vector<OrderBookEntry> entries;


};
