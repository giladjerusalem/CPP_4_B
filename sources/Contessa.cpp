#include <iostream>
#include <string>

#include "Contessa.hpp"


using namespace std;

namespace coup
{
    Contessa::Contessa(Game &game, string player_name) : Player(game, std::move(player_name), "Contessa")    //constructor
    {
        
    }
    
    void Contessa::block(Player &player)    //can block assasin
    {
        if(game->totalPLayers <= 1){
            throw std::runtime_error("there is only 1 player at the game");
        }
        if (player.role() != "Assassin")
        {
            throw runtime_error("Contessa can block only Assassin");
            return;
        }
        if (player.lastAction != "coupS")
        {
            throw runtime_error("You missed the block option");
            return;
        }
        if (player.lastActionTarget->isActive)
        {
            throw runtime_error("player is not couped");
            return;
        }
        if(!this->isAlive || !this->isActive){
            throw std::invalid_argument("you are no active!");
            return; 
        }
        if(!(player.isActive && player.isAlive)){
            throw std::invalid_argument("player is not active");
            return;
        }
        player.lastActionTarget->isActive = true;
        game->totalPLayers++;
    }



}