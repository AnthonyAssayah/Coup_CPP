#include "Contessa.hpp"
#include "Assassin.hpp"

using namespace std;

namespace coup {

    Contessa::Contessa(Game& game, string name_player) : Player(game,std::move(name_player)){
        this->player_role = "Contessa";
    }
    
    void Contessa::block(Player &player){

        if (!this->is_alive) {
            throw invalid_argument("Error, the player is not in the game!");
        }

        if( player.player_role != "Assassin") {

            throw std::runtime_error("Error, Contessa cannot block them!");
        }

        if( player.player_role == "Assassin" && player.last != "coup3") {

            throw std::runtime_error("Error, Contessa cannot block not coup3 operation on Assassin!");

        }

        Assassin *block = dynamic_cast<Assassin *>(&player);
        block->get_last_coup().is_alive = true; 


    }

    string Contessa::role(){
        return "Contessa";
    }
    int Contessa::coins(){
        return this->money;
    } 
}

     