#pragma once
#include "Player.hpp"

namespace coup {

    class Captain: public Player {

        public:
            Player * last_steal;
            Captain(Game& game, string name_player);
            void block(Player &player);
            void steal(Player &player);
            string role();
            int coins ();
            
    };
}