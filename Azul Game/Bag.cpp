#include "Bag.h"

Bag::Bag()
{

    for (unsigned int i = 0; i < COLOUR_LIMIT; ++i)
    {
        this->tiles.addToFront(new Tile(RED));
        this->tiles.addToFront(new Tile(YELLOW));
        this->tiles.addToFront(new Tile(DARK_BLUE));
        this->tiles.addToFront(new Tile(LIGHT_BLUE));
        this->tiles.addToFront(new Tile(BLACK));
    }
}

Bag::~Bag()
{
    this->tiles.wipe();
}

DoublyLinkedList &Bag::getTiles()
{
    return this->tiles;
}

void Bag::printBag() const
{

    const unsigned int bagLength = this->tiles.length();

    for (unsigned int i = 0; i < bagLength; ++i)
    {
        Tile *tile = this->tiles.get(i);
        std::cout << tile->getColourCode();
    }
}

DoublyLinkedList &Bag::shuffleBag()
{

    for (unsigned int i = 0; i < COLOUR_LIMIT; ++i)
    {
        this->copyToVector.push_back(new Tile(RED));
        this->copyToVector.push_back(new Tile(YELLOW));
        this->copyToVector.push_back(new Tile(DARK_BLUE));
        this->copyToVector.push_back(new Tile(LIGHT_BLUE));
        this->copyToVector.push_back(new Tile(BLACK));
    }

    this->tiles.wipe();

    int counter = 0;
    for (Tile *t : this->copyToVector)
    {
        int swapThis = counter + rand() % (copyToVector.size() - counter);
        std::swap(this->copyToVector[counter], this->copyToVector[swapThis]);
    }

    int count = 0;

    for (Tile *t : this->copyToVector)
    {
        this->tiles.addToFront(this->copyToVector.at(count));
        count++;
    }

    return this->tiles;
}
