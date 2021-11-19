#include "../headers/Player.h"

void Player::initTexture() {
    if (!texture.loadFromFile("../Textures/ship.png")) {
        std::cout << "Failed to load texture for player." << "\n";
    }
}

void Player::initSprite() {
    sprite.setTexture(texture);
    sprite.scale(1.0f, 1.0f);
}

Player::Player() {
    speed = 240.f;

    initTexture();
    initSprite();
}

Player::~Player() {

}

void Player::move(sf::Vector2f dir, float deltaTime) {
    sf::Vector2<float> vec = normalize(dir);
    sprite.move(vec * speed * deltaTime);
    //std::cout<<"X: "<<vec.x<<" Y: "<<vec.y<<" Length: "<<sqrt(vec.x*vec.x + vec.y*vec.y)<<std::endl;
}

sf::Vector2f &Player::normalize(sf::Vector2f vec) {
    float length = vec.x*vec.x + vec.y*vec.y;
    if (length == 0.f)
        return vec;
    length = sqrt(1.f/length);
    vec.x = vec.x * length;
    vec.y = vec.y * length;
    return vec;
}

sf::Vector2f  Player::moveTo(sf::Vector2f dir){
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
