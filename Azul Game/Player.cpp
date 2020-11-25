#include "Player.h"

Player::Player() {
    this->name = "";
}

Player::~Player() {

}
// Getters

std::string Player::getName() const {
    return this->name;
}

Mosaic& Player::getMosaic() {
    return this->mosaic;
}


// Setters

void Player::setName(std::string name) {
    this->name = name;
}

void Player::updatePoints(const int points) {
    this->points = this->points + points;
}



