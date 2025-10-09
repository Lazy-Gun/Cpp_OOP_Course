#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenise(std::string csvLine, char separator){

    std::vector<std::string> tokens;
    
    // signed int doesnt matc
    std::string::size_type start, end;
    std::string token;
    // finds start index of line 
    start = csvLine.find_first_not_of(separator, 0);
    
    do{  // returns index of separator
            end = csvLine.find_first_of( separator, start);
        // checks that its not a line of 0 characters
        if (start == csvLine.length() || start ==end) break;
        // second check to pass string
        if (end >= 0) token = csvLine.substr(start, end - start);
        //passes found string to token variable
        else token = csvLine.substr(start, csvLine.length() - start);
        // adds string to token vector
        tokens.push_back(token);
        // moves around the separator to start from new index
        start = end + 1;
    } 
    // while the end is less than legth of string
    while (end != std::string::npos);


    return tokens;

}

int main(){

        std::vector<std::string> tokens;
        std::string s = "01:24.9,ETH/BTC,OrderBookType::bid,0.02187308,7.44564869";
        tokens = tokenise(s, ',');

        for (std::string& t :tokens)
        {
            std::cout << t << std::endl;

        }
 
    return 0;
}