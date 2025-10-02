#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "CricketStatEntry.h"

/** Tokenise function Reads csv Line and sepertes it by the commas into individual tokens for populating vector.  */

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
    // while the end is less than length of string
    while (end != std::string::npos);
    return tokens;

}

int main(){

    // Declare variables
    // Input file
   std::ifstream csvFile{"cricket_data.csv"};
   // std::ifstream csvFile{"buggy_cricket_data.csv"};
    // line counters
    int lines {0};
    int good_lines{0};
    int bad_lines{0};
    // String to store line    
    std::string line;
    // Vector
    std::vector<std::string> tokens;

    // Read in from file
    if(csvFile.is_open()){

        std::cout << "File is open " << std::endl;
        std::cout << " " << std::endl;
        while(std::getline(csvFile, line)){

            // std::cout << "Read line: "<< line << std::endl;
            lines += 1;

           // Add line read in to vector, tokens.
           tokens = tokenise(line, ',');

           // checks number of tokens in read in row trows error is not equal to 11
            if(tokens.size() != 11){
                // adds bad line tobad line counter  
                bad_lines +=1;
                // prints bad line and line number
                std::cout << "bad csv line : " << line << "  line number: " << lines << std::endl;
                std::cout << ""  << std::endl;
                
                continue;
            }
            try{

                // takes string variables in tokenuise line and converts to number format.
                int batting_pos = std::stoi(tokens[2]);
                int runs = std::stoi(tokens[4]);
                int balls = std::stoi(tokens[5]);
                int fours = std::stoi(tokens[6]);
                int sixes = std::stoi(tokens[7]);
                float strike_rate = std::stof(tokens[8]);

            }catch(std::exception& e){
                // prints line caught by exception 
                 bad_lines +=1;
                 std::cout << "Bad data line : " << line << "  line number: " << lines << std::endl;
                 std::cout << ""  << std::endl;

                 continue;
              
            } 
                 
        }
        good_lines = lines - bad_lines;
        std::cout << "Number of valid data lines =  " << good_lines << std::endl;
        std::cout << "Number bad data lines = " << bad_lines << std::endl;

        csvFile.close();
    }
    else
    {
        std::cout << "Could not open file" << std::endl;
    }
 
    return 0;
}