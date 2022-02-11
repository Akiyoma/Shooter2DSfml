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

    int score = 0;
    sf::Text scoreText;

    sf::Text hpText;

    Level(sf::RenderWindow& window, Loader& loader);

    virtual ~Level();

    void update(sf::RenderWindow& window, sf::Time deltaTime, std::map<std::string, bool>& keys);
    void render(sf::RenderWindow& window);

    void addScore(int n);
    void reduceHp(int n);
};


#endif //SHOOTER2DSFML_LEVEL_H
