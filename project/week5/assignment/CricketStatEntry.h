/*\
| |Class to CricketStatEntry 
| | Class specification
| | 
| | Attributes
| | match,  string
| | team_innings, string
| | batting_pos, number <11
| | batsman_name,  string
| | runs, number <100
| | balls, number < 60
| | fours, number <60
| | sixes,number <60
| | strike_rate,<400
| | out_not_out, eunm (out/not_out)
| | match_id
| |   
| | 
\*/

#pragma once
#include<string>

enum class CricketTypeOut{out, not_out};

class CricketStatEntry { 
    public:
    // construtor
        CricketStatEntry (std::string  _match,
                          std::string  _team_innings,
                          int _batting_pos,
                          std::string _batsman_name,
                          int _runs,
                          int _balls,
                          int _fours,
                          int   _sixes,
                          float  _strike_rate,
                          CricketTypeOut _out_not_out,
                          std::string _match_id
                        );

    

    // Initialisation list

        // data members
std::string match;
std::string team_innings;
int batting_pos;
std::string batsman_name;
int runs;
int balls;
int fours;
int sixes;
float strike_rate;
CricketTypeOut out_not_out;
std::string match_id;

};  