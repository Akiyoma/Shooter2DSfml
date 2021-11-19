#ifndef SHOOTER2DSFML_ENEMY_H
#define SHOOTER2DSFML_ENEMY_H


#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy {
public:
    sf::Sprite sprite;
private:
    sf::Texture texture;

    float speed;

    void initTexture();
    void initSprite();

public:
    Enemy();

    void render(sf::RenderTarget& target);

    virtual ~Enemy();

};


#endif //SHOOTER2DSFML_ENEMY_H
