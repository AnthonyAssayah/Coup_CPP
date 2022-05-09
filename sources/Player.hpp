#pragma once
#include "Game.hpp"
#include <iostream>
#include <vector>

using namespace std;

namespace coup {

    class Player {


        public:
            Game *game;
            string player_role;
            string name_player;
            string last;
            bool is_alive;
            int money;
            size_t position;
           

        public:
           
            Player(Game& g, string name);
            string get_playerName() const;
            void income();
            void foreign_aid();
            virtual void coup(Player &player);
            virtual string role();
            int coins() const;
            bool isPlaying() const;
            void incrementCoins(int increment);
    };
}