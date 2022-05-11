#include <iostream>
#include <string>
#include <vector>

#include "Game.hpp"



using namespace std;

namespace coup
{   
    Game::Game()    //constructor
    {
        active=true;
        turn_number=0;
    }

    string Game::turn()//reurn the name of the player who need to play 
    {
        return "player_name";
    }

    vector<string> Game::players()  //the players who active in the game 
    {
        vector<string> arr{"player_1", "player_2", "player_3", "player_4", "player_5"};
        return arr;
    }

    string Game::winner()   //return the winner, if the game active - > ERROR
    {
        return "player_name";
    }

    void Game::add_player (string name){
        names.push_back(name);
        money.push_back(0);
    }

    void Game::remove_player (string name){
        for(int i=0; i<names.size(); i++){
            if(name.compare(names[(size_t)i])){
                names.erase(names.begin()+i);
                money.erase(money.begin()+i);
            }
        }
    }

    int Game::get_money (string name){
        for(size_t i=0; i<names.size(); i++){
            if(name.compare(names[i])){
                return money[i];
            }
        }
        throw;
    }

        void Game::set_money (string name, int amount){
        for(size_t i=0; i<names.size(); i++){
            if(name.compare(names[i])){
                money[i]+=amount;
            }
        }
        throw;
    }

    void Game::set_active (){
        active=false;
    }

    void Game::set_turn(){
        turn_number++;
    }
}