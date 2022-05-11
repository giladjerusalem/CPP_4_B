#include <iostream>
#include <string>

#include "Player.hpp"


using namespace std;

namespace coup
{
    class Duke : public Player
    {
    public:
        Duke(Game &game, string);
        void tax();
        void block(Player &player);
    };
}