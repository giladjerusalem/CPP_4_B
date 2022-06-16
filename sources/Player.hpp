#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Game.hpp"


using namespace std;

namespace coup
{
    class Game;
    class Player
    {
        // private:
            // Game game;
            // string player_name;
            // string the_role;

        public:
            Player(Game &game, string, string);
            Game* game;
            string player_name;
            string the_role;
            void income();
            void foreign_aid();
            void coup(Player &player);
            string role() const;
            int coin;
            int coins() const;

            string lastAction;
            Player* lastActionTarget;
            bool isAlive;
            bool isActive;
            bool turn;
    };
}