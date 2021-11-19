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

void Player::update(float deltaTime, sf::RenderTarget& window, std::map<std::string, bool> keys, std::vector<Bullet*>& bullets) {
    if (keys["Left"] || keys["Right"] || keys["Up"] || keys["Down"]) {
        sf::Vector2<float> dir = {0, 0};

        if (keys["Left"])
            dir.x--;

        if (keys["Right"])
            dir.x++;

        if (keys["Up"]){
            dir.y--;
        }

        if (keys["Down"])
            dir.y++;

        move(dir, deltaTime);

        // Collision window
        // Left
        if (sprite.getPosition().x <= 0) {
            sprite.setPosition(0.f, sprite.getPosition().y);
        }
        // Right
        if (sprite.getPosition().x >= window.getSize().x - sprite.getGlobalBounds().width) {
            sprite.setPosition(window.getSize().x - sprite.getGlobalBounds().width, sprite.getPosition().y);
        }
        // Top
        if (sprite.getPosition().y <= 0) {
            sprite.setPosition(sprite.getPosition().x, 0.f);
        }
        //Bottom
        if (sprite.getPosition().y >= window.getSize().y - sprite.getGlobalBounds().height) {
            sprite.setPosition(sprite.getPosition().x, window.getSize().y - sprite.getGlobalBounds().height);
        }
    }

    if (keys["Shoot"]) {
        if (cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
            cooldownBullet.restart();
            sf::Texture textureBullet;
            sf::Vector2f pos{sprite.getPosition().x + 13, sprite.getPosition().y};
            sf::Vector2f dir{0.f, -1.f};
            bullets.push_back(new Bullet(textureBullet, pos, dir, 260.f));
        }
    }
}

void Player::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
