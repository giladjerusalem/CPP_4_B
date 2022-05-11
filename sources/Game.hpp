#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;

namespace coup
{
    class Game
    {
        private:
            vector<string> names; //int->turn, player->who turn is
            vector<int> money; //int->turn, player->who turn is
            bool active;
            int turn_number;

        public:
            Game();
            string turn();
            vector<string> players();
            string winner();

            void add_player (string); 
            void remove_player (string);
            int get_money (string );
            void set_money (string, int);
            void set_active ();
            void set_turn();
    };
}

#endif