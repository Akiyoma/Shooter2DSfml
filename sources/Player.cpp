#include "../headers/Player.h"

void Player::initSprite(int x , int y, sf::Texture* texture) {

    sprite.setTexture(*texture);
    sprite.scale(2.0f, 2.0f);

    textureSizeX = texture->getSize().x;
    textureSizeY = texture->getSize().y;

    sprite.setOrigin(textureSizeX / 2, textureSizeY / 2);
    sprite.setPosition( x /2 , y/2);
}

Player::Player(int windowSizeX, int windowSizeY, sf::Texture* texture, sf::Texture* bulletTexture) {
    this->bulletTexture = *bulletTexture;
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
    sf::Vector2<float> vec = normalizeVector(direction);
    sprite.move(vec * speed * deltaTime.asSeconds());
}

void Player::shoot(std::vector<Bullet*>& bullets) {
    canShoot = false;
    coolDownBullet.restart();
    if (currentWeapon == 0) {
        weapon1(bullets);
    }
    else if (currentWeapon == 1) {
        weapon2(bullets);
    }
}

void Player::coolDownShoot() {
    if (!canShoot && coolDownBullet.getElapsedTime().asSeconds() > coolDownBulletTime) {
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

void Player::weapon1(std::vector<Bullet*>& bullets) {
    sf::Vector2f pos {sprite.getPosition().x, sprite.getPosition().y - textureSizeY * 2};
    sf::Vector2f pos2 {sprite.getPosition().x + 15, sprite.getPosition().y - textureSizeY * 2};
    sf::Vector2f pos3 {sprite.getPosition().x - 15, sprite.getPosition().y - textureSizeY * 2};
    sf::Vector2f dir {0.f, -1.f};
    sf::Vector2f dir2 {0.f, -1.f};
    sf::Vector2f dir3 {0.f, -1.f};
    Bullet* bullet1 = new Bullet(&bulletTexture, pos, dir, 560.f);
    Bullet* bullet2 = new Bullet(&bulletTexture, pos2, dir2, 560.f);
    Bullet* bullet3 = new Bullet(&bulletTexture, pos3, dir3, 560.f);
    bullets.push_back(bullet1);
    bullets.push_back(bullet2);
    bullets.push_back(bullet3);
}

void Player::weapon2(std::vector<Bullet*>& bullets) {
    sf::Vector2f pos {sprite.getPosition().x, sprite.getPosition().y - textureSizeY * 2};
    sf::Vector2f pos2 {sprite.getPosition().x + 15, sprite.getPosition().y - textureSizeY * 2};
    sf::Vector2f pos3 {sprite.getPosition().x - 15, sprite.getPosition().y - textureSizeY * 2};
    float angle1 = -80;
    float angle2 = -100;

    sf::Vector2f dir{0.f, -1.f};
    sf::Vector2f dir2 {degreeToVector(angle1)};
    sf::Vector2f dir3 {degreeToVector(angle2)};
    Bullet* bullet1 = new Bullet(&bulletTexture, pos, dir, 560.f);
    Bullet* bullet2 = new Bullet(&bulletTexture, pos2, dir2, 560.f);
    bullet2->sprite.rotate(10);
    Bullet* bullet3 = new Bullet(&bulletTexture, pos3, dir3, 560.f);
    bullet3->sprite.rotate(-10);
    bullets.push_back(bullet1);
    bullets.push_back(bullet2);
    bullets.push_back(bullet3);
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
    if (hp > 0) {
        if (keys["Left"] || keys["Right"] || keys["Up"] || keys["Down"]) {
            move(deltaTime, window, getDirection(keys));
        }
        collisionWindow(window);

        if (keys["ChangeWeapon"]) {
            changeWeapon(keys);
        }

        coolDownShoot();
        if (canShoot && keys["Shoot"])
            shoot(bullets);

        invulnerability();
    }
    else {
        sprite.setColor(sf::Color(255, 255, 255, 0));
        isInvulnerable = true;
        canShoot = false;
    }
}

void Player::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
