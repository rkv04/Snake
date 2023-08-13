#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "sector.hpp"

class Snake {
public:
    Snake(int len);
    ~Snake();

    void makeStep();

    void setDirMove();
    std::vector<Sector*> getBody();
    Sector* getHead();

    void grow();
    bool checkCollisionHeadBody();

private:
    enum DirectionMove {UP, LEFT, DOWN, RIGHT};
    DirectionMove curDirMove;
    std::vector<Sector*> body;
};

#endif