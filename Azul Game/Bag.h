#ifndef BAG_H
#define BAG_H

// The bag will hold 100 tiles in total.
#define COLOUR_QUANTITY 5
// The bag will hold 20 of each colour of tile.
#define COLOUR_LIMIT 20
#define BAG_LIMIT (COLOUR_QUANTITY * COLOUR_LIMIT)

#include <iostream>

#include "DoublyLinkedList.h"
#include "Tile.h"
#include <vector>

class Bag {
   public:
    Bag();
    ~Bag();

    DoublyLinkedList& getTiles();

    void printBag() const;

    DoublyLinkedList& shuffleBag();

   private:
    DoublyLinkedList tiles;
    std::vector<Tile*> copyToVector;
};

#endif  // BAG_H