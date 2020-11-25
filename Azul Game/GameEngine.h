#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#define MAX_FACTORIES 6
#define CENTER_FACTORY 0

#define MAX_ROUNDS 5

#define SEPERATOR '\n'

#include "Bag.h"
#include "Player.h"
#include "Factory.h"
#include "Lid.h"

#include <iostream>
#include <array>
#include <fstream>


class GameEngine {
    public:

        GameEngine();

        ~GameEngine();

        // Responsible for running and calling upon the entire game engine logic.
        void runMenuInterface();

    private:
        Bag bag;
        Lid lid;
        
        Player player1;
        Player player2;

        std::array<Factory, MAX_FACTORIES> factories;

        std::vector<std::string> turns;
        

        unsigned int factoryChoice;
        char tileChoice;
        unsigned int storageChoice;

        

        // Displays the menu options.
        void displayMenu() const;

        // Handles logic of user input.
        void navigateMenu();

        // Displays the credits and then prompts the user to select from menu.
        void displayCredits();

        // Starts a new game of Azul.
        void newGame();

        // Loads an existing game of Azul.
        void loadGame();

        // Prints all the factories and what tiles they currently hold, if any.
        void displayFactories() const;
    
        void promptTurnInput(Player player);

        bool validateFactory(const std::string factoryInput);

        bool validateTile(const std::string tileInput);

        bool validateStorage(const std::string storageInput);

        void updateMosaic(Player& player);

        // Takes the tiles from the storage area and places them onto the player's mosaic where appropriate.
        void layTiles(Player& player);

        void tallyPoints(Player& player, unsigned int i, unsigned int rowCounter);

        void clearMosaic(Player& player);

        void fillFactories();

        void lidToBag();

        void saveGameState(const std::string fileName);
        
};


#endif // GAMEENGINE_H