#include "Lid.h"

Lid::Lid() {

    head = nullptr;
    tail = nullptr;

}

Lid::~Lid() {
    this->tiles.wipe();
}

DoublyLinkedList& Lid::getTiles() {
    return this->tiles;
}

