#include "../../headers/Enemies/Enemy.h"

void Enemy::initSprite(sf::Texture* texture, float scaleX, float scaleY){
    sprite.setTexture(*texture);
    sprite.scale(scaleX, scaleY);
    sprite.setRotation(180);

    textureSizeX = texture->getSize().x;
    textureSizeY = texture->getSize().y;
}

bool Enemy::moveTo(sf::Vector2f pos, sf::Time deltaTime) {
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
    if (cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
        cooldownBullet.restart();
        sf::Vector2f pos{sprite.getPosition().x - textureSizeX, sprite.getPosition().y};
        bullets.push_back(new Bullet(&bulletTexture, pos, dir, speed));
        /**
         * Creer diférent type de direction
         *      strict bottom
         *      in player direction
         *      Following player
         * On pourra la définir comme type de munition dans la méthode fire d'une classe héritant de Enemy
         */
    }
}

Enemy::Enemy(sf::Texture* texture, sf::Texture* bulletTexture) {
    speed = 240.f;
    movePointId = 0;
    twoTimePattrolChecker = false;

    initSprite(texture, 2, 2);
    setCooldownBulletTime(0.5f);

    this->bulletTexture = *bulletTexture;

}

void Enemy::update(sf::Time deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets) {
    //moveTo(sf::Vector2f(400, 100), deltaTime);

    sf::Vector2f dir{0.f, 1.f};
    fire(dir, 440, bullets);
}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

void Enemy::setCooldownBulletTime(float cooldownBulletTime) {
    Enemy::cooldownBulletTime = cooldownBulletTime;
}

Enemy::~Enemy() {}

void Enemy::moveBetweenTwoPoint(std::vector<sf::Vector2<float>> movementPointPositions, sf::Time deltaTime) {

    if (movePointId == 0 )
    {
        if (moveTo(movementPointPositions[movePointId], deltaTime) ){
            movePointId++ ;
        }
    } else if (movePointId == 1){
        if (moveTo(movementPointPositions[movePointId], deltaTime) ){
            movePointId-- ;
        }
    }
}

void Enemy::getDamage(int n) {
    hp -= n;
}





