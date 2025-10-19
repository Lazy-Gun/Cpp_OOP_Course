/*\
| |  OrderBook class implementation
| |  Week 7 Add function to compute Maraket stats .
| |  Peer review
| |  Function to implement is track % change in price of a product from timestamp to time stamp
| |  
| |
| |
| |
| |
\*/






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
        
        std::string OrderBook::getEarliestTime(){

            return orders[0].timestamp;
        }

        std::string OrderBook::getNextTime(std::string timestamp)

        {
            std::string next_timestamp = ""; 
            for( OrderBookEntry& e : orders)
            {
                if (e.timestamp > timestamp)
                {
                    next_timestamp = e.timestamp;
                    break;
                }
            }
            if (next_timestamp == "")
            {
                next_timestamp = orders[0].timestamp;
            }
            return next_timestamp;
        }

        /**Compute the arithmatic mean of the product prices
         * input: vector of filtered order book entry
         * returns: average of product price filtered by time stamp
         */

        double OrderBook::computeMean(std::vector<OrderBookEntry>& orders)
        {
            // Local varibles used for computation
            double sum {0};
            double mean{0};

            // Collect the product price values for sum pf product prices
            for(OrderBookEntry& e :orders)
            {
               //
               sum += e.price;
            }
            // divide by numer of elements to compute the average
            mean = sum / orders.size();
            return mean;

        }

        /*Compute the percentage change in price from timestamp to timestamp
         * inputs: vectors of time stampe OrderBook entries filtered by time stamp
         * returns: percentage change of average product price
        */

        double OrderBook::percentageChange(std::vector<OrderBookEntry>& orders, std::vector<OrderBookEntry>& previous_orders)
        {
            // variable to store returned value
            double percentage;
            // calculate the averages of the product price for current time stamp
            double previous_mean = OrderBook::computeMean(previous_orders);
             // calculate the averages of the product price for current previous time stamp
            double mean = OrderBook::computeMean(orders);
            
            // compute the percentage change in product price using the mean of the price
            percentage =  (( mean - previous_mean)/mean)*100;

            return percentage;

        }