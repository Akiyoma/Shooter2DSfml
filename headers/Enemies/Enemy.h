#ifndef SHOOTER2DSFML_ENEMY_H
#define SHOOTER2DSFML_ENEMY_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Bullet.h"

class Enemy {
public:
    sf::Sprite sprite;
    sf::Texture texture;

private:

    int movePoint;
    float speed;

    sf::Clock cooldownBullet;
    float cooldownBulletTime = .2f;
public:
    void setCooldownBulletTime(float cooldownBulletTime);

private:

    int textureSizeX;
    int textureSizeY;



public:
    Enemy(sf::Texture *texture);

    bool moveTo(sf::Vector2f, float deltaTime);
    void initSprite(sf::Texture* texture, float scaleX, float scaleY);
    virtual void update(float deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets);
    void render(sf::RenderTarget& target);

    virtual ~Enemy();

    void fire(sf::Vector2f dir, float speed, std::vector<Bullet *> &bullets);

    void moveBetweenTwoPoint(sf::Vector2f dest1, sf::Vector2f dest2, float deltaTime);
};


#endif //SHOOTER2DSFML_ENEMY_H
