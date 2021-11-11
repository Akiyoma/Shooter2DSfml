#include "Bullet.h"

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
    sprite.scale(.8f, .8f);
    direction = dir;
    this->movementSpeed = movementSpeed;
}

Bullet::~Bullet() {

}

void Bullet::update(float deltaTime) {
    sprite.move(movementSpeed * direction * deltaTime);
}

void Bullet::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
