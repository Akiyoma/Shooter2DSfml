#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Shooter 2D SFML");
    window.setVerticalSyncEnabled(true);
    Player* player;
    player = new Player();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2<int> move = {0,0};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            move.x = -1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            move.x = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            move.y = -1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            move.y = 1;
        player->move(move.x, move.y);

        window.clear();

        player->render(window);

        window.display();
    }


    return 0;
}
