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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            player->move(-1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player->move(1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            player->move(0.f, -1.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            player->move(0.f, 1.f);

        window.clear();

        player->render(window);

        window.display();
    }


    return 0;
}
