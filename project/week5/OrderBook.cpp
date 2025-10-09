#include "OrderBook.h"
#include "CSVReader.h"


    /**Construtor, read in a CSV data file */
        OrderBook::OrderBook(std::string filename)
        {
            orders = CSVReader::readCSV(filename);
        }
    /** Return vector of all known products in the dataset  */
        std::vector<std::string> OrderBook::getKnownProducts()
        {
            std::vector<std::string> products;
            // create key value pairs of poducts
            std::map<std::string, bool> prodMap;
            for(OrderBookEntry& e: orders)
            {
                prodMap[e.product] = true;
            }

            for(auto const& e : prodMap)
            {
                products.push_back(e.first);
            }
            return products;
        }
    /* Return vector of orders according to the sent filtres*/
        std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                              std::string product,
                                              std::string timestamp)
        {
            std::vector<OrderBookEntry> orders_sub;
            for(OrderBookEntry& e : orders)
            {
                if( e.orderType == type &&
                    e.product == product &&
                    e.timestamp == timestamp){
                        orders_sub.push_back(e);
                    }
            }

            return orders_sub;    
        }

        double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
        {
            double max = orders[0].price;
            for(OrderBookEntry& e :orders){
                if(e.price > max) max = e.price;

            }
            return max;
        }

        double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
        {
            double min = orders[0].price;
            for(OrderBookEntry& e :orders){
                if(e.price < min) min = e.price;

            }
            return min;
        }
