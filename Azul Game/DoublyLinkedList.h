#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Tile.h"

class Node {
   public:
    Node();
    Node(Tile* tile, Node* next);
    Node(const Node& other);

    Tile* tile;
    Node* next;
    Node* previous;
};

class DoublyLinkedList {
   public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);
    ~DoublyLinkedList();

    unsigned int length() const;

    Tile* get(unsigned int index) const;

    void addToFront(Tile* tile);
    void addToBack(Tile* tile);

    void removeFront();
    void removeBack();

    void wipe();

   private:
    Node* head;
    Node* tail;
};

#endif  // DOUBLY_LINKED_LIST_H