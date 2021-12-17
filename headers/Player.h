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
    int textureSizeX;
    int textureSizeY;

    sf::Clock cooldownBullet;
    float cooldownBulletTime = .2f;

    void initTexture();
    void initSprite(int x, int y);

public:
    Player(int windowSizeX, int windowSizeY);

    virtual ~Player();

    sf::Vector2f getDirection(std::map<std::string, bool> keys);
    void move(float deltaTime, sf::RenderTarget& window, std::map<std::string, bool> keys);
    sf::Vector2f& normalize(sf::Vector2f vec);

    void shoot(std::map<std::string, bool> keys, std::vector<Bullet*>& bullets);

    void collisionWindow(sf::RenderTarget& window);

    void update(float deltaTime, sf::RenderTarget& window, std::map<std::string, bool> keys, std::vector<Bullet*>& bullets);
    void render(sf::RenderTarget& target);
};


#endif //SHOOTERPROJECT_PLAYER_H
