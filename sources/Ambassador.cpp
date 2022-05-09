#include "Ambassador.hpp"
#include "Captain.hpp"

const short MAX_COINS = 10;

using namespace std;

namespace coup {

    Ambassador::Ambassador(Game& game, string name_player) : Player(game,std::move(name_player)){
        this->player_role = "Ambassador";
    }

    void Ambassador::transfer(Player &p1,Player &p2){

        if (this->game->turn() != this->get_playerName()) {
            throw invalid_argument("This is not your turn! ");
        }
        if (this->coins() >= MAX_COINS) {
            throw invalid_argument("Error, the player must coup!");
        }
        // if p1 doesn't have money throw exception
        if (p1.coins() < 1) {
            throw invalid_argument("Error, p1 doesn't have enough coins! ");
        }
        // else transfer 1 coin from p1 to p2
        p1.money -= 1;
        p2.money += 1;
        this->last = "transfer";
        this->game->next_turn();
    }
    
    void Ambassador::block(Player &player){

        
        Captain *block = dynamic_cast<Captain*> (&player);
        if(player.role() == "Captain" && player.last == "steal") {

            block->last_steal->money += 2;
            block->money -=2;
            this->coins();
            
        }
        else {
            throw invalid_argument("Error, you cannot block them!");
        }
    }

    string Ambassador::role(){
        return this->player_role = "Ambassador";
    }
    int Ambassador::coins(){
        return this->money;
    } 



}