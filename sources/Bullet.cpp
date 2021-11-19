#include "../headers/Bullet.h"

void Bullet::initTexture() {
    if (!texture.loadFromFile("../Textures/ship.png")) {
        std::cout << "Failed to load texture for bullet." << "\n";
    }
}

Bullet::Bullet() {

}

Bullet::Bullet(sf::Texture& texture, sf::Vector2f pos, sf::Vector2f dir, float movementSpeed) {
    initTexture();
    sprite.setTexture(this->texture);
    sprite.setPosition(pos);
    sprite.scale(0.5f, 0.5f);
    direction = dir;
    this->movementSpeed = movementSpeed;
}

Bullet::~Bullet() {

}

void Bullet::update(float deltaTime, sf::RenderTarget &target) {
    sprite.move(movementSpeed * direction * deltaTime);
}

void Bullet::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

bool Bullet::isOutsideWindow(sf::RenderTarget &target, std::vector<Bullet*> bullets) {
    // Left
    if (sprite.getPosition().x + sprite.getGlobalBounds().width <= 0) {
        return true;
    }
    // Right
    if (sprite.getPosition().x >= target.getSize().x) {
        return true;
    }
    // Top
    if (sprite.getPosition().y + sprite.getGlobalBounds().height <= 0) {
        return true;
    }
    //Bottom
    if (sprite.getPosition().y >= target.getSize().y) {
        return true;
    }
    return false;
}
