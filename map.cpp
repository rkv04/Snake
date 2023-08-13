#include "map.hpp"

Map::Map() {
    this->snake = new Snake(3);
    this->apple = new Apple();
}

Map::~Map() {
    delete this->snake;
}

void Map::checkCollisionSnakeApple() {
    Sector *head = this->snake->getHead();
    if (head->getPosX() == this->apple->getPosX() && head->getPosY() == this->apple->getPosY()) {
        setNewApple();
        this->snake->grow();
    }
}

void Map::checkCollisionSnakeWall() {
    Sector* head = this->snake->getHead();
    if (head->getPosX() >= Map::WIDTH) {
        head->setPos(0, head->getPosY());
    }
    else if (head->getPosX() < 0) {
        head->setPos(Map::WIDTH - Sector::size, head->getPosY());
    }
    else if (head->getPosY() >= Map::HEIGHT) {
        head->setPos(head->getPosX(), 0);
    }
    else if (head->getPosY() < 0) {
        head->setPos(head->getPosX(), Map::HEIGHT - Sector::size);
    }
}

void Map::collisionDetection() {
    this->checkCollisionSnakeWall();
    this->checkCollisionSnakeApple();
    if (this->snake->checkCollisionHeadBody()) {
        this->createNewSnake();
    }
}

void Map::drawSnake(sf::RenderWindow &window) {
    std::vector<Sector*> body = snake->getBody();
    for (int i = 0; i < body.size(); i++) {
        window.draw(*body[i]);
    }
}

void Map::drawApple(sf::RenderWindow &window) {
    window.draw(*this->apple);
}

void Map::drawGrid(sf::RenderWindow &window) {
    sf::Color lineColor(200, 200, 200);
    for (int i = 0; i <= Map::WIDTH; i += Sector::size) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(i, 0), lineColor),
            sf::Vertex(sf::Vector2f(i, Map::HEIGHT), lineColor)
        };
        window.draw(line, 2, sf::Lines);
    }
    for (int i = 0; i <= Map::HEIGHT; i += Sector::size) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, i), lineColor),
            sf::Vertex(sf::Vector2f(Map::WIDTH, i), lineColor)
        };
        window.draw(line, 2, sf::Lines);
    }
}

void Map::drawFrame(sf::RenderWindow &window) {
    drawSnake(window);
    drawApple(window);
    drawGrid(window);
}

Snake* Map::getShake() {
    return this->snake;
}

void Map::setNewApple() {
    float kX = rand() % ((int)Map::WIDTH / (int)Sector::size - 1);
    float kY = rand() % ((int)Map::HEIGHT / (int)Sector::size - 1);
    float posX = Sector::size * kX;
    float posY = Sector::size * kY;
    this->apple->setPos(posX, posY);
}

void Map::createNewSnake() {
    this->snake = new Snake(3);
}