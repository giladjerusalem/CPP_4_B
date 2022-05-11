#include <iostream>
#include <string>

#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"


using namespace std;

namespace coup
{
    Captain::Captain(Game &game, string player_name) : Player(game, player_name, "Captain")   //constructor
    {
     this->game=game;
     this->player_name=player_name;
    }

    void Captain::steal(Player &player)     //can steal 2 coins, can be blocked by captain \ ambassador
    {
        game.set_money(player.player_name, -2);
        game.set_money(player_name, 2);
    }
    
    void Captain::block(Player &player)     //can b;ock steal of another captain
    {

    }
}