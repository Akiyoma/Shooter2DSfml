#ifndef SHOOTERPROJECT_PLAYER_H
#define SHOOTERPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

class Player {
private:

    float speed;
    int textureSizeX;
    int textureSizeY;

    sf::Clock cooldownBullet;
    float cooldownBulletTime = .2f;
    bool canShoot = true;

    int currentWeapon = 0;

    sf::Clock invulnerabilityTime;

    void initSprite(int x, int y, sf::Texture* texture);

public:
    sf::Sprite sprite;

    bool isInvulnerable = false;
    int hp = 3;

    Player(int windowSizeX, int windowSizeY, sf::Texture* texture);

    virtual ~Player();

    sf::Vector2f getDirection(std::map<std::string, bool>& keys);
    void move(sf::Time deltaTime, sf::RenderTarget& window, sf::Vector2f direction);
    sf::Vector2f& normalize(sf::Vector2f vec);

    void shoot(std::vector<Bullet*>& bullets);
    void cooldownShoot();

    void collisionWindow(sf::RenderTarget& window);

    void changeWeapon(std::map<std::string, bool>& keys);

    void getDamage(int n);
    void invulnerability();

    void update(sf::Time deltaTime, sf::RenderTarget& window, std::map<std::string, bool>& keys, std::vector<Bullet*>& bullets);
    void render(sf::RenderTarget& target);
};


#endif //SHOOTERPROJECT_PLAYER_H
