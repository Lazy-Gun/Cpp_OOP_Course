/*\
| | Class to CricketStatEntry
| | Class implementation 
| | 
| | match (_match),
| | team_innings (_team_innings),
| | batting_pos (_batting_pos),
| | batsman_name (_batsman_name),
| | runs (_runs),
| | balls (_balls),
| | fourss (_fourss),
| | sixes (_sixes),
| | strike_rate(_single_run),
| | out_not_out (_out_not_out),
| | match_id (_match_id)
| | class implementation
\*/

#include "CricketStatEntry.h"

 CricketStatEntry::CricketStatEntry (  std::string  _match,
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
                            )
                        

    // Initialisation list
:        match (_match),
         team_innings (_team_innings),
         batting_pos (_batting_pos),
         batsman_name (_batsman_name),
         runs (_runs),
         balls (_balls),
         fours (_fours),
         sixes (_sixes),
         strike_rate (_strike_rate),
         out_not_out (_out_not_out),
         match_id (_match_id)

{

}


