#pragma once

#include <string>
#include <map>
#include "OrderBookEntry.h"

class Wallet
{
    public:
        Wallet();
        /** Insert currency into wallet */
        void insertCurrency(std::string type, double amount);
        
        /** Remove currency from wallet */
        bool removeCurrency(std::string type, double amount);

        /** check if wallet contains currency */
        bool containsCurrency(std::string type, double amount);

        /**Checks if the wallet can fulfill ask or bid */
        bool canFulFillOrder(OrderBookEntry order);

        /** generates string representation of wallet */
        std::string toString();

    private:

        std::map<std::string, double> currencies;
};