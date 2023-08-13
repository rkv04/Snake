#ifndef APPLE_HPP
#define APPLE_HPP

#include <SFML/Graphics.hpp>

class Apple : public sf::CircleShape {
public:
    Apple();
    float getPosX();
    float getPosY();
    void setPos(float posX, float posY);
private:
    float posX;
    float posY;
};

#endif