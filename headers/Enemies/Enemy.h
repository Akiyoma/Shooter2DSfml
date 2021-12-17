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


    float speed;

    sf::Clock cooldownBullet;
    float cooldownBulletTime = .2f;
public:
    void setCooldownBulletTime(float cooldownBulletTime);

private:

    int textureSizeX;
    int textureSizeY;



public:
    Enemy();

//    void moveBetweenTwoPoint(sf::Vector2f dest1, sf::Vector2f dest2);
    void moveTo(sf::Vector2f, float deltaTime);
    void initTexture(std::string fileName);
    void initSprite();
    void update(float deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets);
    void render(sf::RenderTarget& target);

    virtual ~Enemy();

    void fire(sf::Vector2f dir, float speed, std::vector<Bullet *> &bullets);
};


#endif //SHOOTER2DSFML_ENEMY_H
