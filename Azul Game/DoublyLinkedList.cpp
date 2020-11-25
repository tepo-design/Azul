#include "DoublyLinkedList.h"

    Node::Node() {
        tile = nullptr;
        next = nullptr;
        previous = nullptr;
    }

    Node::Node(Tile* tile, Node* next) :
            tile(tile),
            next(next) 
            {}

    Node::Node(const Node& other) {
        this->tile = new Tile(*other.tile);
        this->next = new Node(*other.next);
        this->previous = new Node(*other.previous);
    }

    DoublyLinkedList::DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other) {
        // TODO
    }

    DoublyLinkedList::~DoublyLinkedList() {
        wipe();
    }

    unsigned int DoublyLinkedList::length() const {
        unsigned int length = 0;
        Node* current = head;
        while (current != nullptr) {
            current = current->next;
            ++length;
        }

        return length;
    }

    Tile* DoublyLinkedList::get(unsigned int index) const {
        Tile* targetTile = nullptr;


        if (index >= 0 && index < length()) {
            unsigned int counter = 0;
            Node* current = head;
            while(counter != index) {
                current = current->next;
                ++counter;
            }

            targetTile = current->tile;
        }

        return targetTile;
    }

    void DoublyLinkedList::addToFront(Tile* tile) {
        Node* node = new Node();
        node->tile = tile;
        node->next = head;
        node->previous = nullptr;


        if (head == nullptr) {
            tail = node;
        } else {
            head->previous = node;
        }

        head = node;
    }

    void DoublyLinkedList::addToBack(Tile* tile) {

        Node* node = new Node();
        node->tile = tile;
        node->next = nullptr;
        node->previous = tail;


        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }

        tail = node;
    }

    void DoublyLinkedList::removeFront() {
        if (head != nullptr) {
            Node* toRemove = head;

            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            } else {
                head->previous = nullptr;
            }


            delete toRemove->tile;
            delete toRemove;
        }
    }

    void DoublyLinkedList::removeBack() {
        if (tail != nullptr) {
            Node* toRemove = tail;

            tail = tail->previous;
            if (tail == nullptr) {
                head = nullptr;
            } else {
                tail->next = nullptr;
            }

            delete toRemove->tile;
            delete toRemove;
        }
    }

    void DoublyLinkedList::wipe() {
        while (head != nullptr) {
            removeFront();
        }
    }

   