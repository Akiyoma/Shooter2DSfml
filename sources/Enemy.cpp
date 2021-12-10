#include "../headers/Enemy.h"

void Enemy::initTexture(){
    if (!texture.loadFromFile("../Galaxia Sprite Pack #1/Enemy/idle_bomber_red.png")) {
        std::cout << "Failed to load texture for enemy." << "\n";
    }
    texture.setSmooth(false);
}

void Enemy::initSprite(){
    sprite.setTexture(texture);
    sprite.scale(2.0f, 2.0f);
    sprite.setRotation(180);

    textureSizeX = texture.getSize().x;
    textureSizeY = texture.getSize().y;
}

void Enemy::moveTo(sf::Vector2f pos, float deltaTime) {
    sf::Vector2f dir {pos.x - sprite.getPosition().x, pos.y - sprite.getPosition().y};
    float length = dir.x*dir.x + dir.y*dir.y;
    length = sqrt(length);
    dir = {dir.x / length, dir.y / length};

    float distX = std::abs(sprite.getPosition().x - pos.x);
    float distY = std::abs(sprite.getPosition().y - pos.y);
    if (distX > std::abs(dir.x * speed * deltaTime) || distY > std::abs(dir.y * speed * deltaTime)) {
        sprite.move(dir * speed * deltaTime);
    }
    else {
        sprite.setPosition(pos);
    }
}

bool Enemy::circularMoveTo(sf::Vector2f, float deltaTime) {
    for (int i = 0; i < 360; ++i) {
        i++;
        float sx = std::cos(i);
        float sy = std::sin(i);
        sprite.move(sx*deltaTime, sy*deltaTime);
    }


    return true;
}

void Enemy::fire(sf::Vector2f dir, float speed) {

}

Enemy::Enemy() {
    speed = 240.f;

    initTexture();
    initSprite();
}

void Enemy::update(float deltaTime, sf::RenderTarget& window, std::vector<Bullet*>& bullets) {
    moveTo(sf::Vector2f(400, 100), deltaTime);


    if (cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
        std::cout<<"test"<<std::endl;
        cooldownBullet.restart();
        sf::Texture textureBullet;
        sf::Vector2f pos{sprite.getPosition().x, sprite.getPosition().y + textureSizeY * 2};
        sf::Vector2f dir{0.f, 1.f};
        bullets.push_back(new Bullet(textureBullet, pos, dir, 560.f));
    }
}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

Enemy::~Enemy() {}
