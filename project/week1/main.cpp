#include <iostream>

int main()
{
    while (true)
    {
        // Variable for input
        int userOption;
        // main menu printout to consloe
        std::cout << " 1 : Print help" << std::endl;
        std::cout << " 2 : Print exchange stats" << std::endl;
        std::cout << " 3 : Place an ask" << std::endl;
        std::cout << " 4 : Place a bid" << std::endl;
        std::cout << " 5 : Print wallet" << std::endl;
        std::cout << " 6 : Continue" << std::endl;
        std::cout << " 7 : Exit " << std::endl;
        std::cout << " ************************ " << std::endl;
        std::cout << " Type a number 1-6" << std::endl;
        // input value and assign to userOption
        std::cin >> userOption;
            std::cout << "You chose: " << userOption << std::endl;


    switch(userOption){

    // 1 : Print help
    // 2 : Print exchange stats
    // 3 : Place an ask
    // 4 : Place a bid
    // 5 : Print wallet
    // 6 : Continue

       case 1:
           std::cout << " 1: Matt Olsen's rip off crypto currency exchange" << std::endl;
           std::cout << " " << std::endl;
           break;
       case 2:
           std::cout << " 2: Exchange Statistics" << std::endl;
           std::cout << " " << std::endl;
           break;
       case 3:
           std::cout << " 3: Ask for exchange" << std::endl;
           std::cout << " " << std::endl;
           break;
       case 4:
           std::cout << " 4: Bid for an exchange" << std::endl;
           std::cout << " " << std::endl;
           break;
       case 5:
           std::cout << " 5: Wallet print out" << std::endl;
           std::cout << " " << std::endl;
           break;
       case 6:
           std::cout << " 6: Continue to next time frame " << std::endl;
           std::cout << " " << std::endl;
           break;
       case 7:
           std::cout << " 7: Exit the exchange" << std::endl;
           std::cout << " " << std::endl;
           return 0;
       default :
           std::cout << " Invalid number" << std::endl;
           break;
        }
    }



    return 0;
}