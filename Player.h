#ifndef SHOOTERPROJECT_PLAYER_H
#define SHOOTERPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float speed;

    void initTexture();
    void initSprite();

public:
    Player();

    virtual ~Player();

    void move(float dirX, float dirY);

    void update();
    void render(sf::RenderTarget& target);
};


#endif //SHOOTERPROJECT_PLAYER_H
