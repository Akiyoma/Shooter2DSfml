#include "Player.h"

void Player::initTexture() {
    if (!texture.loadFromFile("../Textures/ship.png")) {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
    }
}

void Player::initSprite() {
    sprite.setTexture(texture);
    //sprite.scale(.1f, .1f);
}

Player::Player() {
    speed = 1.f;

    initTexture();
    initSprite();
}

Player::~Player() {

}

void Player::move(float dirX, float dirY) {
    sprite.move(speed * dirX, speed * dirY);
}

void Player::update() {

}

void Player::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
