#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Shooter 2D SFML");
    //window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);
    Player* player;
    player = new Player();

    float deltaTime = 1.f/60.f; // 60fps
    sf::Clock clock;
    float lastTime = clock.getElapsedTime().asSeconds();
    float accumulator = 0.f;

    while (window.isOpen()) {
        float currentTime = clock.getElapsedTime().asSeconds();
        accumulator += currentTime - lastTime;
        lastTime = currentTime;

        while (accumulator >= deltaTime) {
            sf::Event event;

            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // Keys
            bool keyLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            bool keyRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
            bool keyUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
            bool keyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

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


                player->move(dir, deltaTime);

                // Collision window
                // Left
                if (player->sprite.getPosition().x <= 0) {
                    player->sprite.setPosition(0.f, player->sprite.getPosition().y);
                }
                // Right
                if (player->sprite.getPosition().x >= window.getSize().x - player->sprite.getGlobalBounds().width) {
                    player->sprite.setPosition(window.getSize().x - player->sprite.getGlobalBounds().width, player->sprite.getPosition().y);
                }
                // Top
                if (player->sprite.getPosition().y <= 0) {
                    player->sprite.setPosition(player->sprite.getPosition().x, 0.f);
                }
                //Bottom
                if (player->sprite.getPosition().y >= window.getSize().y - player->sprite.getGlobalBounds().height) {
                    player->sprite.setPosition(player->sprite.getPosition().x, window.getSize().y - player->sprite.getGlobalBounds().height);
                }
            }

            window.clear();

            player->render(window);

            window.display();

            accumulator -= deltaTime;
        }
    }


    return 0;
}