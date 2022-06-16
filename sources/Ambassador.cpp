#include <iostream>
#include <string>
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Game.hpp"
using namespace std;

namespace coup
{
    Ambassador::Ambassador(Game &game, string name) : Player(game, std::move(name), "Ambassador")
    {
        
    }

    void Ambassador::transfer(Player &player_1, Player &player_2) //can transfer one coin from one player to another
    {
        if(game->totalPLayers <= 1){
            throw std::runtime_error("there is only 1 player at the game");
        }
        if(!turn){
            throw std::invalid_argument("not your turn!"); 
        }
        if(!(player_1.isActive && player_1.isAlive && player_2.isAlive && player_2.isActive)){
            throw runtime_error("one of the players isnt active anymore");
        }
        if (player_1.coins() > 0)
        {
            player_1.coin--;
            player_2.coin++;
        }
        else
        {
            throw std::logic_error("not enought coins to steal");
        }
        game->set_turn();
    }
    
    void Ambassador::block(Player &player)  //can block steal from captain
    {
        if(game->totalPLayers <= 1){
            throw std::runtime_error("there is only 1 player at the game");
        }
        if(player.role() != "Captain"){
            throw runtime_error("can block only another captain");
            return;
        }
        if(player.lastAction != "steal"){
            throw std::runtime_error("last action wasnt staling..");
            return;
        }
        if(!this->isAlive || !this->isActive){
            throw std::invalid_argument("you are no active!"); 
            return; 
        }
        player.coin-=2;
        player.lastActionTarget->coin+=2;
    }
}