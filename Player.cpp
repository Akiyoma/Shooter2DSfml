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
    speed = 3.f;

    initTexture();
    initSprite();
}

Player::~Player() {

}

void Player::move(sf::Vector2<float> dir) {
    sf::Vector2<float> vec = normalize(dir);
    sprite.move(vec);
    std::cout<<"X: "<<vec.x<<" Y: "<<vec.y<<" Length: "<<sqrt(vec.x*vec.x + vec.y*vec.y)<<std::endl;
}

sf::Vector2<float> &Player::normalize(sf::Vector2<float> vec) {
    float length = vec.x*vec.x + vec.y*vec.y;
    if (length == 0.f)
        return vec;
    length = sqrt(speed/length);
    vec.x = vec.x * length;
    vec.y = vec.y * length;
    return vec;
}


void Player::update() {

}

void Player::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
