#pragma once
#include <iostream>
#include <vector>


using namespace std;


namespace coup {

    
    class Player;
    class Game {

        public:
            vector<Player*> players_name;
            Player* curr_player;
            unsigned long curr_winner;
            size_t index_player = 0;
            bool game_status;
          
            Game();
            void next_turn();
            string turn();
            vector<string> players();
            string winner();
            size_t add_player(Player *new_player);
            void remove_player(Player *removed_player);
            void get_player_back(Player *player_back);

      

           
    };
}