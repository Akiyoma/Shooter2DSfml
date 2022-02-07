//
// Created by asus on 17/12/2021.
//
#include "Enemy.h"

#ifndef SHOOTER2DSFML_TWOTIMEPATROLENEMY_H
#define SHOOTER2DSFML_TWOTIMEPATROLENEMY_H


class TwoTimePatrolEnemy : public Enemy{
public:
    sf::Vector2f dest1;
    sf::Vector2f dest2;
    TwoTimePatrolEnemy(sf::Texture *texture);
    void update(float deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets);
    virtual ~TwoTimePatrolEnemy();

};


#endif //SHOOTER2DSFML_TWOTIMEPATROLENEMY_H
