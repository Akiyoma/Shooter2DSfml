#include "../../headers/Enemies/CircleEnemy.h"

CircleEnemy::CircleEnemy(sf::Texture *texture, sf::Texture* bulletTexture, sf::Vector2f initialPos) : Enemy(texture, bulletTexture, initialPos) {
    setCoolDownBulletTime(1.5f);
    hp = 20;
}

CircleEnemy::~CircleEnemy() {

}

void CircleEnemy::update(sf::Time deltaTime, sf::RenderTarget &window, std::vector<Bullet *> &bullets) {
    Enemy::update(deltaTime, window, bullets);

    if (isAppear) {
        if (coolDownBullet.getElapsedTime().asSeconds() > coolDownBulletTime) {
            coolDownBullet.restart();
            int n = 6 + (rand() % 7);
            circleAttack(n, 70, bullets);
        }
    }
}
