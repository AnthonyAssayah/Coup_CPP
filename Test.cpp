#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>


using namespace std;
using namespace coup;

TEST_CASE("Create a new game") {

    Game game1{};

    Captain captain{game1, "Anthony"};
	Ambassador ambassador{game1, "Bar"};
	Assassin assassin{game1, "Itamar"};
    Duke duke{game1, "Lior"};
	Contessa contessa{game1, "Roni"};
    Duke duke1{game1, "Nir"};

        SUBCASE("Checking the who's the next player in the game") {
            CHECK(game1.turn() == "Anthony");
            CHECK_NOTHROW(captain.income());
            CHECK(game1.turn() == "Bar");
            CHECK_NOTHROW(ambassador.income());
            CHECK(game1.turn() == "Itamar");

            CHECK_THROWS(captain.income()); // because its not his turn
            CHECK_THROWS(duke1.income());
            CHECK_THROWS(ambassador.income());
        }


        SUBCASE("Checking roles of players") {
            CHECK_EQ(duke.role(), "Duke");
            CHECK_EQ(ambassador.role(), "Ambassador");
            CHECK_EQ(assassin.role(), "Assassin");
            CHECK_NE(duke.role(), "Duke");
            CHECK_NE(contessa.role(), "Contessa");

        }

        SUBCASE("checking coins amount"){
            CHECK_EQ(captain.coins(), 1);
            CHECK_EQ(ambassador.coins(), 1);
            CHECK_NOTHROW(assassin.income());
            CHECK_EQ(assassin.coins(), 1);
            CHECK_NOTHROW(duke.income());
            CHECK_EQ(duke.coins(), 1);
            CHECK_NOTHROW(contessa.income());
            CHECK_EQ(contessa.coins(), 1);

            
            
        }
}


