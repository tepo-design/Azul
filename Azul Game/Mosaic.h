#ifndef MOSAIC_H
#define MOSAIC_H

#define GRID_HEIGHT 5
#define GRID_WIDTH 5

#include "Tile.h"

#include <vector>
#include <iostream>


typedef char Storage[GRID_HEIGHT][GRID_WIDTH];
typedef char Laid[GRID_HEIGHT][GRID_WIDTH];
typedef std::vector<Tile> Broken;

class Mosaic{
    public:

    Mosaic();
    ~Mosaic();

    char& getStorageAt(const unsigned int x, const unsigned int y);

    char& getLaidAt(const unsigned int x, const unsigned int y);

    char getPatternAt(const unsigned int x, const unsigned int y);

    void clearMosaic();

    std::vector<Tile>& getBrokenTiles();

    void printMosaic();

    // Used for testing purposes - to display the layout of the Mosaic.
    void printPattern();

    private:
    Laid DEFAULT_PATTERN = {
    {'B', 'Y', 'R', 'U', 'L'},
    {'L', 'B', 'Y', 'R', 'U'},
    {'U', 'L', 'B', 'Y', 'R'},
    {'R', 'U', 'L', 'B', 'Y'},
    {'Y', 'R', 'U', 'L', 'B'}
    };

    Storage storage;
    Laid pattern;
    Laid placed;
    Broken broken;
    
};


#endif // MOSAIC_H