
#include "Wallet.h"
#include "CSVReader.h" 
#include <iostream>

Wallet::Wallet(){
 
}

bool Wallet::containsCurrency(std::string type, double amount){
    if(currencies.count(type) == 0) 
        return false;
    else 
        return currencies[type] >= amount;
}

void Wallet::insertCurrency(std::string type, double amount){

    double balance;
// Throw exception if 'amout is less than 0
    if(amount < 0)
    {
        throw std::exception{};
    }

// if no currency type is in wallet set balance to 0
    if(currencies.count(type) == 0) 
    {
        balance = 0;
    }
    else
    { // is there
        balance = currencies[type];

    }  
// add amount to balance, set to zero if no currency type or adds to balqance if type in wallet
    balance += amount;
    currencies[type] = balance;
}

std::string Wallet::toString(){

    std::string s;
    for (std::pair<std::string,double> pair : currencies)
    {
        std::string currency = pair.first;
        double amount = pair.second;
        s+= currency + " : " + std::to_string(amount) + "\n";
    }
    if(s == "") return " your wallet is empty";
    else return s;
}

bool Wallet::removeCurrency(std::string type, double amount)
{
    double balance;

    if(amount < 0)
    {
        throw std::exception{};
    }
    if( currencies.count(type) == 0) // not there yet
    {
        return false;
    }
    else
    { // is there, do we have enough?
           if(containsCurrency(type, amount))
        {
 // If the wallet does not contain this much currency, do not change the wallet and return true
            currencies[type] -= amount;
            return true;
        }
        else 
           // return false;
            return true;
    }   
    balance += amount;
    currencies[type] = balance;
}

 bool Wallet::canFulFillOrder(OrderBookEntry order)
{
    
    std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
    //ask
    if(order.orderType == OrderBookType::ask)
    {
        double amount = order.amount;
        std::string currency = currs[0];
        std::cout << "Wallet::canFulFillOrder" << currency << " : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    //bid
    if(order.orderType == OrderBookType::bid)
    {
        double amount = order.amount * order.price;
        std::string currency = currs[1];
        std::cout << "Wallet::canFulFillOrder" << currency << " : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    return false;
}

void Wallet::processSale(OrderBookEntry& sale)
{

    
    std::vector<std::string> currs = CSVReader::tokenise(sale.product, '/');
    //ask
    if(sale.orderType == OrderBookType::asksale)
    {
        double outgoingAmount = sale.amount;
        std::string outgoingCurrency = currs[0];
        double incomingAmount = sale.amount * sale.price;
        std::string incomingCurrency = currs[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;

    }
    //bid
    if(sale.orderType == OrderBookType::bidsale)
    {
        double incomingAmount = sale.amount;
        std::string incomingCurrency = currs[0];
        double outgoingAmount = sale.amount * sale.price;
        std::string outgoingCurrency = currs[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
}
