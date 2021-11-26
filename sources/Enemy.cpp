#include "../headers/Enemy.h"

void Enemy::initTexture(){
    if (!texture.loadFromFile("../Textures/enemy.png")) {
        std::cout << "Failed to load texture for enemy." << "\n";
    }
}

void Enemy::initSprite(){
    sprite.setTexture(texture);
}

void Enemy::moveTo(sf::Vector2f pos, float deltaTime) {
    sf::Vector2<float> vec{1,0};
    float length = vec.x*vec.x + vec.y*vec.y;
    if (length != 0.f) {
        length = sqrt(1.f/length);
        vec.x = vec.x * length;
        vec.y = vec.y * length;
    }
    float distX = std::abs(sprite.getPosition().x - pos.x);
    float distY = std::abs(sprite.getPosition().y - pos.y);
    if (distX > std::abs(vec.x * speed * deltaTime) || distY > std::abs(vec.y * speed * deltaTime)) {
        sprite.move(vec * speed * deltaTime);
    }
    else {
        sprite.setPosition(pos);
    }
}

Enemy::Enemy() {
    speed = 240.f;

    initTexture();
    initSprite();
}

void Enemy::update(float deltaTime) {
    moveTo(sf::Vector2f(501, 0), deltaTime);
}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

Enemy::~Enemy() {}
