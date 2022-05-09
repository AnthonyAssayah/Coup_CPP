#pragma once
#include "Player.hpp"

using namespace std;

namespace coup {

    class Assassin: public Player {

        private:
            Player *last_coup;

        public:
            Assassin(Game &g, string name_player);
            void coup(Player &player);
            string role();
            int coins ();
            Player &get_last_coup();
           
    };
}