/*\
| | Introduction to Object Oriented Programming in C++
| | Week 2 Lab 1 - Refactored week 1 to use functions for menu calls
| | Week 3 Lab 1 - Modelling data
| | Week 3 Lab 2 - Modelling data as a class
\*/
#include <iostream>

void printMenu() {
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

int getUserOption()
{
    // get input value and return it
    int userOption;
    std::cin >> userOption;
    std::cout << " You chose: " << userOption << std::endl;
    return userOption;
}

void printHelp(){
    std::cout << " 1: Matt Olsen's rip off crypto currency exchange" << std::endl;
    std::cout << " 1: But, Sell, Give me your Cash" << std::endl;
    std::cout << " " << std::endl;

}

void printMarketStats(){
    std::cout << " 2: Exchange Statistics" << std::endl;
    std::cout << " " << std::endl;
}

void enterAsk(){
    std::cout << " 3: Ask for exchange" << std::endl;
    std::cout << " " << std::endl;
}

void enterBid(){
    std::cout << " 4: Bid for an exchange" << std::endl;
    std::cout << " " << std::endl;
}

void printWallet(){
    std::cout << " 5: Wallet print out" << std::endl;
    std::cout << " " << std::endl;
}

void gotoNextTimeframe(){
    std::cout << " 6: Continue to next time frame " << std::endl;
    std::cout << " " << std::endl;
}

void exit(){
    std::cout << " 7: Exit the exchange" << std::endl;
    std::cout << " " << std::endl;
    exit(0);
}
/** Function to process user input. Uses switch statement not if  */
void processUserOption(int userOption)
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
        exit();
    default:
        std::cout << " Invalid number" << std::endl;
        break;
    }
}



int main()
{
    while (true){

        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }
    return 0;
}