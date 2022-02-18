#include "../../headers/Enemies/TwoTimePatrolEnemy.h"

TwoTimePatrolEnemy::TwoTimePatrolEnemy(sf::Texture *texture, sf::Texture* bulletTexture, sf::Vector2f initialPos, sf::Vector2f dest1, sf::Vector2f dest2) : Enemy(texture, bulletTexture, initialPos), dest1(dest1), dest2(dest2) {
    setCoolDownBulletTime(1.f);
    hp = 15;
}

TwoTimePatrolEnemy::~TwoTimePatrolEnemy() {

}

void TwoTimePatrolEnemy::update(sf::Time deltaTime, sf::RenderTarget &window, std::vector<Bullet *> &bullets) {
    Enemy::update(deltaTime, window, bullets);

    if (isAppear) {
        if (coolDownBullet.getElapsedTime().asSeconds() > coolDownBulletTime) {
            coolDownBullet.restart();
            sf::Vector2f dir{0.f, 1.f};
            fire(dir, 300, bullets);
        }

        std::vector<sf::Vector2<float>> movementPoints = {dest1, dest2};

        moveBetweenTwoPoint(movementPoints, deltaTime);
    }
}