#include "../../headers/Enemies/TwoTimePatrolEnemy.h"



TwoTimePatrolEnemy::TwoTimePatrolEnemy() {
    initTexture("../GalaxiaSpritePack/Enemy/idle_drone_orange.png");
    setCooldownBulletTime(0.3);
}

//void Enemy::update(float deltaTime, sf::RenderTarget &window, std::vector<Bullet *> &bullets) {
//    sf::Vector2f dir{0.f, 1.f};
//    fire(dir, cooldownBulletTime, bullets);
//}

TwoTimePatrolEnemy::~TwoTimePatrolEnemy() {

}
