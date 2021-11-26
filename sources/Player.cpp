#include "../headers/Player.h"

void Player::initTexture() {
    if (!texture.loadFromFile("../Galaxia Sprite Pack #1/Enemy/idle_bomber_green.png")) {
        std::cout << "Failed to load texture for player." << "\n";
    }

}

void Player::initSprite(int x , int y) {

    sprite.setTexture(texture);
    sprite.scale(2.0f, 2.0f);

    textureSizeX = texture.getSize().x;
    textureSizeY = texture.getSize().y;

    sprite.setOrigin(textureSizeX / 2, textureSizeY / 2);
    std::cout<<sprite.getOrigin().x;
    sprite.setPosition( x /2 , y/2);

}

Player::Player(int windowSizeX, int windowSizeY) {

    speed = 240.f;
    initTexture();
    initSprite(windowSizeX, windowSizeY);
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

void Player::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
