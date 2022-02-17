#ifndef SHOOTER2DSFML_CIRCLEENEMY_H
#define SHOOTER2DSFML_CIRCLEENEMY_H

#include "Enemy.h"

class CircleEnemy : public Enemy {
public:
    CircleEnemy(sf::Texture *texture, sf::Texture* bulletTexture, sf::Vector2f initialPos);

    virtual ~CircleEnemy();

    void update(sf::Time deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets);
};


#endif //SHOOTER2DSFML_CIRCLEENEMY_H
