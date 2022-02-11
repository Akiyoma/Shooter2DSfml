#include "../headers/Player.h"

void Player::initSprite(int x , int y, sf::Texture* texture) {

    sprite.setTexture(*texture);
    sprite.scale(2.0f, 2.0f);

    textureSizeX = texture->getSize().x;
    textureSizeY = texture->getSize().y;

    sprite.setOrigin(textureSizeX / 2, textureSizeY / 2);
    sprite.setPosition( x /2 , y/2);

    //sprite.setColor(sf::Color::Red);
}

Player::Player(int windowSizeX, int windowSizeY, sf::Texture* texture) {

    speed = 240.f;
    initSprite(windowSizeX, windowSizeY, texture);
}

Player::~Player() {

}

sf::Vector2f Player::getDirection(std::map<std::string, bool>& keys) {
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

void Player::move(sf::Time deltaTime, sf::RenderTarget& window, sf::Vector2f direction) {
    sf::Vector2<float> vec = normalize(direction);
    sprite.move(vec * speed * deltaTime.asSeconds());
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

void Player::shoot(std::vector<Bullet*>& bullets) {
    canShoot = false;
    cooldownBullet.restart();
    sf::Texture textureBullet;
    if (currentWeapon == 0) {
        sf::Vector2f pos{sprite.getPosition().x, sprite.getPosition().y - textureSizeY * 2};
        sf::Vector2f pos2{sprite.getPosition().x + 15, sprite.getPosition().y - textureSizeY * 2};
        sf::Vector2f pos3{sprite.getPosition().x - 15, sprite.getPosition().y - textureSizeY * 2};
        sf::Vector2f dir{0.f, -1.f};
        sf::Vector2f dir2{0.f, -1.f};
        sf::Vector2f dir3{0.f, -1.f};
        Bullet* bullet1 = new Bullet(textureBullet, pos, dir, 560.f);
        Bullet* bullet2 = new Bullet(textureBullet, pos2, dir2, 560.f);
        Bullet* bullet3 = new Bullet(textureBullet, pos3, dir3, 560.f);
        bullets.push_back(bullet1);
        bullets.push_back(bullet2);
        bullets.push_back(bullet3);
    }
    else if (currentWeapon == 1) {
        sf::Vector2f pos{sprite.getPosition().x, sprite.getPosition().y - textureSizeY * 2};
        sf::Vector2f pos2{sprite.getPosition().x + 15, sprite.getPosition().y - textureSizeY * 2};
        sf::Vector2f pos3{sprite.getPosition().x - 15, sprite.getPosition().y - textureSizeY * 2};
        sf::Vector2f dir{0.f, -1.f};
        sf::Vector2f dir2{0.5f, -0.86f};
        sf::Vector2f dir3{-0.5f, -0.86f};
        Bullet* bullet1 = new Bullet(textureBullet, pos, dir, 560.f);
        Bullet* bullet2 = new Bullet(textureBullet, pos2, dir2, 560.f);
        bullet2->sprite.rotate(30);
        Bullet* bullet3 = new Bullet(textureBullet, pos3, dir3, 560.f);
        bullet3->sprite.rotate(-30);
        bullets.push_back(bullet1);
        bullets.push_back(bullet2);
        bullets.push_back(bullet3);
    }
}

void Player::cooldownShoot() {
    if (!canShoot && cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
        canShoot = true;
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

void Player::changeWeapon(std::map<std::string, bool>& keys) {
    currentWeapon++;
    if (currentWeapon > 1)
        currentWeapon = 0;
    // Change with the event
    keys["ChangeWeapon"] = false;
}

void Player::getDamage(int n) {
    hp -= n;
    isInvulnerable = true;
    invulnerabilityTime.restart();
}

void Player::invulnerability() {
    if (isInvulnerable) {
        sf::Color red(255, 0, 0, 125);
        sf::Color white(255, 255, 255, 125);
        if (invulnerabilityTime.getElapsedTime().asSeconds() < 0.5f)
            sprite.setColor(red);
        else if (invulnerabilityTime.getElapsedTime().asSeconds() < 1.f)
            sprite.setColor(white);
        else if (invulnerabilityTime.getElapsedTime().asSeconds() < 1.5f)
            sprite.setColor(red);
        else if (invulnerabilityTime.getElapsedTime().asSeconds() >= 1.5f) {
            sprite.setColor(sf::Color(255, 255, 255, 255));
            isInvulnerable = false;
        }
    }
}


void Player::update(sf::Time deltaTime, sf::RenderTarget& window, std::map<std::string, bool>& keys, std::vector<Bullet*>& bullets) {
    if (keys["Left"] || keys["Right"] || keys["Up"] || keys["Down"]) {
        move(deltaTime, window, getDirection(keys));
    }
    collisionWindow(window);

    if (keys["ChangeWeapon"]) {
        changeWeapon(keys);
    }

    cooldownShoot();
    if (canShoot && keys["Shoot"])
        shoot(bullets);
    invulnerability();
}

void Player::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
