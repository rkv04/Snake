#ifndef SECTOR_HPP
#define SECTOR_HPP

#include <SFML/Graphics.hpp>

class Sector : public sf::RectangleShape {
public:
    static constexpr float size = 20;
    
    Sector(int posX, int posY);
    float getPosX();
    float getPosY();
    void setPos(float posX, float posY);
private:
    float posX;
    float posY;
};

#endif // SECTOR_HPP