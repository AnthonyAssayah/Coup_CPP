#include "Captain.hpp"

const short MAX_COINS = 10;

using namespace std;

namespace coup {

    Captain::Captain(Game& game, string name_player) : Player(game,std::move(name_player)){
        this->player_role = "Captain";
        this->last_steal = nullptr;
    }

    void Captain::block(Player &player){

        if(player.last == "income") {

            throw std::runtime_error("Error, 'income' operation cannot be blocked by any role!");

        }
        
        if(player.role() == "Captain" && player.last == "steal") {

            this->coins();
        }
    }

    void Captain::steal(Player &player){

        if (!this->is_alive) {
            this->game->next_turn();
        }

        if (this->game->turn() != this->get_playerName()) {
            throw invalid_argument("This is not your turn! ");
        }
        
        if (this->coins() >= MAX_COINS) {
            throw invalid_argument("Error, the player must coup!");
        }

        // if player doesn't have money throw exception
        if (player.coins() == 0) {
            throw invalid_argument("Error, player doesn't have enough coins! ");
        }
        // else if player have only 1 coin, stole him it
        if ( player.coins() == 1) {
            player.money -= 1;
            this->money += 1;
            this->last = "steal";
            this->game->next_turn();
        }
        // else stole him 2 coins
        else {
            player.money -= 2;
            this->money += 2;
            this->last = "steal";
            this->game->next_turn();

        }
        last_steal = &player;
        
    }
    
    string Captain::role(){
        return this->player_role = "Captain";
    }

    int Captain::coins(){
        return this->money;
    }

}