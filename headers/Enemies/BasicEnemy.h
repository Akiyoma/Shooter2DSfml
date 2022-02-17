#ifndef SHOOTER2DSFML_BASICENEMY_H
#define SHOOTER2DSFML_BASICENEMY_H

#include "Enemy.h"

class BasicEnemy : public Enemy {
public:
    BasicEnemy(sf::Texture *texture, sf::Texture* bulletTexture, sf::Vector2f initialPos);

    virtual ~BasicEnemy();

    void update(sf::Time deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets);
};


#endif //SHOOTER2DSFML_BASICENEMY_H
