#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>
#include <map>


class OrderBook{


    public:
    /**Construtor, read in a CSV data file */
        OrderBook(std::string filename);
    /** Return vector of all known products in the dataset  */
        std::vector<std::string> getKnownProducts();
    /* Return vector of orders according to the sent filtres*/
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                              std::string product,
                                              std::string timestamp);
        /** Returns earliest time in the orderbook*/
        std::string getEarliestTime();
         /** Returns next time after the sent time in the orderbook
          * no next times stamp wraps around to start
         */
        std::string getNextTime(std::string timestamp);

        void insertOrder(OrderBookEntry& order);

        static double getHighPrice(std::vector<OrderBookEntry>& orders);

        static double getLowPrice(std::vector<OrderBookEntry>& orders);

        static double computeMean(std::vector<OrderBookEntry>& orders);
        
        static double percentageChange(std::vector<OrderBookEntry>& orders, std::vector<OrderBookEntry>& previous_orders);

    private:

        std::vector<OrderBookEntry> orders;
       // double previous_mean;
};