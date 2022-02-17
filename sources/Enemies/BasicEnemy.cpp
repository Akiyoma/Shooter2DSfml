#include "../../headers/Enemies/BasicEnemy.h"

BasicEnemy::BasicEnemy(sf::Texture *texture, sf::Texture* bulletTexture, sf::Vector2f initialPos) : Enemy(texture, bulletTexture, initialPos) {
    setCooldownBulletTime(1.f);
}

BasicEnemy::~BasicEnemy() {

}

void BasicEnemy::update(sf::Time deltaTime, sf::RenderTarget &window, std::vector<Bullet *> &bullets) {
    Enemy::update(deltaTime, window, bullets);

    if (isAppear) {
        if (cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
            cooldownBullet.restart();
            sf::Vector2f dir{0.f, 1.f};
            fire(dir, 300, bullets);
        }
    }
}
