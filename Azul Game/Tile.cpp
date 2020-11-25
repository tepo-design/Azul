#include "Tile.h"



Tile::Tile() {
    // Default tile is empty tile.
    this->type = TileType::EMPTY;
    this->colourCode = '.'; 
}

Tile::~Tile() {

}

Tile::Tile(ColourCode code) {
    this->colourCode = code;

    if (this->colourCode == 'R')
        this->type = TileType::RED;
    
    if (this->colourCode == 'Y')
        this->type = TileType::YELLOW;

    if (this->colourCode == 'B')
        this->type= TileType::DARK_BLUE;

    if (this->colourCode == 'L')
        this->type = TileType::LIGHT_BLUE;

    if (this->colourCode == 'U')
        this->type = TileType::BLACK;

    if (this->colourCode == 'F')
        this->type= TileType::FIRST_PLAYER;

    if (this->colourCode == '.')
        this->type = TileType::EMPTY;

}

Tile::Tile(TileType type) {
    this->type = type;

    if (this->type == TileType::RED)
        this->colourCode = 'R';
    
    if (this->type == TileType::YELLOW)
        this->colourCode = 'Y';

    if (this->type == TileType::DARK_BLUE)
        this->colourCode = 'B';

    if (this->type == TileType::LIGHT_BLUE)
        this->colourCode = 'L';

    if (this->type == TileType::BLACK)
        this->colourCode = 'U';

    if (this->type == TileType::FIRST_PLAYER)
        this->colourCode = 'F';

    if (this->type == TileType::EMPTY)
        this->colourCode = '.';
}

Tile::Tile(const Tile& other) :
type(other.type), 
colourCode(other.colourCode)
{}

TileType Tile::getTileType() {
    return this->type;
}

ColourCode Tile::getColourCode() {
    return this->colourCode;
}