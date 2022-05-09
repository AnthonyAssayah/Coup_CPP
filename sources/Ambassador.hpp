#pragma once
#include "Player.hpp"

namespace coup {

    class Ambassador: public Player {

        public:
            Ambassador(Game& game, string name_player);
            void transfer(Player &p1, Player &p2);
            void block(Player &player);
            string role();
            int coins ();
            
    };
}