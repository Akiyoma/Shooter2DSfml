#include "../headers/Level.h"

Level::Level(sf::RenderWindow& window, Loader& loader) : loader(loader) {
    player = new Player(window.getSize().x, window.getSize().y, &loader.playerTexture, &loader.bulletTexture);

    wave = new Wave(loader, enemies, enemiesBullets);

    bullets.reserve(10);
    enemiesBullets.reserve(100);

    scoreText.setFont(loader.font);
    scoreText.setString("Score : 0");
    scoreText.setPosition(0, 0);

    hpText.setFont(loader.font);
    hpText.setString("HP : " + std::to_string(player->hp));
    hpText.setPosition(window.getSize().x - 100, 0);

    gameOverText.setFont(loader.font);
    gameOverText.setString("Game over");
    gameOverText.setFillColor(sf::Color(255, 255, 255, 0));
    sf::FloatRect gameOverRect = gameOverText.getLocalBounds();
    gameOverText.setPosition(window.getSize().x / 2 - gameOverRect.width / 2, window.getSize().y / 2 - gameOverRect.height / 2);
}

Level::~Level() {
    delete player;

    for (auto bullet : bullets) {
        delete bullet;
    }

    for (auto bullet : enemiesBullets) {
        delete bullet;
    }

    for (auto enemy : enemies) {
        delete enemy;
    }
}

void Level::update(sf::RenderWindow& window, sf::Time deltaTime, std::map<std::string, bool>& keys, GameState& state) {
    player->update(deltaTime, window, keys, bullets);
    for (int i = 0; i < enemies.size(); ++i) {
        enemies[i]->update(deltaTime, window , enemiesBullets);
    }

    std::vector<Bullet*> bulletsToDelete;
    std::vector<Enemy*> enemiesToDelete;
    std::vector<Bullet*> enemiesBulletsToDelete;

    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i]->update(deltaTime, window);
        if (bullets[i]->isOutsideWindow(window, bullets)) {
            bulletsToDelete.push_back(bullets[i]);
        }
        else if (!enemies.empty()) {
            for (int j = 0; j < enemies.size(); ++j) {
                if (bullets[i]->sprite.getGlobalBounds().intersects(enemies[j]->sprite.getGlobalBounds())) {
                    bulletsToDelete.push_back(bullets[i]);
                    enemies[j]->getDamage(1);
                    if (enemies[j]->hp <= 0) {
                        enemiesToDelete.push_back(enemies[j]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < enemiesBullets.size(); ++i) {
        enemiesBullets[i]->update(deltaTime, window);
        if (enemiesBullets[i]->isOutsideWindow(window, enemiesBullets)) {
            enemiesBulletsToDelete.push_back(enemiesBullets[i]);
        }
        else if (enemiesBullets[i]->sprite.getGlobalBounds().intersects(player->sprite.getGlobalBounds()) && player->hp > 0) {
            enemiesBulletsToDelete.push_back(enemiesBullets[i]);
            if (!player->isInvulnerable)
                reduceHp(1);
        }
    }

    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i]->sprite.getGlobalBounds().intersects(player->sprite.getGlobalBounds()) && !player->isInvulnerable) {
            reduceHp(1);
        }
    }

    // Delete bullets
    for (auto bullet: bulletsToDelete) {
        bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());
    }
    bulletsToDelete.clear();

    // Delete enemies
    // Delete duplicates
    enemiesToDelete.erase( unique( enemiesToDelete.begin(), enemiesToDelete.end() ), enemiesToDelete.end());
    for (auto enemy: enemiesToDelete) {
        enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
        addScore(1);
    }
    enemiesToDelete.clear();

    // Delete enemies bullets
    for (auto bullet: enemiesBulletsToDelete) {
        enemiesBullets.erase(std::remove(enemiesBullets.begin(), enemiesBullets.end(), bullet), enemiesBullets.end());
    }
    enemiesBulletsToDelete.clear();

    if (player->hp <= 0) {
        gameOver();
        if (keys["EnterMenu"]) {
            keys["EnterMenu"] = false;
            state = GameState::RestartLevel;
        }
        if (keys["ReturnMenu"]) {
            keys["ReturnMenu"] = false;
            state = GameState::GoBackMenu;
        }
    }

    wave->update();
}

void Level::render(sf::RenderWindow &window) {
    player->render(window);

    for (auto enemy : enemies) {
        enemy->render(window);
    }

    for (auto bullet : bullets) {
        bullet->render(window);
    }

    for (auto bullet : enemiesBullets) {
        bullet->render(window);
    }

    window.draw(scoreText);
    window.draw(hpText);
    window.draw(gameOverText);
}

void Level::addScore(int n) {
    score += n;
    scoreText.setString("Score : " + std::to_string(score));
}

void Level::reduceHp(int n) {
    player->getDamage(n);
    hpText.setString("HP : " + std::to_string(player->hp));
}

void Level::gameOver() {
    gameOverText.setFillColor(sf::Color::White);
}
