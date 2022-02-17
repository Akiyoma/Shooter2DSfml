#include "../../headers/Waves/Wave0.h"

Wave0::Wave0(Loader &loader, std::vector<Enemy*> &enemies, std::vector<Bullet *> &bullets) : Wave(loader, enemies, bullets) {
    enemies.push_back(new BasicEnemy(&loader.defaultEnemyTexture, &loader.redBulletTexture, {624,150}));
    enemies.push_back(new BasicEnemy(&loader.defaultEnemyTexture, &loader.redBulletTexture, {400,150}));

    enemies[0]->sprite.setPosition(624,-10);
    enemies[1]->sprite.setPosition(400,-10);
}

Wave0::~Wave0() {

}
