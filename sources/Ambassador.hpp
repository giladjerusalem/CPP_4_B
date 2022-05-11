#include <iostream>
#include <string>
#include <vector>

#include "Player.hpp"
#include "Game.hpp"



using namespace std;

namespace coup
{
    class Ambassador : public Player
    {
        public:
            Ambassador(Game &game, string);
            void transfer(Player &player1, Player &player2);
            void block(Player &player);
    };
}