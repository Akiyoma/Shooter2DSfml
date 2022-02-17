#ifndef SHOOTER2DSFML_WAVE0_H
#define SHOOTER2DSFML_WAVE0_H


#include "Wave.h"

class Wave0 : public Wave {
public:
    Wave0(Loader &loader, std::vector<Enemy*>& enemies, std::vector<Bullet*>& bullets);

    virtual ~Wave0();
};


#endif //SHOOTER2DSFML_WAVE0_H
