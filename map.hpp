#ifndef MAP_HPP
#define MAP_HPP

#include "SFML/Graphics.hpp"
#include "snake.hpp"
#include "apple.hpp"

class Map {
public:
    static constexpr float WIDTH = Sector::size * 25;
    static constexpr float HEIGHT = Sector::size * 25;
    Map();
    ~Map();
    bool checkCollisionSnakeApple();
    void checkCollisionSnakeWall();
    void collisionDetection();
    void drawSnake(sf::RenderWindow &window);
    void drawApple(sf::RenderWindow &window);
    void drawFrame(sf::RenderWindow &window);
    void drawGrid(sf::RenderWindow &window);
    Snake* getSnake();
    void createNewSnake();
    void createNewApple();
    

private:
    Snake* snake;
    Apple* apple;
    std::vector<sf::Vector2f> freeCoordinates;
};

#endif