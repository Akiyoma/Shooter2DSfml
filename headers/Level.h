#ifndef SHOOTER2DSFML_LEVEL_H
#define SHOOTER2DSFML_LEVEL_H


#include <vector>
#include "Bullet.h"
#include "Player.h"
#include "Enemies/Enemy.h"
#include "Enemies/TwoTimePatrolEnemy.h"
#include "Loader.h"
#include "GameState.h"

class Level {
public:
    Player* player;

    std::vector<Bullet*> bullets;
    std::vector<Bullet*> ennemiesBullets;
    std::vector<Enemy*> enemies;

    int score = 0;
    sf::Text scoreText;

    sf::Text hpText;

    sf::Text gameOverText;

    Level(sf::RenderWindow& window, Loader& loader);

    virtual ~Level();

    void update(sf::RenderWindow& window, sf::Time deltaTime, std::map<std::string, bool>& keys, GameState& state);
    void render(sf::RenderWindow& window);

    void addScore(int n);
    void reduceHp(int n);

    void gameOver();
};


#endif //SHOOTER2DSFML_LEVEL_H