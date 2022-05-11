#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>

#include "Game.hpp"


using namespace std;

namespace coup
{
    class Player
    {
        // private:
            // Game game;
            // string player_name;
            // string the_role;

        public:
            Player(Game &game, string, string);
            Game game;
            string player_name;
            string the_role;
            void income();
            void foreign_aid();
            void coup(Player &player);
            string role();
            int coins();
    };
}

#endif