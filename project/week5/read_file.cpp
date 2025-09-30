#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<fstream>

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

/*       
    // call tokenise function to read string of CSV 
        std::vector<std::string> tokens;
        std::string s = "01:24.9,ETH/BTC,OrderBookType::bid,0.02187308,7.44564869";
        tokens = tokenise(s, ',');

        for (std::string& t :tokens)
        {

            std::cout << t << std::endl;

        } */

    // Read in from file

    std::ifstream csvFile{"crypto_dataset_with_errors.csv"};
    std::string line;
    std::vector<std::string> tokens;

    if(csvFile.is_open()){

        std::cout << "File is open" << std::endl;
        while(std::getline(csvFile, line)){

            std::cout << "Read line: "<< line << std::endl;

            tokens = tokenise(line, ',');
            if(tokens.size() != 5){
                std::cout << "bad csv line" << std::endl;
                continue;
            }
            try{
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << std::fixed << std::setprecision(8); 
                std::cout << price <<" : " << amount << std::endl;
            }catch(std::exception& e){
                 std::cout << "Bad float" << tokens[3] << std::endl;
                 std::cout << "Bad float" << tokens[4] << std::endl;
                 continue;
              
            }


        }
        csvFile.close();
    }
    else
    {
        std::cout << "Could not open file" << std::endl;
    }
 
    return 0;
}