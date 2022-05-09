#include "Duke.hpp"

const short MAX_COINS = 10;

using namespace std;

namespace coup {

    Duke::Duke(Game &game, string name_player) : Player(game,std::move(name_player)){
        this->player_role = "Duke";
    }

    void Duke::tax() {

        if (!this->is_alive) {
            this->game->next_turn();
        }

        if (this->game->turn() != this->get_playerName()) {
            throw invalid_argument("This is not your turn! ");
        }

        if (this->coins() >= MAX_COINS) {
            throw invalid_argument("Error, you must 'coup' !");
        }
        this->money += 3;
        this->last = "tax";
        cout << this->player_role << " did tax" << endl;
        this->game->next_turn();
    }
    
    void Duke::block(Player &player){

        if (player.last == "foreign_aid") {
            player.money -= 2;
            this->coins();
        }

        else{
            throw invalid_argument("maniyak");
        }
    }

    string Duke::role(){
        return this->player_role = "Duke";
    }
    int Duke::coins(){
        return this->money;
    } 

       
}