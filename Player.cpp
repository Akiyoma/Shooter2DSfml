#include "Player.h"

void Player::initTexture() {
    if (!texture.loadFromFile("../Textures/ship.png")) {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
    }
}

void Player::initSprite() {
    sprite.setTexture(texture);
    sprite.scale(1.0f, 1.0f);
}

Player::Player() {
    speed = 2.f;

    initTexture();
    initSprite();
}

Player::~Player() {

}

void Player::move(sf::Vector2<float> dir) {
    moveTo(dir);
    sf::Vector2<float> vec = normalize(dir);
    sprite.move(vec);
    //std::cout<<"X: "<<vec.x<<" Y: "<<vec.y<<" Length: "<<sqrt(vec.x*vec.x + vec.y*vec.y)<<std::endl;
}

sf::Vector2<float> &Player::normalize(sf::Vector2<float> vec) {
    float length = vec.x*vec.x + vec.y*vec.y;
    if (length == 0.f)
        return vec;
    length = sqrt(1.f/length)*speed;
    vec.x = vec.x * length;
    vec.y = vec.y * length;
    return vec;
}

sf::Vector2<float>  Player::moveTo(sf::Vector2<float> dir){
    this->sprite.getPosition().x;

    float moveToX = sprite.getPosition().x + dir.x;
    float moveToY = sprite.getPosition().y + dir.y;
    sf::Vector2<float> moveToVec;
    moveToVec.x = moveToX;
    moveToVec.y = moveToY;

    return moveToVec;
}

void Player::update() {

}

void Player::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
