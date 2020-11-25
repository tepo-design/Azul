#ifndef FACTORY_H
#define FACTORY_H

#define MAX_TILES 5

#include <vector>

#include "Tile.h"


class Factory {
    public:
    Factory();
    ~Factory();

    std::vector<Tile>& getTiles();

    private:
        std::vector<Tile> tiles;
};


#endif // FACTORY_H