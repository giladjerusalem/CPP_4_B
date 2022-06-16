#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Player;
    class Game
    {
        private:
            
            int turn_number;
            

        public:
            bool active;
            vector<Player*> allPlayers; //int->turn, player->who turn is
            int totalPLayers;
            Game();
            string turn();
            vector<string> players();
            
            string winner();

            void add_player (Player*); 
            //void remove_player (string);
            //int get_money (string );
            //void set_money (string, int);
            void set_active ();
            void set_turn();
    };
}
