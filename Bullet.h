#ifndef SHOOTER2DSFML_BULLET_H
#define SHOOTER2DSFML_BULLET_H


#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f direction;
    float movementSpeed;

    void initTexture();

public:
    Bullet();
    Bullet(sf::Texture& texture, sf::Vector2f pos, sf::Vector2f dir, float movementSpeed);

    virtual ~Bullet();

    void update(float deltaTime);
    void render(sf::RenderTarget& target);
};


#endif //SHOOTER2DSFML_BULLET_H
