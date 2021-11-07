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

    void move(sf::Vector2<float> dir);
    sf::Vector2<float>& normalize(sf::Vector2<float> vec);

    void update();
    void render(sf::RenderTarget& target);

    sf::Vector2<float>  moveTo(sf::Vector2<float> dir);
};


#endif //SHOOTERPROJECT_PLAYER_H
