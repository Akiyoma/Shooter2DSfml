//
// Created by asus on 17/12/2021.
//
#include "Enemy.h"

#ifndef SHOOTER2DSFML_TWOTIMEPATROLENEMY_H
#define SHOOTER2DSFML_TWOTIMEPATROLENEMY_H


class TwoTimePatrolEnemy : public Enemy{
public:

    TwoTimePatrolEnemy(sf::Texture *texture, sf::Texture* bulletTexture, sf::Vector2f initialPos);
    void update(sf::Time deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets);
    virtual ~TwoTimePatrolEnemy();
//    void MovementPattern(float speed, float interval, std::vector<sf::Vector2<float>> movePointId);

};


#endif //SHOOTER2DSFML_TWOTIMEPATROLENEMY_H
