#ifndef SHOOTER2DSFML_WAVE1_H
#define SHOOTER2DSFML_WAVE1_H


#include "Wave.h"

class Wave1 : public Wave {
public:
    Wave1(Loader& loader, std::vector<Enemy*>& enemies, std::vector<Bullet*>& bullets);

    virtual ~Wave1();
};


#endif //SHOOTER2DSFML_WAVE1_H
