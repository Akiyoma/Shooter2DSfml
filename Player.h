#ifndef SHOOTERPROJECT_PLAYER_H
#define SHOOTERPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
public:
    sf::Sprite sprite;
private:
    sf::Texture texture;

    float speed;

    void initTexture();
    void initSprite();

public:
    Player();

    virtual ~Player();

    void move(sf::Vector2f dir, float deltaTime);
    sf::Vector2f& normalize(sf::Vector2f vec);

    void update();
    void render(sf::RenderTarget& target);

    sf::Vector2f moveTo(sf::Vector2f dir);
};


#endif //SHOOTERPROJECT_PLAYER_H
