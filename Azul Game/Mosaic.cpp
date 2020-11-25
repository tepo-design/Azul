#include "Mosaic.h"

Mosaic::Mosaic() {

    // Instantiates the storage tiles to default state (empty).
    unsigned int z = 5;
    for (unsigned int i = 0; i < GRID_HEIGHT; ++i) {
        --z;
        for (unsigned int j = 0; j < GRID_WIDTH; ++j) {
            if (j < z) {
                storage[i][j] = ' ';
            } else {
                storage[i][j] = '.';
            }
        }
    }

    // Instantiate mosaic place tiles to default state (empty).
    for (unsigned int i = 0; i < GRID_HEIGHT; ++i) {
        for (unsigned int j = 0; j < GRID_WIDTH; ++j) {
            this->placed[i][j] = '.';
        }
    }


    // Instantiates the pattern identity of the mosaic (uses classical/default pattern of Azul).
    for (unsigned int i = 0; i < GRID_HEIGHT; ++i) {
        for (unsigned int j = 0; j < GRID_WIDTH; ++j) {
            this->pattern[i][j] = this->DEFAULT_PATTERN[i][j];
        }
    }

    // Instantiates the pattern identity of the mosaic (uses classical/default pattern of Azul).
    // for (unsigned int i = 0; i < GRID_HEIGHT; ++i) {
    //     for (unsigned int j = 0; j < GRID_sWIDTH; ++j) {

    //         unsigned int enumCorrespondant = ((i + j) % COLOUR_QUANTITY);

    //         if (enumCorrespondant == LIGHT_BLUE) {
    //             this->pattern[i][j] = 'L';
    //         } else if (enumCorrespondant == YELLOW) {
    //             this->pattern[i][j] = 'Y';
    //         } else if (enumCorrespondant == RED) {
    //             this->pattern[i][j] = 'R';
    //         } else if (enumCorrespondant == BLACK) {
    //             this->pattern[i][j] = 'U';
    //         } else if (enumCorrespondant == DARK_BLUE) {
    //             this->pattern[i][j] = 'B';
    //         }
            
    //     }
    // }

}

Mosaic::~Mosaic() {
    
}

char& Mosaic::getStorageAt(const unsigned int x, const unsigned int y) {
    return this->storage[y][x];
}

char& Mosaic::getLaidAt(const unsigned int x, const unsigned int y) {
    return this->placed[y][x];
}

char Mosaic::getPatternAt(const unsigned int x, const unsigned int y) {
    return this->DEFAULT_PATTERN[y][x];
}

std::vector<Tile>& Mosaic::getBrokenTiles() {
    return this->broken;
}

void Mosaic::printMosaic() {

    for (unsigned int i = 0; i < GRID_HEIGHT; ++i) {
        std::cout << i + 1 << ": ";
        for (unsigned int j = 0; j < GRID_WIDTH; ++j) {
            std::cout << this->storage[i][j] << " ";
        }

        std::cout << "|| ";

        for (unsigned int k = 0; k < GRID_WIDTH; ++k) {
            std::cout << this->placed[i][k] << " ";
        }
        std::cout << '\n';
    }

    std::cout << "broken: ";
    for (Tile tile : this->broken) {
        std:: cout << tile.getColourCode() << " ";
    }
    std::cout << "\n\n";
}

void Mosaic::printPattern() {
    for (unsigned int i = 0; i < GRID_HEIGHT; ++i) {
        std::cout << i + 1 << ": ";
        for (unsigned int j = 0; j < GRID_WIDTH; ++j) {
            std::cout << this->pattern[i][j] << " ";
        }
        std::cout << '\n';
    }
}


