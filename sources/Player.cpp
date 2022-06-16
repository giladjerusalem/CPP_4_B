#include <iostream>
#include <string>

#include "Player.hpp"
#include "Game.hpp"


using namespace std;

using namespace coup;

    Player::Player(Game &game, string player_name, string role)    //constructor
    {
    
        this->game=&game;
        this->player_name=std::move(player_name);
        this->the_role=std::move(role); 
        turn = false;
        this->lastAction = "";
        this->lastActionTarget = NULL;  
        this->isActive = true;
        this->isAlive = true;
        this->coin = 0;
        this->game->add_player(this);
    }

    void Player::income()   //1 coin - no interupt
    {
        if(game->totalPLayers <= 1){
            throw std::runtime_error("there is only 1 player at the game");
        }
        if(!turn){
                throw std::invalid_argument("not your turn!"); 
        }

        if(!this->isAlive || !this->isActive){
            throw std::invalid_argument("you are no active!");  
        }

        this->lastAction = "income";
        this->lastActionTarget = NULL;
        this->coin++;
        this->game->set_turn();
    }

    void Player::foreign_aid()  //2 coins - with interupt, other player can block
    {
        const int ten = 10;

        if(game->totalPLayers <= 1){
            throw std::runtime_error("there is only 1 player at the game");
        }
        if(!this->isAlive || !this->isActive){
            throw std::invalid_argument("you are no active!");  
        }
        if(!turn){
                throw std::invalid_argument("not your turn!"); 
        }
        if(this->coin >=ten){
            throw std::runtime_error("must coup");
        }


        this->lastAction = "foreign_aid";
        this->lastActionTarget = NULL;
        this->coin+=2;
        this->game->set_turn();
    }

    void Player::coup(Player &player)   //which player to kick out of game, cost of 7 coins.
    {
        if(game->totalPLayers <= 1){
            throw std::runtime_error("there is only 1 player at the game");
        }
        if(!this->isAlive || !this->isActive){
            throw std::invalid_argument("you are no active!");  
            return; 
        }
        if(!(player.isActive && player.isAlive)){
            throw std::invalid_argument("player is not active");
            return;
        }

        if(!turn){
            throw std::invalid_argument("not your turn!");
            return; 
        }
        const int seven = 7;
        if(this->coin < seven){
                throw std::invalid_argument("not enough coins!");
                return; 
        }
        for(Player* p : this->game->allPlayers){
            if(p->player_name == player.player_name){
                p->isActive = false;
                break;
            }
        }
        this->coin-=seven;
        this->lastAction = "coup";
        this->lastActionTarget = &player;
        game->totalPLayers--;
        game->set_turn();
    }

    string Player::role() const   //func who return as a string the role of each player
    {
        return the_role;
    }

    int Player::coins() const //return the amount of coins the player have
    {
        return this->coin;
    }

    
    