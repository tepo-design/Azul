#ifndef LID_H
#define LID_H
#include <iostream>

#include "DoublyLinkedList.h"
#include "Tile.h"
#include <vector>

class Lid {
   public:
    Lid();
    ~Lid();

    DoublyLinkedList& getTiles();

    private:
    DoublyLinkedList tiles;
    Node* head;
    Node* tail;
   
};

#endif  // LID_H