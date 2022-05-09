#pragma once
#include "Player.hpp"

namespace coup {

    class Contessa: public Player {

        public:
            Contessa(Game &g, string name_player);
            void block(Player &player);
            string role();
            int coins ();


    };
}