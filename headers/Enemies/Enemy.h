#ifndef SHOOTER2DSFML_ENEMY_H
#define SHOOTER2DSFML_ENEMY_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Bullet.h"

class Enemy {
public:
    sf::Sprite sprite;
    sf::Texture texture;

    int hp = 3;

private:

    int movePointId;
    float speed;

    bool twoTimePattrolChecker;

    sf::Clock cooldownBullet;
    float cooldownBulletTime = .2f;
public:
    void setCooldownBulletTime(float cooldownBulletTime);

private:

    int textureSizeX;
    int textureSizeY;



public:
    Enemy(sf::Texture *texture);

    bool moveTo(sf::Vector2f, sf::Time deltaTime);
    void initSprite(sf::Texture* texture, float scaleX, float scaleY);
    virtual void update(sf::Time deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets);
    void render(sf::RenderTarget& target);

    virtual ~Enemy();

    void fire(sf::Vector2f dir, float speed, std::vector<Bullet*>& bullets);

    void moveBetweenTwoPoint(std::vector<sf::Vector2<float>>, sf::Time deltaTime);

    void getDamage(int n);
};


#endif //SHOOTER2DSFML_ENEMY_H
