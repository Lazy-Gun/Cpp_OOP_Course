#include<iostream>
#include<string>
#include<vector>

#include <iomanip> // Required for std::setprecision


enum class OrderBookType{bid, ask};

std::string orderBookTypeToString(OrderBookType type) {
    switch (type) {
        case OrderBookType::bid: return "bid";
        case OrderBookType::ask: return "ask";
        default: return "unknown";
    }
}

/** Line from data set CSV: 01:24.9,ETH/BTC,bid,0.02187308,7.44564869 */

int main(){
    // initialise and assign variables
    double amountA{0.02187308f};
    double amountB{7.44564869};
    double amountC = 1.234567;

    std::string product{"ETH/BTC"};
    std::string timestamp{"01:24.9"};

    OrderBookType orderType = OrderBookType::bid;

    // data modelled as vectors
    std::vector<double> amounts;
    amounts.push_back(amountA);
    amounts.push_back(amountB);
    amounts.push_back(amountC);

    // console print the variables
    std::cout << std::fixed << std::setprecision(8);     // Set precision to show full digits

    std::cout << "" << std::endl;
    std::cout << "Line from data set CSV: 01:24.9,ETH/BTC,bid,0.02187308,7.44564869" << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;

    std::cout << "Line form variables ";
    std::cout << timestamp;
    std::cout << "," ;
    std::cout << product;
    std::cout << "," ;
    /** std::cout << orderType; error here cannot convert orderType to string as in enum so needs helper function 
    orderBookTypeToString(orderType)
    */ 
    std::cout << orderBookTypeToString(orderType);
    std::cout << ',';
    std::cout << amountA;
    std::cout << "," ;
    std::cout << amountB <<std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "First row amount " << amounts[0] << std::endl;
    std::cout << "Second row amount " << amounts[1] << std::endl;
    std::cout << "Third row amount " << amounts[2] << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "" <<std::endl;
    return 0;
}

