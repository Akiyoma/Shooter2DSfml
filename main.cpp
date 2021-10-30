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

        // Keys detected
        bool keyLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
        bool keyRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        bool keyUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
        bool keyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

        if (keyLeft || keyRight || keyUp || keyDown) {
            sf::Vector2<float> dir = {0, 0};
            if (keyLeft)
                dir.x--;
            if (keyRight)
                dir.x++;
            if (keyUp)
                dir.y--;
            if (keyDown)
                dir.y++;
            player->move(dir);
        }

        window.clear();

        player->render(window);

        window.display();
    }


    return 0;
}
