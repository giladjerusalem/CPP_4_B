#include <iostream>
#include <string>
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Game.hpp"
using namespace std;

namespace coup
{
    Ambassador::Ambassador(Game &game, string name) : Player(game, name, "Ambassador")
    {
        
    }

    void Ambassador::transfer(Player &player_1, Player &player_2) //can transfer one coin from one player to another
    {
        game.set_money(player_1.player_name, -1);
        game.set_money(player_2.player_name, 1);
    }
    
    void Ambassador::block(Player &player)  //can block steal from captain
    {

    }
}