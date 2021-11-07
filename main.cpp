#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Shooter 2D SFML");
    window.setVerticalSyncEnabled(true);
    Player* player;
    player = new Player();

    float dt = 1.f/40.f; // Modify this to change physics rate.
    float accumulator = 0.f;
    bool drawn = false;

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


            sf::Vector2<float> moveToVec = player->moveTo(dir);

            std::cout<<moveToVec.x<<std::endl;
            if(moveToVec.x >= 0 && moveToVec.y >= 0 && moveToVec.x + 50 <= window.getSize().x && moveToVec.y + 50 <= window.getSize().y ){
                player->move(dir);
            }else{
                if (moveToVec.x < 0){
                    sf::Vector2<float> correctPosition;
                    correctPosition.x = - moveToVec.x;
                    correctPosition.y = 0;
                    player->move(correctPosition);

                }
                if (moveToVec.y < 0){
                    sf::Vector2<float> correctPosition;
                    correctPosition.x = 0;
                    correctPosition.y = - moveToVec.y;
                    player->move(correctPosition);

                }
                if (moveToVec.x + 50 > window.getSize().x){
                    sf::Vector2<float> correctPosition;
                    correctPosition.x = - moveToVec.x;
                    correctPosition.y = 0;
                    player->move(correctPosition);

                }
                if (moveToVec.y + 50 > window.getSize().y){
                    sf::Vector2<float> correctPosition;
                    correctPosition.x = 0;
                    correctPosition.y = - moveToVec.y;
                    player->move(correctPosition);

                }
            }

        }

        window.clear();

        player->render(window);

        window.display();
    }


    return 0;
}


/** TODO
 *        - Gameplay loop
 */