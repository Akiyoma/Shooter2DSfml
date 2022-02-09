#ifndef SHOOTER2DSFML_BULLET_H
#define SHOOTER2DSFML_BULLET_H


#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {
public:
    sf::Sprite sprite;

private:
    sf::Texture texture;
    sf::Vector2f direction;
    float movementSpeed;

    void initTexture();

public:
    Bullet();
    Bullet(sf::Texture& texture, sf::Vector2f pos, sf::Vector2f dir, float movementSpeed);

    virtual ~Bullet();

    void update(sf::Time deltaTime, sf::RenderTarget &target);
    void render(sf::RenderTarget& target);

    bool isOutsideWindow(sf::RenderTarget &target, std::vector<Bullet*> bullets);
};


#endif //SHOOTER2DSFML_BULLET_H
