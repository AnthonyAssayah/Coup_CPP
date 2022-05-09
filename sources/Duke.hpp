#pragma once
#include "Player.hpp"

using namespace std;

namespace coup {

    class Duke: public Player {

        public:
            Duke(Game &g, string name_player);
            void tax();
            void block(Player &player);
            string role();
            int coins ();

    };
}

