#include "../../headers/Enemies/TwoTimePatrolEnemy.h"

TwoTimePatrolEnemy::TwoTimePatrolEnemy(sf::Texture *texture, sf::Texture* bulletTexture, sf::Vector2f initialPos) : Enemy(texture, bulletTexture, initialPos) {
    setCooldownBulletTime(1.f);
    hp = 15;
}

TwoTimePatrolEnemy::~TwoTimePatrolEnemy() {

}

void TwoTimePatrolEnemy::update(sf::Time deltaTime, sf::RenderTarget &window, std::vector<Bullet *> &bullets) {
    Enemy::update(deltaTime, window, bullets);

    if (isAppear) {
        if (cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
            cooldownBullet.restart();
            sf::Vector2f dir{0.f, 1.f};
            fire(dir, 300, bullets);
        }

        sf::Vector2f dest1 ={100, 100};
        sf::Vector2f dest2 ={500, 100};

        std::vector<sf::Vector2<float>> movementPoints = {dest1, dest2};

        moveBetweenTwoPoint(movementPoints, deltaTime);
    }
}

/*void TwoTimePatrolEnemy::MovementPattern(float speed, float interval, std::vector<sf::Vector2<float>> movePointId) {



}*/
