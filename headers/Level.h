#ifndef SHOOTER2DSFML_LEVEL_H
#define SHOOTER2DSFML_LEVEL_H


#include <vector>
#include "Bullet.h"
#include "Player.h"
#include "Enemies/Enemy.h"
#include "Enemies/TwoTimePatrolEnemy.h"
#include "Loader.h"

class Level {
public:
    Player* player;

    std::vector<Bullet*> bullets;
    std::vector<Bullet*> ennemiesBullets;
    std::vector<Enemy*> enemies;

    Level(sf::RenderWindow& window, Loader& loader);

    virtual ~Level();

    void update(sf::RenderWindow& window, sf::Time deltaTime, std::map<std::string, bool>& keys);
    void render(sf::RenderWindow& window);
};


#endif //SHOOTER2DSFML_LEVEL_H
