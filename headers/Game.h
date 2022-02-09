#ifndef SHOOTER2DSFML_GAME_H
#define SHOOTER2DSFML_GAME_H


#include <SFML/Graphics.hpp>
#include "Loader.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemies/Enemy.h"
#include "Enemies/TwoTimePatrolEnemy.h"
#include <list>
#include "../headers/Level.h"


class Game {
private:
    sf::RenderWindow* window;

    void initWindow();

    std::map<std::string, bool> keys;
    Loader* loader;
    //const float deltaTime = 1.f/60.f; // 60fps
    sf::Clock clock;
    sf::Time fixedPhysic = sf::microseconds(16666);
    sf::Time updateTime;

    Level* level;

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
