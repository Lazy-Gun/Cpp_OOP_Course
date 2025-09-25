/*\
| | OrderBookOrder class specification
\*/

#include<string>

enum class OrderBookType{bid, ask};

class OrderBookEntry { 
    public:
    // construtor
        OrderBookEntry (std::string _timestamp,
                        std::string _product,
                        OrderBookType _orderType,          
                        double _price,
                        double _amount
                        );

    

    // Initialisation list

        // data members
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
        double price;
        double amount;
};  