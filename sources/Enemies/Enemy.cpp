#include "../../headers/Enemies/Enemy.h"

void Enemy::initSprite(sf::Texture* texture, float scaleX, float scaleY){
    sprite.setTexture(*texture);
    sprite.scale(scaleX, scaleY);
    sprite.setRotation(180);

    textureSizeX = texture->getSize().x;
    textureSizeY = texture->getSize().y;
}

bool Enemy::moveTo(sf::Vector2f pos, float deltaTime) {
    sf::Vector2f dir {pos.x - sprite.getPosition().x, pos.y - sprite.getPosition().y};
    float length = dir.x*dir.x + dir.y*dir.y;
    length = sqrt(length);
    dir = {dir.x / length, dir.y / length};

    float distX = std::abs(sprite.getPosition().x - pos.x);
    float distY = std::abs(sprite.getPosition().y - pos.y);
    if (distX > std::abs(dir.x * speed * deltaTime) || distY > std::abs(dir.y * speed * deltaTime)) {
        sprite.move(dir * speed * deltaTime);
    }
    else {
        sprite.setPosition(pos);
        return true;
    }
    return false;
}

void Enemy::moveBetweenTwoPoint(sf::Vector2f dest1, sf::Vector2f dest2, float deltaTime) {

    if (moveTo(dest1, deltaTime))
    {
        movePoint++;
    } else if (moveTo(dest2, deltaTime)){
        movePoint--;
    }
}

void Enemy::fire(sf::Vector2f dir, float speed , std::vector<Bullet*>& bullets) {
    if (cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
        cooldownBullet.restart();
        sf::Texture textureBullet;
        sf::Vector2f pos{sprite.getPosition().x - textureSizeX, sprite.getPosition().y};
        bullets.push_back(new Bullet(textureBullet, pos, dir, speed));
        /**
         * Creer diférent type de direction
         *      strict bottom
         *      in player direction
         *      Following player
         * On pourra la définir comme type de munition dans la méthode fire d'une classe héritant de Enemy
         */
    }
}

Enemy::Enemy(sf::Texture *texture) {
    speed = 240.f;

    //initTexture("../GalaxiaSpritePack/Enemy/idle_bomber_red.png");
    initSprite(texture, 2, 2);
    setCooldownBulletTime(0.5f);

}

void Enemy::update(float deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets) {
    //moveTo(sf::Vector2f(400, 100), deltaTime);

    sf::Vector2f dir{0.f, 1.f};
    fire(dir, 550, bullets);

}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

void Enemy::setCooldownBulletTime(float cooldownBulletTime) {
    Enemy::cooldownBulletTime = cooldownBulletTime;
}

Enemy::~Enemy() {}




