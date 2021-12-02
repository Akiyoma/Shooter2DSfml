#include "../headers/Game.h"

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Shooter 2D SFML");
    window->setVerticalSyncEnabled(true);
}

Game::Game() {
    initWindow();

    player = new Player(window->getSize().x, window->getSize().y);
    enemies.push_back(new Enemy);
    enemies.push_back(new Enemy);

    enemies[0]->sprite.setPosition(500,700);

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
    keys["Left"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    keys["Right"] = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    keys["Up"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    keys["Down"] = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    keys["Shoot"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void Game::update() {
    updatePollEvents();
    updateInput();

    player->update(deltaTime, *window, keys, bullets);

    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i]->update(deltaTime, *window);
        if (bullets[i]->isOutsideWindow(*window, bullets)) {
            bullets.erase(bullets.begin()+i);
        }
        else if (!enemies.empty()) {
            if (bullets[i]->sprite.getGlobalBounds().intersects(enemies[0]->sprite.getGlobalBounds())) {
                enemies.erase(enemies.begin());
                bullets.erase(bullets.begin() + i);
            }
        }
    }

    for (int i = 0; i < enemies.size(); ++i) {
        enemies[i]->update(deltaTime);
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
