#include "../headers/Wave.h"

Wave::Wave(Loader& loader, std::vector<Enemy*>& enemies, std::vector<Bullet*>& bullets) : loader(loader), enemies(enemies), bullets(bullets) {

}

Wave::~Wave() {

}

void Wave::update() {
    if (endWave()) {
        int n = 2 + (rand() % 7);
        spawnWave(n);
    }
}


bool Wave::endWave() {
    return enemies.empty();
}

void Wave::spawnWave(int nEnemy) {
    for (int i = 0; i < nEnemy; ++i) {
        float x = 20 + (rand() % 985);
        float y = 20 + (rand() % 221);

        int chooseEnemy = rand() % 3;
        Enemy* enemy;

        sf::Vector2f dest1;
        sf::Vector2f dest2;

        switch (chooseEnemy) {
            case 0:
                enemy = new BasicEnemy(&loader.defaultEnemyTexture, &loader.redBulletTexture, {x, y});
                break;
            case 1:
                dest1 = {x, y};
                dest2 = {20.f + (rand() % 985), 20.f + (rand() % 221)};
                enemy = new TwoTimePatrolEnemy(&loader.twoTimePatrolEnemyTexture, &loader.redBulletTexture, {x, y}, dest1, dest2);
                break;
            case 2:
                enemy = new CircleEnemy(&loader.circleEnemyTexture, &loader.redBulletTexture, {x, y});
                break;
        }
        enemy->sprite.setPosition(x, -10);
        enemies.push_back(enemy);
    }
}