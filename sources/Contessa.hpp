#include <iostream>
#include <string>
#include <vector>

#include "Player.hpp"
#include "Game.hpp"


using namespace std;

namespace coup
{
    class Contessa : public Player
    {
        public:
            Contessa(Game &game, string);
            void block(Player &player);
    };
}