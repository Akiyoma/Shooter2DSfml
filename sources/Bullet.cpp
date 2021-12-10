#include "../headers/Bullet.h"

void Bullet::initTexture() {
    if (!texture.loadFromFile("../Galaxia Sprite Pack #1/Effects/LaserBlue.png")) {
        std::cout << "Failed to load texture for bullet." << "\n";
    }
    texture.setSmooth(false);
}

Bullet::Bullet(sf::Texture& texture, sf::Vector2f pos, sf::Vector2f dir, float movementSpeed) {
    initTexture();
    sprite.setTexture(this->texture);
    sprite.scale(0.5f, 0.5f);

    sprite.setPosition(pos);


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
