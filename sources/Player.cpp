#include <iostream>
#include <string>

#include "Player.hpp"
#include "Game.hpp"


using namespace std;

using namespace coup;

    Player::Player(Game &game, string player_name, string role)    //constructor
    {
     this->game=game;
     this->player_name=player_name;
     this->the_role=role;   
    }

    void Player::income()   //1 coin - no interupt
    {
        game.set_money(player_name, 1);
    }

    void Player::foreign_aid()  //2 coins - with interupt, other player can block
    {
        game.set_money(player_name, 2);     //check if blocked

    }

    void Player::coup(Player &player)   //which player to kick out of game, cost of 7 coins.
    {
        if (the_role.compare("Assassin")){
            if (game.get_money(player_name)>=3)
            {
                game.remove_player(player.player_name);
                game.set_money(player_name, -3);
            }
        }
        else{
            if (game.get_money(player_name)>=7)     //if you not assassin
            {
                game.remove_player(player.player_name);
                game.set_money(player_name, -7);
            }  
        }
    }

    string Player::role()   //func who return as a string the role of each player
    {
        return the_role;
    }

    int Player::coins() //return the amount of coins the player have
    {
        return  game.get_money(player_name);
    }

    
    