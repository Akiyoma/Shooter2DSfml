#include "../../headers/Enemy.h"

void Enemy::initTexture(){
    if (!texture.loadFromFile("../Galaxia Sprite Pack #1/Enemy/idle_bomber_red.png")) {
        std::cout << "Failed to load texture for enemy." << "\n";
    }
    texture.setSmooth(false);
}

void Enemy::initSprite(){
    sprite.setTexture(texture);
    sprite.scale(2.0f, 2.0f);
    sprite.setRotation(180);

    textureSizeX = texture.getSize().x;
    textureSizeY = texture.getSize().y;
}

void Enemy::moveTo(sf::Vector2f pos, float deltaTime) {
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
    }
}

void Enemy::fire(sf::Vector2f dir, float speed , std::vector<Bullet*>& bullets) {
    if (cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
        std::cout<<"test"<<std::endl;
        cooldownBullet.restart();
        sf::Texture textureBullet;
        sf::Vector2f pos{sprite.getPosition().x - textureSizeX, sprite.getPosition().y};
        bullets.push_back(new Bullet(textureBullet, pos, dir, speed));
        /** *
         * Creer diférent type de direction
         *      strict bottom
         *      in player direction
         *      Following player
         * On pourra la définir comme type de munition dans la méthode fire d'une classe héritant de Enemy
         */
    }
}

Enemy::Enemy() {
    speed = 240.f;

    initTexture();
    initSprite();
}

void Enemy::update(float deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets) {
    moveTo(sf::Vector2f(400, 100), deltaTime);

    sf::Vector2f dir{0.f, 1.f};
    setCooldownBulletTime(0.5f);
    fire(dir, 550, bullets);


}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

Enemy::~Enemy() {}

void Enemy::setCooldownBulletTime(float cooldownBulletTime) {
    Enemy::cooldownBulletTime = cooldownBulletTime;
}
