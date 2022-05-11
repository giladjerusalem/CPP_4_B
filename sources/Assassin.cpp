#include <iostream>
#include <string>

#include "Assassin.hpp"




using namespace std;

namespace coup
{
    Assassin::Assassin(Game &game, string player_name) : Player(game, player_name, "Assassin")    //constructor
    {
        
    }

    void Assassin_coup (Player &player){    //coup of 3 coins
        player.coup(player);
    }
}