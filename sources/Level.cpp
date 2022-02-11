#include "../headers/Level.h"

Level::Level(sf::RenderWindow& window, Loader& loader) {
    player = new Player(window.getSize().x, window.getSize().y, &loader.playerTexture);
    enemies.push_back(new Enemy(&loader.defaultEnemyTexture));
    enemies.push_back(new Enemy(&loader.defaultEnemyTexture));
    enemies.push_back(new TwoTimePatrolEnemy(&loader.twoTimePatrolEnemyTexture));

    enemies[0]->sprite.setPosition(500,700);
    enemies[1]->sprite.setPosition(400,400);
    enemies[2]->sprite.setPosition(300,500);

    bullets.reserve(10);
    ennemiesBullets.reserve(100);

    scoreText.setFont(loader.font);
    scoreText.setString("Score : 0");
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(0, 0);

    hpText.setFont(loader.font);
    hpText.setString("HP : " + std::to_string(player->hp));
    hpText.setFillColor(sf::Color::White);
    hpText.setPosition(window.getSize().x - 100, 0);
}

Level::~Level() {
    delete player;

    for (auto bullet : bullets) {
        delete bullet;
    }

    for (auto bullet : ennemiesBullets) {
        delete bullet;
    }

    for (auto enemy : enemies) {
        delete enemy;
    }
}

void Level::update(sf::RenderWindow& window, sf::Time deltaTime, std::map<std::string, bool>& keys) {
    player->update(deltaTime, window, keys, bullets);
    for (int i = 0; i < enemies.size(); ++i) {
        enemies[i]->update(deltaTime, window , ennemiesBullets);
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
                    enemiesToDelete.push_back(enemies[j]);
                    bulletsToDelete.push_back(bullets[i]);
                }
            }
        }
    }

    for (int i = 0; i < ennemiesBullets.size(); ++i) {
        ennemiesBullets[i]->update(deltaTime, window);
        if (ennemiesBullets[i]->isOutsideWindow(window, ennemiesBullets)) {
            enemiesBulletsToDelete.push_back(ennemiesBullets[i]);
        }
        else if (ennemiesBullets[i]->sprite.getGlobalBounds().intersects(player->sprite.getGlobalBounds())) {
            enemiesBulletsToDelete.push_back(ennemiesBullets[i]);
            if (!player->isInvulnerable)
                reduceHp(1);
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
        addScore(1);
    }
    enemiesToDelete.clear();

    // Delete enemies bullets
    for (auto bullet: enemiesBulletsToDelete) {
        ennemiesBullets.erase(std::remove(ennemiesBullets.begin(), ennemiesBullets.end(), bullet), ennemiesBullets.end());
    }
    enemiesBulletsToDelete.clear();
}

void Level::render(sf::RenderWindow &window) {
    player->render(window);

    for (auto bullet : bullets) {
        bullet->render(window);
    }

    for (auto bullet : ennemiesBullets) {
        bullet->render(window);
    }

    for (auto enemy : enemies) {
        enemy->render(window);
    }

    window.draw(scoreText);
    window.draw(hpText);
}

void Level::addScore(int n) {
    score += n;
    scoreText.setString("Score : " + std::to_string(score));
}

void Level::reduceHp(int n) {
    player->getDamage();
    hpText.setString("HP : " + std::to_string(player->hp));
}
