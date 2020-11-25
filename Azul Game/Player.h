#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Mosaic.h"

class Player {

    public:

        Player();
        ~Player();

        // Getters

        std::string getName() const;

        Mosaic& getMosaic();

        // Setters

        void setName(std::string name);

        void updatePoints(const int points);



    private:
        std::string name; // The name of the player.
        int points;
        Mosaic mosaic;
};


#endif // PLAYER_H