#ifndef TILE_H
#define TILE_H

#define COLOUR_QUANTITY 5

typedef char ColourCode;

#include <string>

enum TileType {
    LIGHT_BLUE,
    YELLOW,
    RED,
    BLACK,
    DARK_BLUE,
    FIRST_PLAYER,
    EMPTY
};

class Tile {
    public:
        Tile();
        ~Tile();
        Tile(ColourCode code);
        Tile(TileType type);
        Tile(const Tile& other);

        TileType getTileType();
        ColourCode getColourCode();

    private:
        TileType type;
        ColourCode colourCode;
};


#endif // TILE_H