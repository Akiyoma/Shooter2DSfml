#include "../../headers/Enemies/Enemy.h"

void Enemy::initSprite(sf::Texture* texture, float scaleX, float scaleY){
    sprite.setTexture(*texture);
    sprite.scale(scaleX, scaleY);
    sprite.setRotation(180);

    textureSizeX = texture->getSize().x;
    textureSizeY = texture->getSize().y;

    sprite.setOrigin(textureSizeX / scaleX, textureSizeY / scaleY);
}

bool Enemy::moveTo(sf::Vector2f pos, float speed, sf::Time deltaTime) {
    sf::Vector2f dir {pos.x - sprite.getPosition().x, pos.y - sprite.getPosition().y};
    dir = normalizeVector(dir);

    float distX = std::abs(sprite.getPosition().x - pos.x);
    float distY = std::abs(sprite.getPosition().y - pos.y);
    if (distX > std::abs(dir.x * speed * deltaTime.asSeconds()) || distY > std::abs(dir.y * speed * deltaTime.asSeconds())) {
        sprite.move(dir * speed * deltaTime.asSeconds());
    }
    else {
        sprite.setPosition(pos);
        return true;
    }
    return false;
}


void Enemy::fire(sf::Vector2f dir, float speed , std::vector<Bullet*>& bullets) {
    sf::Vector2f pos {sprite.getPosition().x, sprite.getPosition().y};
    bullets.push_back(new Bullet(&bulletTexture, pos, dir, speed));
}

Enemy::Enemy(sf::Texture* texture, sf::Texture* bulletTexture, sf::Vector2f initialPos) : initialPos(initialPos) {
    speed = 150.f;
    movePointId = 0;

    initSprite(texture, 2, 2);
    setCoolDownBulletTime(1.f);

    this->bulletTexture = *bulletTexture;
}

void Enemy::update(sf::Time deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets) {
    if (!isAppear)
        appear(initialPos, deltaTime);
}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

void Enemy::setCoolDownBulletTime(float coolDownBulletTime) {
    Enemy::coolDownBulletTime = coolDownBulletTime;
}

Enemy::~Enemy() {}

void Enemy::moveBetweenTwoPoint(std::vector<sf::Vector2<float>> movementPointPositions, sf::Time deltaTime) {

    if (movePointId == 0 )
    {
        if (moveTo(movementPointPositions[movePointId], speed, deltaTime)){
            movePointId++ ;
        }
    } else if (movePointId == 1){
        if (moveTo(movementPointPositions[movePointId], speed, deltaTime)){
            movePointId-- ;
        }
    }
}

void Enemy::getDamage(int n) {
    hp -= n;
}

void Enemy::circleAttack(int n, float speed, std::vector<Bullet *> &bullets) {
    float angleBetweenBullet = 360.f / n;
    float angle = 0;
    for (int i = 0; i < n; ++i) {
        sf::Vector2f pos {sprite.getPosition().x, sprite.getPosition().y};
        sf::Vector2f dir {degreeToVector(angle)};
        Bullet* bullet = new Bullet(&bulletTexture, pos, dir, speed);
        bullet->sprite.rotate(angle+90);
        bullets.push_back(bullet);
        angle += angleBetweenBullet;
    }
}

void Enemy::appear(sf::Vector2f pos, sf::Time deltaTime) {
    if (moveTo(pos, 350, deltaTime))
        isAppear = true;
}





