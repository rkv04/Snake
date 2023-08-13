#include "apple.hpp"
#include "sector.hpp"
#include "map.hpp"

Apple::Apple() {
    this->setRadius(Sector::size / 2);
    int kX = rand() % ((int)Map::WIDTH / (int)Sector::size - 1);
    int kY = rand() % ((int)Map::HEIGHT / (int)Sector::size - 1);
    float posX = kX * (int)Sector::size;
    float posY = kY * (int)Sector::size;
    this->setPosition(posX, posY);
    sf::Color color(121, 6, 4);
    this->setFillColor(sf::Color::Red);
    this->setOutlineThickness(-2);
    this->setOutlineColor(color);
    this->posX = posX;
    this->posY = posY;
}
float Apple::getPosX() {
    return this->posX;
}
float Apple::getPosY() {
    return this->posY;
}
void Apple::setPos(float posX, float posY) {
    this->setPosition(posX, posY);
    this->posX = posX;
    this->posY = posY;
}