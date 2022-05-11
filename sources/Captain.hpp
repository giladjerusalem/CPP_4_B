#include <iostream>
#include <string>
#include <vector>

#include "Player.hpp"
#include "Game.hpp"


using namespace std;

namespace coup
{
    class Captain : public Player
    {
        public:
            Captain(Game &game, string);
            void steal(Player &player);
            void block(Player &player);
    };
}