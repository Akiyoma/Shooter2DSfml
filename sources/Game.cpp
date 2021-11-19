#include "../headers/Game.h"

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Shooter 2D SFML");
    window->setVerticalSyncEnabled(true);
}

Game::Game() {
    initWindow();

    player = new Player();
    enemies.push_back(new Enemy);
    enemies.push_back(new Enemy);

}

Game::~Game() {
    delete window;
    delete player;

    for (auto *bullet : bullets) {
        delete bullet;
    }

    for (auto *enemy : enemies) {
        delete enemy;
    }
}

void Game::run() {
    while (window->isOpen()) {
        float currentTime = clock.getElapsedTime().asSeconds();
        accumulator += currentTime - lastTime;
        lastTime = currentTime;
        while (accumulator >= deltaTime) {
            update();


            accumulator -= deltaTime;
        }

        render();
    }
}

void Game::updatePollEvents() {
    sf::Event event;

    while (window->pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void Game::updateInput() {
    bool keyLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool keyRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool keyUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool keyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    if (keyLeft || keyRight || keyUp || keyDown) {

        sf::Vector2<float> dir = {0, 0};

        if (keyLeft)
            dir.x--;

        if (keyRight)
            dir.x++;

        if (keyUp){
            dir.y--;
        }

        if (keyDown)
            dir.y++;


        player->move(dir, deltaTime);

        // Collision window
        // Left
        if (player->sprite.getPosition().x <= 0) {
            player->sprite.setPosition(0.f, player->sprite.getPosition().y);
        }
        // Right
        if (player->sprite.getPosition().x >= window->getSize().x - player->sprite.getGlobalBounds().width) {
            player->sprite.setPosition(window->getSize().x - player->sprite.getGlobalBounds().width, player->sprite.getPosition().y);
        }
        // Top
        if (player->sprite.getPosition().y <= 0) {
            player->sprite.setPosition(player->sprite.getPosition().x, 0.f);
        }
        //Bottom
        if (player->sprite.getPosition().y >= window->getSize().y - player->sprite.getGlobalBounds().height) {
            player->sprite.setPosition(player->sprite.getPosition().x, window->getSize().y - player->sprite.getGlobalBounds().height);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (cooldownBullet.getElapsedTime().asSeconds() > cooldownBulletTime) {
            cooldownBullet.restart();
            sf::Texture texture;
            sf::Vector2f pos{player->sprite.getPosition().x + 13, player->sprite.getPosition().y};
            sf::Vector2f dir{0.f, -1.f};
            bullets.push_back(new Bullet(texture, pos, dir, 260.f));
        }
    }
}

void Game::update() {
    updatePollEvents();
    updateInput();


    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i]->update(deltaTime, *window);
        if (bullets[i]->isOutsideWindow(*window, bullets)) {
            bullets.erase(bullets.begin()+i);
        }
        else if (enemies.size() >= 1) {
            if (bullets[i]->sprite.getGlobalBounds().intersects(enemies[0]->sprite.getGlobalBounds())) {
                enemies.erase(enemies.begin());
                bullets.erase(bullets.begin() + i);
            }
        }
    }

}

void Game::render() {
    window->clear();


    player->render(*window);

    for (auto *bullet : bullets) {
        bullet->render(*window);
    }

    for (auto *enemy : enemies) {
        enemy->render(*window);
    }

    window->display();
}
