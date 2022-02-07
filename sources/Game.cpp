#include "../headers/Game.h"

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Shooter 2D SFML");
    window->setVerticalSyncEnabled(true);
}

Game::Game() {

    loader = new Loader();
    loader->loadGame();

    initWindow();

    player = new Player(window->getSize().x, window->getSize().y, &loader->playerTexture);
    enemies.push_back(new Enemy(&loader->defaultEnemyTexture));
    enemies.push_back(new Enemy(&loader->defaultEnemyTexture));
    enemies.push_back(new TwoTimePatrolEnemy(&loader->twoTimePatrolEnemyTexture));

    enemies[0]->sprite.setPosition(500,700);
    enemies[1]->sprite.setPosition(400,400);
    enemies[2]->sprite.setPosition(300,500);

    bullets.reserve(10);
    ennemiesBullets.reserve(100);

}

Game::~Game() {
    delete window;
    delete player;

    for (auto *bullet : bullets) {
        delete bullet;
    }

    for (auto *bullet : ennemiesBullets) {
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
    for (int i = 0; i < enemies.size(); ++i) {
        enemies[i]->update(deltaTime,*window , ennemiesBullets);
    }

    std::vector<Bullet*> bulletsToDelete;
    std::vector<Enemy*> enemiesToDelete;
    std::vector<Bullet*> enemiesBulletsToDelete;

    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i]->update(deltaTime, *window);
        if (bullets[i]->isOutsideWindow(*window, bullets)) {
            bulletsToDelete.push_back(bullets[i]);
        }
        else if (!enemies.empty()) {
            for (int j = 0; j < enemies.size(); ++j) {
                if (bullets[i]->sprite.getGlobalBounds().intersects(enemies[j]->sprite.getGlobalBounds())) {
                    enemiesToDelete.push_back(enemies[j]);
                    bulletsToDelete.push_back(bullets[i]);
                }
            }
        }
    }

    for (int i = 0; i < ennemiesBullets.size(); ++i) {
        ennemiesBullets[i]->update(deltaTime, *window);
        if (ennemiesBullets[i]->isOutsideWindow(*window, ennemiesBullets)) {
            ennemiesBullets.erase(ennemiesBullets.begin()+i);
        }
    }

    // Delete bullets
    for (auto bullet: bulletsToDelete) {
        bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());
    }
    bulletsToDelete.clear();

    // Delete enemies
    for (auto enemy: enemiesToDelete) {
        //vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
        enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
    }
    enemiesToDelete.clear();

    // Delete enemies bullets
    for (auto bullet: ennemiesBullets) {
        ennemiesBullets.erase(std::remove(ennemiesBullets.begin(), ennemiesBullets.end(), bullet), ennemiesBullets.end());
    }
    enemiesBulletsToDelete.clear();
}

void Game::render() {
    window->clear();


    player->render(*window);

    for (auto *bullet : bullets) {
        bullet->render(*window);
    }

    for (auto *bullet : ennemiesBullets) {
        bullet->render(*window);
    }

    for (auto *enemy : enemies) {
        enemy->render(*window);
    }

    window->display();
}
