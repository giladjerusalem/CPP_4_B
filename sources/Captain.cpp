#include <iostream>
#include <string>

#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"


using namespace std;

namespace coup
{
    Captain::Captain(Game &game, string player_name) : Player(game, std::move(player_name), "Captain")   //constructor
    {
        this->the_role = "Captain";
    }

    void Captain::steal(Player &player)     //can steal 2 coins, can be blocked by captain \ ambassador
    {
        if(game->totalPLayers <= 1){
            throw std::runtime_error("there is only 1 player at the game");
        }
        if(!turn){
            throw std::invalid_argument("not your turn!");
            return;
        }
        if(!(player.isActive && player.isAlive)){
            throw std::invalid_argument("player is not active");
            return;
        }
        if(player.coin >=2 ){
            player.coin-=2;
            this->coin +=2;
        }
        else if(player.coin ==1){
            player.coin-=1;
            this->coin +=1;
        }
        this->lastAction = "steal";
        this->lastActionTarget = &player;
        game->set_turn();
    }
    
    void Captain::block(Player &player)     //can b;ock steal of another captain
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