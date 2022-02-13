#include "../../headers/Enemies/TwoTimePatrolEnemy.h"

TwoTimePatrolEnemy::TwoTimePatrolEnemy(sf::Texture *texture) : Enemy(texture) {
    initSprite(texture, 1, 1);
    setCooldownBulletTime(0.5f);
}

//void Enemy::update(float deltaTime, sf::RenderTarget &window, std::vector<Bullet *> &bullets) {
//    sf::Vector2f dir{0.f, 1.f};
//    fire(dir, 550, bullets);
//
//    sf::Vector2f dest1 ={100, 100};
//    sf::Vector2f dest2 ={500, 500};
//    moveBetweenTwoPoint(dest1, dest2, deltaTime);
//}

TwoTimePatrolEnemy::~TwoTimePatrolEnemy() {

}

void TwoTimePatrolEnemy::update(sf::Time deltaTime, sf::RenderTarget &window, std::vector<Bullet *> &bullets) {
    Enemy::update(deltaTime, window, bullets);

    sf::Vector2f dest1 ={100, 100};
    sf::Vector2f dest2 ={500, 100};

    std::vector<sf::Vector2<float>> movementPoints = {dest1, dest2};

    moveBetweenTwoPoint(movementPoints, deltaTime);
}

/*void TwoTimePatrolEnemy::MovementPattern(float speed, float interval, std::vector<sf::Vector2<float>> movePointId) {



}*/
