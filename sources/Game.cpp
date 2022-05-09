#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include <stdexcept>
#include <vector>

const short MAX_PLAYERS = 6;
 
using namespace std;

namespace coup {

    Game::Game(){
        game_status = false;
        curr_player = nullptr;
        curr_winner = 0;
        
    }

    string Game::turn() {

        string turn = this->players_name.at(this->index_player)->get_playerName();
        return turn;
 
    }
    
    vector<string> Game::players(){
       
        vector<string> names_of_players;

        for(size_t i = 0; i < this->players_name.size(); i++) {
    
            if (players_name.at(i)->is_alive) {
                names_of_players.push_back(players_name.at(i)->get_playerName());
            }
        } 
        return names_of_players;
    }


    size_t Game::add_player(Player *new_player) {
        if (this->game_status) {
            throw invalid_argument("Error, the game already started!");
        }

        if (players_name.size() == MAX_PLAYERS ) {
            throw logic_error("Error, you cannot add more players in this game!");
        }
   
        players_name.push_back(new_player);
        return players_name.size()-1;
    
    }

    void Game::remove_player(Player *removed_player){
        
        for(size_t i = 0; i < this->players_name.size(); i++) {

            if (players_name.at(i)== removed_player){
                players_name[i] = nullptr;
                break;
            }
        }
      
    }

    void Game::get_player_back(Player *player_back) {

        if (players_name.at(player_back->position)==nullptr) {
                players_name[player_back->position] = player_back;
        } 
    }

    void Game::next_turn(){

        game_status = true;

        do {
            index_player = (index_player+1)%players_name.size();
        } while (!(players_name.at((index_player)%players_name.size())->is_alive));
        curr_player=players_name.at(index_player);
     
    }


    string Game::winner() {


        size_t num_of_player = 0;
        size_t winner_index = 0;
        for (size_t i = 0; i < players_name.size(); i++) {
            if (players_name.at(i)->is_alive) {
                cout << "PLAYER : " << players_name.at(i)->get_playerName() << endl;
                num_of_player++;
                winner_index = i;
            }
        }
        if (num_of_player > 1 || !this->game_status) {
            throw invalid_argument("Error, the game is not finished yet!");
        }
    
        return this->players_name.at(winner_index)->get_playerName();

    }
}
