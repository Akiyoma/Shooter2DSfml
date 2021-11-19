#include "../headers/Enemy.h"

void Enemy::initTexture(){
    if (!texture.loadFromFile("../Textures/enemy.png")) {
        std::cout << "Failed to load texture for enemy." << "\n";
    }
}

void Enemy::initSprite(){
    sprite.setTexture(texture);
}

Enemy::Enemy() {
    speed = 240.f;

    initTexture();
    initSprite();
}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

Enemy::~Enemy() {}
