#include "../headers/Player.h"

void Player::initSprite(int x , int y, sf::Texture* texture) {

    sprite.setTexture(*texture);
    sprite.scale(2.0f, 2.0f);

    textureSizeX = texture->getSize().x;
    textureSizeY = texture->getSize().y;

    sprite.setOrigin(textureSizeX / 2, textureSizeY / 2);
    sprite.setPosition( x /2 , y/2);

}

Player::Player(int windowSizeX, int windowSizeY, sf::Texture* texture) {

    speed = 240.f;
    initSprite(windowSizeX, windowSizeY, texture);
}

Player::~Player() {

}

sf::Vector2f Player::getDirection(std::map<std::string, bool> keys) {
    sf::Vector2f dir = {0, 0};

    if (keys["Left"])
        dir.x--;

    if (keys["Right"])
        dir.x++;

    if (keys["Up"]){
        dir.y--;
    }

    if (keys["Down"])
        dir.y++;

    return dir;
}

void Player::move(float deltaTime, sf::RenderTarget& window, std::map<std::string, bool> keys) {
    if (keys["Left"] || keys["Right"] || keys["Up"] || keys["Down"]) {
        sf::Vector2<float> vec = normalize(getDirection(keys));
        sprite.move(vec * speed * deltaTime);

        collisionWindow(window);
    }
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

void Player::shoot(std::map<std::string, bool> keys, std::vector<Bullet*>& bullets) {
    if (keys["Shoot"]) {
        if (cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
            cooldownBullet.restart();
            sf::Texture textureBullet;
            sf::Vector2f pos{sprite.getPosition().x, sprite.getPosition().y - textureSizeY * 2};
            sf::Vector2f dir{0.f, -1.f};
            bullets.push_back(new Bullet(textureBullet, pos, dir, 560.f));
        }
    }
}

void Player::collisionWindow(sf::RenderTarget &window) {
    // Left
    if (sprite.getPosition().x <= textureSizeX)  {
        sprite.setPosition(textureSizeX , sprite.getPosition().y);
    }
    // Right
    if (sprite.getPosition().x + textureSizeX >= window.getSize().x) {
        sprite.setPosition(window.getSize().x - textureSizeX, sprite.getPosition().y);
    }
    // Top
    if (sprite.getPosition().y <= textureSizeY + window.getSize().y * 0.33) {
        sprite.setPosition(sprite.getPosition().x, textureSizeY + window.getSize().y * 0.33);
    }
    //Bottom
    if (sprite.getPosition().y + textureSizeY >= window.getSize().y) {
        sprite.setPosition(sprite.getPosition().x, window.getSize().y - textureSizeY);
    }
}

void Player::update(float deltaTime, sf::RenderTarget& window, std::map<std::string, bool> keys, std::vector<Bullet*>& bullets) {
    move(deltaTime, window, keys);
    shoot(keys, bullets);
}

void Player::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
