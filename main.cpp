#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <iostream>

#include "sector.hpp"
#include "apple.hpp"
#include "snake.hpp"
#include "map.hpp"

int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(Map::WIDTH, Map::HEIGHT), "Snake");
    window.setFramerateLimit(7);
    sf::Color backgroungColor(255, 255, 255);

    Map map;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        map.getSnake()->makeStep();
        map.collisionDetection();

        window.setTitle("Score - " + std::to_string(map.getSnake()->getScore()));

        window.clear(backgroungColor);
        map.drawFrame(window);
        window.display();


    }
    
    return 0;
}