#ifndef SHOOTER2DSFML_ENEMY_H
#define SHOOTER2DSFML_ENEMY_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Bullet.h"
#include "../VectorMath.h"

class Enemy {
public:
    sf::Sprite sprite;

    int hp = 5;

    bool isAppear = false;

    sf::Clock coolDownBullet;
    float coolDownBulletTime{};
private:
    sf::Texture bulletTexture;

    int movePointId{};
    float speed{};

    sf::Vector2f initialPos;

public:
    void setCoolDownBulletTime(float coolDownBulletTime);

private:
    int textureSizeX{};
    int textureSizeY{};

public:
    Enemy(sf::Texture *texture, sf::Texture *bulletTexture, sf::Vector2f initialPos);

    bool moveTo(sf::Vector2f pos, float speed, sf::Time deltaTime);

    void initSprite(sf::Texture *texture, float scaleX, float scaleY);

    virtual void update(sf::Time deltaTime, sf::RenderTarget &window, std::vector<Bullet *> &bullets);

    void render(sf::RenderTarget &target);

    virtual ~Enemy();

    void fire(sf::Vector2f dir, float speed, std::vector<Bullet *> &bullets);

    void moveBetweenTwoPoint(std::vector<sf::Vector2<float>>, sf::Time deltaTime);

    void getDamage(int n);

    void circleAttack(int n, float speed, std::vector<Bullet *> &bullets);

    void appear(sf::Vector2f pos, sf::Time deltaTime);
};


#endif //SHOOTER2DSFML_ENEMY_H
