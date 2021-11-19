#ifndef SHOOTERPROJECT_PLAYER_H
#define SHOOTERPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;

    float speed;

    sf::Clock cooldownBullet;
    float cooldownBulletTime = .2f;

    void initTexture();
    void initSprite();

public:
    Player();

    virtual ~Player();

    void move(sf::Vector2f dir, float deltaTime);
    sf::Vector2f& normalize(sf::Vector2f vec);

    void update(float deltaTime, sf::RenderTarget& window, std::map<std::string, bool> keys, std::vector<Bullet*>& bullets);
    void render(sf::RenderTarget& target);

    sf::Vector2f moveTo(sf::Vector2f dir);
};


#endif //SHOOTERPROJECT_PLAYER_H
