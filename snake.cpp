#include "snake.hpp"
#include "sector.hpp"

Snake::Snake(int len) {
    for (int i = 0; i < len; i++) {
        this->body.push_back(new Sector(Sector::size * 8, Sector::size * 20 - i * Sector::size));
    }
    this->curDirMove = DirectionMove::UP;
}

Snake::~Snake() {
    for (int i = 0; i < this->body.size(); i++) {
        delete body[i];
    }
}

std::vector<Sector*> Snake::getBody() {
    return this->body;
}

void Snake::makeStep() {
    this->setDirMove();
    Sector *new_head = body.front();
    Sector *head = this->getHead();
    float posX, posY;
    if (this->curDirMove == DirectionMove::UP) {
        posX = head->getPosX();
        posY = head->getPosY() - Sector::size;
    }
    else if (this->curDirMove == DirectionMove::DOWN) {
        posX = head->getPosX();
        posY = head->getPosY() + Sector::size;
    }
    else if (this->curDirMove == DirectionMove::LEFT) {
        posX = head->getPosX() - Sector::size;
        posY = head->getPosY();
    }
    else if (this->curDirMove == DirectionMove::RIGHT) {
        posX = head->getPosX() + Sector::size;
        posY = head->getPosY();
    }
    new_head->setPos(posX, posY);
    this->body.erase(body.begin());
    this->body.push_back(new_head);
}

void Snake::setDirMove() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->curDirMove != DOWN) {
        curDirMove = UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->curDirMove  != UP) {
        curDirMove = DOWN;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->curDirMove != RIGHT) {
        curDirMove = LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->curDirMove != LEFT) {
        curDirMove = RIGHT;
    }
}

Sector* Snake::getHead() {
    return this->body.back();
}

void Snake::grow() {
    float posX0 = this->body[0]->getPosX();
    float posY0 = this->body[0]->getPosY();
    float posX1 = this->body[1]->getPosX();
    float posY1 = this->body[1]->getPosY();
    if (posX0 < posX1) {
        posX0 -= Sector::size;
    }
    else if (posX0 > posX1) {
        posX0 += Sector::size;
    }
    else if (posY0 < posY1) {
        posY0 -= Sector::size;
    }
    else if (posY0 > posY1) {
        posY0 += Sector::size;
    }
    Sector *newSector = new Sector(posX0, posY0);
    this->body.insert(body.begin(), newSector);
}

bool Snake::checkCollisionHeadBody() {
    Sector *head = this->getHead();
    for (int i = 0; i < this->body.size() - 1; i++) {
        if (head->getPosX() == this->body[i]->getPosX() && head->getPosY() == this->body[i]->getPosY()) {
            return true;
        }
    }
    return false;
}

int Snake::getScore() {
    return this->body.size() - 3;
}