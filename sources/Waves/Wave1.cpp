#include "../../headers/Waves/Wave1.h"

Wave1::Wave1(Loader& loader, std::vector<Enemy*>& enemies, std::vector<Bullet*>& bullets) : Wave(loader, enemies, bullets) {
    enemies.push_back(new BasicEnemy(&loader.defaultEnemyTexture, &loader.redBulletTexture, {800, 50}));
    enemies.push_back(new BasicEnemy(&loader.defaultEnemyTexture, &loader.redBulletTexture, {500, 170}));
    enemies.push_back(new TwoTimePatrolEnemy(&loader.twoTimePatrolEnemyTexture, &loader.redBulletTexture, {100, 100}));
    enemies.push_back(new CircleEnemy(&loader.circleEnemyTexture, &loader.redBulletTexture, {512, 100}));

    enemies[0]->sprite.setPosition(900, -10);
    enemies[1]->sprite.setPosition(400,-10);
    enemies[2]->sprite.setPosition(-20,-10);
    enemies[3]->sprite.setPosition(512,-10);
}

Wave1::~Wave1() {

}
