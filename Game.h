//
// Created by Jeremy on 12/11/2021.
//

#ifndef SHOOTER2DSFML_GAME_H
#define SHOOTER2DSFML_GAME_H


#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"

class Game {
private:
    sf::RenderWindow* window;

    void initWindow();

    Player* player;

    std::vector<Bullet*> bullets;
    sf::Clock cooldownBullet;
    float cooldownBulletTime = .5f;

    const float deltaTime = 1.f/60.f; // 60fps
    sf::Clock clock;
    float lastTime = clock.getElapsedTime().asSeconds();
    float accumulator = 0.f;

public:
    Game();

    virtual ~Game();

    void run();

    void updatePollEvents();
    void updateInput();
    void update();
    void render();
};


#endif //SHOOTER2DSFML_GAME_H
