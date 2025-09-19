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
        std::cout << " " << std::endl;
        std::cout << " Type a number 1-6" << std::endl;
        // input value and assign to userOption
        std::cin >> userOption;

        if (userOption < 1)
        {
            std::cout << " Don't be silly!" << std::endl;
            std::cout << " " << std::endl;
            //continue;
        }
        if (userOption > 7)
        {
            std::cout << " Don't be stupid !" << std::endl;
            std::cout << " " << std::endl;
            //continue;
        }
        if (userOption > 0 && userOption < 8)
        {
            switch(userOption){
                case 1:
                    std::cout << " Matt Olsen's rip off crypto currency exchange" << std::endl;
                    std::cout << " " << std::endl;
                    break;
                case 2:
                    std::cout << " Exchange Statistics" << std::endl;
                    std::cout << " " << std::endl;
                    break;
                case 3:
                    std::cout << " ask for exchange" << std::endl;
                    std::cout << " " << std::endl;
                    break;
                case 4:
                    std::cout << " Bid for an exchange" << std::endl;
                    std::cout << " " << std::endl;
                    break;
                case 5:
                    std::cout << " Wallet print out" << std::endl;
                    std::cout << " " << std::endl;
                    break;
                case 6:
                    std::cout << " Continue " << std::endl;
                    std::cout << " " << std::endl;
                    break;
                case 7:
                    std::cout << " Exit the exchange" << std::endl;
                    std::cout << " " << std::endl;
                    return 0;
                  
            }
        }
    }

    // 1 : Print help
    // 2 : Print exchange stats
    // 3 : Place an ask
    // 4 : Place a bid
    // 5 : Print wallet
    // 6 : Continue

    return 0;
}