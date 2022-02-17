#include "../headers/Loader.h"

Loader::Loader(){}

void Loader::loadGame() {
    loadDefaultEnemyTexture("../GalaxiaSpritePack/Enemy/idle_bomber_red.png");
    loadTwoTimePatrolEnemyTexture("../GalaxiaSpritePack/Enemy/idle_drone_orange.png");
    loadCircleEnemyTexture("../GalaxiaSpritePack/Enemy/idle_scout_red.png");
    loadAimEnemyTexture("../GalaxiaSpritePack/Enemy/idle_heavy_yellow.png");
    loadBlueBulletTexture("../GalaxiaSpritePack/Effects/LaserBlue.png");
    loadRedBulletTexture("../GalaxiaSpritePack/Effects/LaserRed.png");
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

void Loader::loadCircleEnemyTexture(std::string fileName) {
    circleEnemyTexture.loadFromFile(fileName);
    circleEnemyTexture.setSmooth(false);
}

void Loader::loadAimEnemyTexture(std::string fileName) {
    aimEnemyTexture.loadFromFile(fileName);
    aimEnemyTexture.setSmooth(false);
}

void Loader::loadBlueBulletTexture(std::string fileName) {
    if (!bulletTexture.loadFromFile(fileName)) {
        std::cout << "Failed to load defaultEnemyTexture for enemy." << "\n";
    }
    bulletTexture.setSmooth(false);
}

void Loader::loadRedBulletTexture(std::string fileName) {
    redBulletTexture.loadFromFile(fileName);
    redBulletTexture.setSmooth(false);
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
