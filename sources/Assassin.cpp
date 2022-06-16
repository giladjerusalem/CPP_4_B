#include <iostream>
#include <string>

#include "Assassin.hpp"




using namespace std;

namespace coup
{
    Assassin::Assassin(Game &game, string player_name) : Player(game, std::move(player_name), "Assassin")    //constructor
    {
        
    }

    void Assassin::coup (Player &player){    //coup of 3 coins
        const int three = 3;
        const int seven = 7;
        //cout << "is this turn?? " << this->turn << endl;
        if(game->totalPLayers <= 1){
            throw std::runtime_error("there is only 1 player at the game");
        }
        if(!this->turn){
            throw std::invalid_argument("not your turn!");
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
        if(this->coin <three){
             throw runtime_error("havan't enough money");
             return; 
        }
        if(this->coin >=seven){
            player.isAlive = false;
            player.isActive = false;
            this->coin-=seven;
            this->lastAction = "coup";
        }
        else if(this->coin <seven && this->coin >=three){
            player.isActive = false;
            this->coin-=three;
            this->lastAction = "coupS";
        }
        
        this->lastActionTarget = &player;
        game->totalPLayers--;
        game->set_turn();

    }
}