#include "../headers/Bullet.h"

Bullet::Bullet(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f dir, float movementSpeed) {
    sprite.setTexture(*texture);
    sprite.scale(0.4f, 0.4f);

    sf::Vector2u textureSize = sprite.getTexture()->getSize();
    sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);

    sprite.setPosition(pos);


    direction = dir;
    this->movementSpeed = movementSpeed;
}

Bullet::~Bullet() {

}

void Bullet::update(sf::Time deltaTime, sf::RenderTarget &target) {
    sprite.move(movementSpeed * direction * deltaTime.asSeconds());
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
