#include "GameEngine.h"

GameEngine::GameEngine() {

    std::cout << "Welcome to Azul!\n";
    std::cout << "-------------------\n\n";

    //fillFactories();
}

GameEngine::~GameEngine() {}

void GameEngine::displayMenu() const {
    std::cout << "Menu\n";
    std::cout << "----\n";
    std::cout << "1. New Game\n";
    std::cout << "2. Load Game\n";
    std::cout << "3. Credits\n";
    std::cout << "4. Quit\n";

    std::cout << '\n';
}

void GameEngine::navigateMenu() {

    bool invalidInput = true;
    std::string input;
    
    while (invalidInput) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "1" || input == "2" || input == "3" || input == "4") {
            invalidInput = false;
        } else {
            std::cout << "Invalid Input" << '\n';
        }
    }

    if (input == "1") {
            newGame();
        } else if (input == "2") {
            loadGame();
        } else if (input == "3") {
            displayCredits();
        } else if (input == "4") {
            std::cout << "Quitting...\n";
        }

}

void GameEngine::displayCredits() {
    // Group member 1:
    std::cout << "----------------------------------\n";
    std::cout << "Name: Tessa Podbury\n";
    std::cout << "Student ID: s3775931\n";
    std::cout << "Email: s3775931@student.rmit.edu.au\n";
    std::cout << "----------------------------------\n";

    // Group member 2:
    std::cout << "----------------------------------\n";
    std::cout << "Name: Frank Yousif\n";
    std::cout << "Student ID: s3791643\n";
    std::cout << "Email: s3791643@student.rmit.edu.au\n";
    std::cout << "----------------------------------\n";

    // Group member 3:
    std::cout << "----------------------------------\n";
    std::cout << "Name: Wyatt Jenkins\n";
    std::cout << "Student ID: s3770872\n";
    std::cout << "Email: s3770872@student.rmit.edu.au\n";
    std::cout << "----------------------------------\n";

    runMenuInterface();
}

void GameEngine::newGame() {
    // Enter code for newGame here...
    std::cout << "Starting a New Game" << '\n';
    std::cout << "Do you want to play a game where we mix the tiles?!\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";

    bool invalidInput = true;
    std::string input;
    
    while (invalidInput) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "1" || input == "2") {
            invalidInput = false;
        } else {
            std::cout << "Invalid Input" << '\n';
        }
    }

    if (input == "1")
    {
        this->bag.shuffleBag();
        fillFactories();
    }
    else{
            fillFactories();
    }
    

    std::cout << "\nEnter a name for player 1" << '\n' << "> ";
    std::string name;
    std::getline(std::cin, name);
    player1.setName(name);

    std::cout << "\nEnter a name for player 2" << '\n' << "> ";

    while (name == player1.getName()) {
        std::getline(std::cin, name);
        if (name == player1.getName()) {
            std::cout << "Name cannot be the same as player 1's name." << '\n';
            std::cout << "> ";
        }
    }

    player2.setName(name);

    std::cout << "\nLet's Play!" << "\n\n";


    // newRound() ???
    unsigned int roundCount = 0;
    unsigned int cumulativeTiles = 0;

    while (roundCount < MAX_ROUNDS) {

        // Checks to see if all factories are empty - if they are, the round ends
        for (Factory fact : this->factories) {
            cumulativeTiles = cumulativeTiles + fact.getTiles().size();
        }

        if (cumulativeTiles == 0) {
            std::cout << "=== END OF ROUND ===" << "\n\n";

            layTiles(player1);
            layTiles(player2);

            clearMosaic(player1);
            clearMosaic(player2);

            fillFactories();
            ++roundCount;
        

            std::cout << "=== Start Round ===" << "\n\n";
            std::cout << "Round " << roundCount + 1 << "\n\n";

        } else {

        // Player 1
        std::cout << "TURN FOR PLAYER: " << player1.getName() << '\n';
        displayFactories();
        std::cout << "\n\nMosaic for " << player1.getName() << '\n';
        player1.getMosaic().printMosaic();

        promptTurnInput(player1);
        updateMosaic(player1);

        std::cout << '\n';

        cumulativeTiles = 0;

        }



        // Checks to see if all factories are empty - if they are, the round ends
        for (Factory fact : this->factories) {
            cumulativeTiles = cumulativeTiles + fact.getTiles().size();
        }

        if (cumulativeTiles == 0) {
            std::cout << "=== END OF ROUND ===" << "\n\n";

            layTiles(player1);
            layTiles(player2);

            clearMosaic(player1);
            clearMosaic(player2);

            fillFactories();
            ++roundCount;

            std::cout << "=== Start Round ===" << '\n';
            std::cout << "Round " << roundCount + 1 << '\n';

        } else {

        // Player 2
        std::cout << "TURN FOR PLAYER: " << player2.getName() << '\n';
        displayFactories();
        std::cout << "\n\nMosaic for " << player2.getName() << '\n';
        player2.getMosaic().printMosaic();

        promptTurnInput(player2);
        updateMosaic(player2);

        std::cout << '\n';

        cumulativeTiles = 0;

        }

    }

}

void GameEngine::loadGame() {
    // Enter code for loadGame here...
}

void GameEngine::runMenuInterface() {

    displayMenu();
    navigateMenu();
}

void GameEngine::displayFactories() const {
    
    unsigned int counter = 0;
    
    std::cout << "Factories:" << '\n';
    for (const Factory fact : this->factories) {
        Factory f = fact;
        std::cout << counter << ": ";
        for (Tile tile : f.getTiles()) {
            std::cout << tile.getColourCode() << " ";
        }
        std::cout << '\n';
        ++counter;
    }
}

void GameEngine::promptTurnInput(Player player) {

    std::string input;
    std::vector<std::string> words;
    std::string word = "";

    bool invalidFactory = true;
    bool invalidTile = true;
    bool invalidStorage = true;
    bool invalidTurn = true;
    bool invalidPlacement = false;

    bool gameSaved = false;
    // 'Do' keep taking input from user until they enter a valid turn command.
    do {

        std::cout << "> ";
        std::getline(std::cin, input);

        for (char x : input) { 
            if (x == ' ') { 
                words.push_back(word); 
                word = ""; 
            } else { 
                word = word + x; 
            } 
        }

        words.push_back(word);
        word = "";


        const unsigned int COMMAND_ARGS = 4;
        if (words.size() != COMMAND_ARGS || words.at(0) != "turn") {

            if (words.at(0) == "save" && words.size() == 2) {
                saveGameState(words.at(1));

                invalidTurn = false;
                invalidFactory = false;
                invalidTile = false;
                invalidStorage = false;

                gameSaved = true;
                std::cout << "Game saved successfully as: " << words.at(1) << ".txt" << '\n';

            }

            words.clear();

        } else {

            invalidTurn = false;
            invalidFactory = !validateFactory(words.at(1));
            invalidTile = !validateTile(words.at(2));
            invalidStorage = !validateStorage(words.at(3));

            words.clear();

        }

        
        if (!(invalidFactory || invalidTile || invalidStorage || invalidTurn)) {

            // Checks to see if a laid tile of the same colour as the player chose exists on the Mosaic. If it does, the move is invalid.
            for (unsigned int i = 0; i < GRID_WIDTH; ++i) {
                if (player.getMosaic().getLaidAt(i, this->storageChoice - 1) == this->tileChoice) {
                    invalidPlacement = true;
                }
            }

            // Ensures that the player cannot add tiles of a different colour to a storage row where tiles of another colour already exist.
            for (unsigned int i = 0; i < GRID_WIDTH; ++i) {
                if (player.getMosaic().getStorageAt(i, this->storageChoice - 1) != '.' && player.getMosaic().getStorageAt(i, this->storageChoice-1) != ' ') {
                    if (player.getMosaic().getStorageAt(i, this->storageChoice - 1) != this->tileChoice) {
                        invalidPlacement = true;
                    }
                }
            }

        }

        if ((invalidFactory || invalidTile || invalidStorage || invalidTurn || invalidPlacement)) {
            std::cout << "Turn Unsuccessful. Try Again." << '\n';
        } else {
            turns.push_back(input);
        }

    }   while (invalidFactory || invalidTile || invalidStorage || invalidTurn || invalidPlacement);


    // True if all inputs from the user are valid.
    if (!(invalidFactory || invalidTile || invalidStorage || invalidTurn || invalidPlacement)) {
        if (gameSaved == false) {
            std::cout << "Turn Successful." << '\n';
        }
    }
}

bool GameEngine::validateFactory(const std::string factoryInput) {
    bool returnVal = false;


    if (factoryInput == "0") {
        this->factoryChoice = 0;
        returnVal = true;
    } else if (factoryInput == "1") {
        this->factoryChoice = 1;
        returnVal = true;
    } else if (factoryInput == "2") {
        this->factoryChoice = 2;
        returnVal = true;
    } else if (factoryInput == "3") {
        this->factoryChoice = 3;
        returnVal = true;
    } else if (factoryInput == "4") {
        this->factoryChoice = 4;
        returnVal = true;
    } else if (factoryInput == "5") {
        this->factoryChoice = 5;
        returnVal = true;
    }

    // Player cannot choose an empty factory.
    if (factories.at(this->factoryChoice).getTiles().size() == 0) {
        returnVal = false;
    }

    return returnVal;
}

bool GameEngine::validateTile(const std::string tileInput) {
    bool returnVal = false;
    if (tileInput == "B") {
        this->tileChoice = 'B';
        returnVal = true;
    } else if (tileInput == "Y") {
        this->tileChoice = 'Y';
        returnVal = true;
    } else if (tileInput == "R") {
        this->tileChoice = 'R';
        returnVal = true;
    } else if (tileInput == "U") {
        this->tileChoice = 'U';
        returnVal = true;
    } else if (tileInput == "L") {
        this->tileChoice = 'L';
        returnVal = true;
    }

    return returnVal;
}

bool GameEngine::validateStorage(const std::string storageInput) {
    bool returnVal = false;
    if (storageInput == "1") {
        this->storageChoice = 1;
        returnVal = true;
    } else if (storageInput == "2") {
        this->storageChoice = 2;
        returnVal = true;
    } else if (storageInput == "3") {
        this->storageChoice = 3;
        returnVal = true;
    } else if (storageInput == "4") {
        this->storageChoice = 4;
        returnVal = true;
    } else if (storageInput == "5") {
        this->storageChoice = 5;
        returnVal = true;
    }
    
    return returnVal;
}

void GameEngine::updateMosaic(Player& player) {

    std::vector<Tile> chosenTiles;
    std::vector<Tile> unchosenTiles;

    // Takes all the tiles from a factory (based on what the player has chosen) and stores them 
    // in temporary vectors - chosen and unchosen
    unsigned int factorySize = factories.at(this->factoryChoice).getTiles().size();
    for (unsigned int i = 0; i < factorySize; ++i) {

        if (factories.at(this->factoryChoice).getTiles().at(i).getColourCode() == this->tileChoice || factories.at(this->factoryChoice).getTiles().at(i).getColourCode() == 'F') {
            chosenTiles.push_back(factories.at(this->factoryChoice).getTiles().at(i));

        } else {

            unchosenTiles.push_back(factories.at(this->factoryChoice).getTiles().at(i));

        }
    }

    factories.at(this->factoryChoice).getTiles().clear();

    // Moves discarded tiles to the center factory.
    for (unsigned int i = 0; i < unchosenTiles.size(); ++i) {
        factories.at(0).getTiles().push_back(unchosenTiles.at(i));
    }

    unchosenTiles.clear();

    // Moves chosen tiles to the storage area.
    unsigned int counter = 0;
    for (unsigned int i = 0; i < GRID_WIDTH && counter < chosenTiles.size(); ++i) {
        if (player.getMosaic().getStorageAt(i, this->storageChoice - 1) == '.') {
            if (chosenTiles.at(counter).getColourCode() == 'F') {
                player.getMosaic().getBrokenTiles().push_back(Tile('F'));
                ++counter;
            } else {
                player.getMosaic().getStorageAt(i, this->storageChoice - 1) = chosenTiles.at(counter).getColourCode();
                ++counter;
            }
        }
    }

    // Moves any leftover tiles the player has chosen to the Broken Tiles area.
    while (counter < chosenTiles.size()) {
        player.getMosaic().getBrokenTiles().push_back(chosenTiles.at(counter));
        ++counter;
    }

    chosenTiles.clear();

}

void GameEngine::layTiles(Player& player) {

    bool filledRow = true;
    const unsigned int RIGHT_MOST_TILE = 4;


    unsigned int rowCounter = 0;
    while (rowCounter < GRID_HEIGHT) {

         // Checks to see if the row is filled or if there are empty spaces.
        for (unsigned int i = 0; i < MAX_TILES; ++i) {
            if (player.getMosaic().getStorageAt(i, rowCounter) == '.') {
                filledRow = false;
            }
        }
        
        // Moves the right-most tile of a filled row to the laid-tiles area of the player's mosaic. .....
        if (filledRow) {
            for (unsigned int i = 0; i < MAX_TILES; ++i) {
                if (player.getMosaic().getLaidAt(i, rowCounter) == '.') {
                    if (player.getMosaic().getPatternAt(i, rowCounter) == player.getMosaic().getStorageAt(RIGHT_MOST_TILE, rowCounter)) {
                        player.getMosaic().getLaidAt(i, rowCounter) = player.getMosaic().getStorageAt(RIGHT_MOST_TILE, rowCounter);

                        tallyPoints(player, i, rowCounter);
                        
                        player.getMosaic().getStorageAt(RIGHT_MOST_TILE, rowCounter) = '.';
                    }
                }
            }

            // Unplaced storage tiles are sent to the back of the tile bag.
            for (unsigned int i = 0; i < MAX_TILES; ++i) {
                if (player.getMosaic().getStorageAt(i, rowCounter) != '.' && player.getMosaic().getStorageAt(i, rowCounter) != ' ') {
                    this->bag.getTiles().addToBack(new Tile(player.getMosaic().getStorageAt(i, rowCounter)));
                    player.getMosaic().getStorageAt(i, rowCounter) = '.';
                }
            }

        }
        ++rowCounter;
    }
}

void GameEngine::tallyPoints(Player& player, unsigned int i, unsigned int rowCounter) {

    // Points ADDITION

    // ... (horizontal, vertical)
    int pointsToAdd = 1;
    unsigned int x = i;
    unsigned int y = rowCounter;

    // Check EAST
    while (x < GRID_WIDTH) {
        if (player.getMosaic().getLaidAt(x, y) != '.') {
            if (x != i || y != rowCounter) {
                pointsToAdd = pointsToAdd + 1;
            }
        }
        ++x;
    }

    // Check WEST
    x = i;
    while (x > 0) {
        if (player.getMosaic().getLaidAt(x, y) != '.') {
            if (x != i || y != rowCounter) {
                pointsToAdd = pointsToAdd + 1;
            }
        }
        --x;
    }

    x = i;

    // Check NORTH
        while (y < GRID_HEIGHT) {
        if (player.getMosaic().getLaidAt(x, y) != '.') {
            if (x != i || y != rowCounter) {
                pointsToAdd = pointsToAdd + 1;
            }
        }
        ++y;
    }

    y = rowCounter;

    // Check SOUTH
        while (y > 0) {
        if (player.getMosaic().getLaidAt(x, y) != '.') {
            if (x != i || y != rowCounter) {
                pointsToAdd = pointsToAdd + 1;
            }
        }
        --y;
    }

    // Points SUBRACTION

    int pointsToSubtract = 0;

    unsigned int brokenTilesLength = player.getMosaic().getBrokenTiles().size();

    if (brokenTilesLength == 1) {
        pointsToSubtract = pointsToSubtract - 1;
    } else if (brokenTilesLength == 2) {
        pointsToSubtract = pointsToSubtract - 2;
    } else if (brokenTilesLength == 3) {
        pointsToSubtract = pointsToSubtract - 4;
    } else if (brokenTilesLength == 4) {
        pointsToSubtract = pointsToSubtract - 6;
    } else if (brokenTilesLength == 5) {
        pointsToSubtract = pointsToSubtract - 8;
    } else if (brokenTilesLength == 6) {
        pointsToSubtract = pointsToSubtract - 11;
    } else if (brokenTilesLength == 7) {
        pointsToSubtract = pointsToSubtract - 14;
    }
    unsigned int netPoints = 0;
    if (pointsToAdd + pointsToSubtract >= 0) {
        netPoints = pointsToAdd + pointsToSubtract;
    }

    player.updatePoints(netPoints);
}

void GameEngine::clearMosaic(Player& player) {

    // Clean up storage tiles.
    for (unsigned int i = 0; i < GRID_HEIGHT; ++i) {
        for (unsigned int j = 0; j < GRID_WIDTH; ++j) {
            if (player.getMosaic().getStorageAt(i, j) != '.' && player.getMosaic().getStorageAt(i, j) != ' ') {
               // this->bag.getTiles().addToBack(new Tile(player.getMosaic().getStorageAt(i, j)));
                this->lid.getTiles().addToBack(new Tile(player.getMosaic().getStorageAt(i,j)));
                player.getMosaic().getStorageAt(i, j) = '.';
            }
        }
    }

    // Clean up laid tiles.
    for (unsigned int i = 0; i < GRID_HEIGHT; ++i) {
        for (unsigned int j = 0; j < GRID_WIDTH; ++j) {
            if (player.getMosaic().getLaidAt(i, j) != '.') {
                //this->bag.getTiles().addToBack(new Tile(player.getMosaic().getLaidAt(i, j)));
                this->lid.getTiles().addToBack(new Tile(player.getMosaic().getLaidAt(i,j)));
                player.getMosaic().getLaidAt(i, j) = '.';
            }
        }
    }

    // Clean up broken tiles / floor tiles.
    unsigned int length = player.getMosaic().getBrokenTiles().size();
    for (unsigned int i = 0; i < length; ++i) {
        ColourCode colour = player.getMosaic().getBrokenTiles().at(i).getColourCode();
        this->lid.getTiles().addToBack(new Tile(colour));
        //this->bag.getTiles().addToBack(new Tile(colour));
    }

    player.getMosaic().getBrokenTiles().clear();

}

void GameEngine::fillFactories() {

    for (unsigned int i = 0; i < MAX_FACTORIES; ++i) {

        if (i == (CENTER_FACTORY)) {

            // Makes the last factory the center factory.
            Factory centerFactory;
            Tile fp(FIRST_PLAYER);
            centerFactory.getTiles().push_back(fp);
            this->factories.at(CENTER_FACTORY) = centerFactory;

        } else {

            Factory newFactory;
            for (unsigned int j = 0; j < MAX_TILES; ++j) {

                if (this->bag.getTiles().get(j) == nullptr)
                {
                    lidToBag();
                }
                
                Tile* tile = this->bag.getTiles().get(0);
                newFactory.getTiles().push_back(*tile);
                this->bag.getTiles().removeFront();
            }

        factories.at(i) = newFactory;

        }
    }

}

void GameEngine::lidToBag(){

    const unsigned int bagLength = this->lid.getTiles().length();

    for (int i = 0; i < bagLength; i++)
    {
        this->bag.getTiles().addToBack(this->lid.getTiles().get(i));
    }

    this->lid.getTiles().wipe();
}

void GameEngine::saveGameState(const std::string fileName) {

    // Create the save file.
    std::ofstream saveFile;
    saveFile.open(fileName + ".txt");
    
    // Save the tiles currently in the tile bag.
    for (unsigned int i = 0; i < this->bag.getTiles().length(); ++i) {
        saveFile.put(this->bag.getTiles().get(i)->getColourCode());
    }
    saveFile.put(SEPERATOR);

    // Save player 1's name.
    saveFile << this->player1.getName();
    saveFile.put(SEPERATOR);

    // Save player 2's name.
    saveFile << this->player2.getName();
    saveFile.put(SEPERATOR);

    // Save the turns.
    for (unsigned int i = 0; i < this->turns.size(); ++i) {
        saveFile << this->turns.at(i);
        saveFile.put(SEPERATOR);
    }



    







    saveFile.close();
}