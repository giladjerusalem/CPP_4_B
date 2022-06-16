#include <iostream>
#include <string>

#include "Duke.hpp"


using namespace std;

namespace coup
{
    Duke::Duke(Game &game, string player_name) : Player(game, std::move(player_name), "Duke")    //constructor
    {
        
    }

    void Duke::tax()    //can take tax of 3 coins from the cashier
    {
        const int ten=10; 
        const int one=1;
        if(game->totalPLayers <= 1){
            throw std::runtime_error("there is only 1 player at the game");
        }
        if(!turn){
            throw std::invalid_argument("not your turn!"); 
            return;
        }
        if(this->game->allPlayers.size()<=one){
            throw std::invalid_argument( "cant play with 1 player or less!" );
            return;   
        }
        if(this->coin>=ten){
            throw std::invalid_argument("you have to do coup!"); 
            return;
        }
        if(!this->isAlive || !this->isActive){
            throw std::invalid_argument("you are no active!");
            return;  
        }
        
        this->coin+=3;
        this->lastAction = "tax";
        this->lastActionTarget = NULL;
        this->game->set_turn(); 
    }
    
    void Duke::block(Player &player)    //can block player income
    {
        if(player.lastAction != "foreign_aid"){
            throw runtime_error("player last action was not foreign aid");
        }
        if(!(this->isActive && this->isAlive && player.isAlive && player.isActive)){
            throw runtime_error("one of the players isnt active anymore");
        }
        player.coin-=2;
    }
}