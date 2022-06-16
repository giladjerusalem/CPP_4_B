
#include <iostream>
#include <string>
#include <vector>

#include "Game.hpp"



using namespace std;

namespace coup
{   
    Game::Game()    //constructor
    {
        active=false;
        turn_number=0;
        totalPLayers = 0;
    }

    string Game::turn()//reurn the name of the player who need to play 
    {
        for (Player *p : this->allPlayers)
        {
            if (p->turn)
            {
                return p->player_name;
            }
        }
        return "none";
    }

    vector<string> Game::players()
    {
        if (this->allPlayers.empty())
        {
            throw out_of_range("no players in game");
        }
        vector<string> allNames;
        for (Player *p : this->allPlayers)
        {
            if (p->isActive)
            {
                allNames.push_back(p->player_name);
            }
        }
        return allNames;
    }

    string Game::winner()   //return the winner, if the game active - > ERROR
    {
        if (!this->active || this->totalPLayers > 1)
        {
            throw std::invalid_argument("there is no winner");
        }
        for (Player *p : this->allPlayers)
        {
            if (p->isAlive)
            {
                return p->player_name;
            }
        }
        return "none";
        
    }

    void Game::add_player (Player* player){
        if(this->active){
            throw runtime_error("game started");
        }
        const int six = 6;
        if(this->allPlayers.size() == six ){
            throw runtime_error("this game limited to 6 players");
        }
        this->allPlayers.push_back(player);
        const int zero = 0;
        if(totalPLayers == zero){
            this->allPlayers[0]->turn = true;

        }
        totalPLayers++;
    }

    // void Game::remove_player (string name){
    //     // for(int i=0; i<names.size(); i++){
    //     //     if(name.compare(names[(size_t)i])){
    //     //         names.erase(names.begin()+i);
    //     //         money.erase(money.begin()+i);
    //     //     }
    //     // }
    // }

    // int Game::get_money (string name){
    //     // for(size_t i=0; i<names.size(); i++){
    //     //     if(name.compare(names[i])){
    //     //         return money[i];
    //     //     }
    //     // }
    //     // throw;
    // }

    // void Game::set_money (string name, int amount){
    // // for(size_t i=0; i<names.size(); i++){
    // //     if(name.compare(names[i])){
    // //         money[i]+=amount;
    // //     }
    // // }
    // // throw;
    // }

    void Game::set_active (){
        active=false;
    }

    void Game::set_turn(){
        this->active = true;
        this->allPlayers[(size_t)(turn_number % (int)this->allPlayers.size())]->turn = false;
        //cout << "tn: " << (turn_number % (int)this->allPlayers.size()) << endl;
        turn_number++;
        while(!this->allPlayers[(size_t)(turn_number % (int)this->allPlayers.size())]->isActive){
            //cout << "tn: " <<  (turn_number % (int)this->allPlayers.size()) << endl;
            
            this->allPlayers[(size_t)(turn_number % (int)this->allPlayers.size())]->isAlive = false;
            turn_number++;

        }
        this->allPlayers[(size_t)(turn_number % (int)this->allPlayers.size())]->turn = true;
    }
}