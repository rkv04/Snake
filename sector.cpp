#include "sector.hpp"
#include "map.hpp"
#include <SFML/Graphics.hpp>

Sector::Sector(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    sf::Color sectorColor(64, 130, 109);
    this->setFillColor(sectorColor);
    this->setPosition(posX, posY);
    this->setSize(sf::Vector2f(Sector::size, Sector::size));
}
float Sector::getPosX() {
        return this->posX;
}
float Sector::getPosY() {
        return this->posY;
}
void Sector::setPos(float posX, float posY) {
    this->setPosition(posX, posY);
    this->posX = posX;
    this->posY = posY;
}