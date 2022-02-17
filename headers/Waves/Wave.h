#ifndef SHOOTER2DSFML_WAVE_H
#define SHOOTER2DSFML_WAVE_H


#include "../Bullet.h"
#include "../Enemies/Enemy.h"
#include "../Enemies/BasicEnemy.h"
#include "../Enemies/TwoTimePatrolEnemy.h"
#include "../Enemies/CircleEnemy.h"
#include "../Loader.h"

class Wave {
private:
    std::vector<Bullet*>& bullets;
    std::vector<Enemy*>& enemies;

public:
    Wave(Loader& loader, std::vector<Enemy*>& enemies, std::vector<Bullet*>& bullets);

    virtual ~Wave();

    bool endWave();
};


#endif //SHOOTER2DSFML_WAVE_H
