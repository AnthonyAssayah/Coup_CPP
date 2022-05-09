#include "Assassin.hpp"

const short COUP_PRICE = 7;

using namespace std;

namespace coup {

    Assassin::Assassin(Game &g, string name_player) : Player(g,std::move(name_player)){
        this->player_role = "Assassin";
        this->last_coup = nullptr;
    }

    void Assassin::coup(Player &player) {


        if (!this->is_alive || !player.is_alive) {
            throw invalid_argument("Error, the player is not in the game!");
        }
     
        if (this->game->turn() != this->get_playerName()) {
            throw invalid_argument("This is not your turn! ");
        }
        if (this->coins() < 3) {
            throw invalid_argument("Error, you need more coins for coup() !");
        }
        
        if(this->coins() >= COUP_PRICE) {
            

            Player::coup(player);
        }
        else {
            this->money -=3;
            this->last = "coup3";
            player.is_alive = false;
            last_coup = &player;
            cout << this->player_role << " did coup" << endl;
            cout << "The player : " << player.role() << "  " << player.get_playerName() << " has been removed from the game by coup()" << endl;
            this->game->next_turn();

        }

    }
  
    string Assassin::role(){
        return "Assassin";
    }
    int Assassin::coins(){
        return this->money;
    } 

    Player &Assassin::get_last_coup(){
        return *last_coup;
    }

}