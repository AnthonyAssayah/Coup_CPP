#include <iostream>
#include "Player.hpp"
#include <stdexcept>
#include <vector>

const short MAX_COINS = 10;
const short COUP_PRICE = 7;

using namespace std;

namespace coup {

    Player::Player(Game & g, string name){

        this->game = &g;
        this->name_player = std::move(name);
        this->money = 0;
        this->is_alive = true;
        position = g.add_player(this);

    }

    string Player::get_playerName() const{
        return name_player;
    }

    void Player::income(){

        if (!this->is_alive) {
            throw invalid_argument("Error, the player is not in the game!");
        }
        if (this->game->turn() != this->get_playerName()) {
            throw invalid_argument("This is not your turn! ");
        }

        if (this->game->players_name.size() == 1) {
            throw invalid_argument("Error, cannot play with only 1 player!");
        }
        if (this->coins() >= MAX_COINS) {
            throw invalid_argument("Error, the player must coup!");
        }

       this->money += 1;
       this->last = "income";
       this->game->next_turn();
       cout << this->player_role << ": "<< this->name_player <<" did income" << endl;

    }

    void Player::foreign_aid(){
      
        if (!this->is_alive) {
            this->game->next_turn();
        }

        if (this->game->turn() != this->get_playerName()) {
            throw invalid_argument("This is not your turn! ");
        }
        if (this->game->players_name.size() == 1) {
            throw invalid_argument("Error, cannot play with only 1 player!");
        }
        if (this->coins() >= MAX_COINS) {
            throw invalid_argument("Error, the player must coup!");
        }
        this->money += 2;
        this->last = "foreign_aid";
        this->game->next_turn();
        cout << this->player_role << " did foreign_aid" << endl;
       
    }

    void Player::coup(Player &player) {

        if (!this->is_alive || !player.is_alive) {
            throw invalid_argument("Error, the player is not in the game!");
        }
        if (this->game->turn() != this->get_playerName()) {
            throw invalid_argument("This is not your turn! ");
        }
        if (this->money < COUP_PRICE) {
            throw std::runtime_error("Error, the player has not enough coins!");
        }
    
        this->money -= COUP_PRICE;
        this->last = "coup";
        player.is_alive = false;
        this->game->next_turn();
        cout << this->player_role << " did coup" << endl;
        cout << "The player : " << player.role() << "  " << player.get_playerName() << " has been removed from the game by coup()" << endl;
        
    }


    string Player::role() {
        return this->player_role;
    }

    int Player::coins() const{
        return this->money;
    }

    void Player::incrementCoins(int increment) {
        this->money+=increment;
}
    

}