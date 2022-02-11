#include "../headers/Loader.h"

Loader::Loader(){}

void Loader::loadGame() {
    loadDefaultEnemyTexture("../GalaxiaSpritePack/Enemy/idle_bomber_red.png");
    loadTwoTimePatrolEnemyTexture("../GalaxiaSpritePack/Enemy/idle_drone_orange.png");
    loadBulletTexture("../GalaxiaSpritePack/Effects/LaserBlue.png");
    loadPlayerTexture("../GalaxiaSpritePack/Enemy/idle_bomber_green.png");
    loadFont("../arialbi.ttf");
}

void Loader::loadDefaultEnemyTexture(std::string fileName){
    if (!defaultEnemyTexture.loadFromFile(fileName)) {
        std::cout << "Failed to load defaultEnemyTexture for enemy." << "\n";
    }
    defaultEnemyTexture.setSmooth(false);
}

void Loader::loadTwoTimePatrolEnemyTexture(std::string fileName) {
    if (!twoTimePatrolEnemyTexture.loadFromFile(fileName)) {
        std::cout << "Failed to load defaultEnemyTexture for enemy." << "\n";
    }
    twoTimePatrolEnemyTexture.setSmooth(false);
}

void Loader::loadBulletTexture(std::string fileName) {
    if (!bulletTexture.loadFromFile(fileName)) {
        std::cout << "Failed to load defaultEnemyTexture for enemy." << "\n";
    }
    bulletTexture.setSmooth(false);
}

void Loader::loadPlayerTexture(std::string fileName) {
    if (!playerTexture.loadFromFile(fileName)) {
        std::cout << "Failed to load defaultEnemyTexture for enemy." << "\n";
    }
    playerTexture.setSmooth(false);
}

void Loader::loadFont(std::string fileName) {
    font.loadFromFile(fileName);
}

Loader::~Loader() {

}
