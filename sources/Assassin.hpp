#include <iostream>
#include <string>
#include <vector>

#include "Player.hpp"
#include "Game.hpp"


using namespace std;

namespace coup
{
    class Assassin : public Player
    {
        public:
            Assassin(Game &game, string);
            void coup (Player &player);
    };
}