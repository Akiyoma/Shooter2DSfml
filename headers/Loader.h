#ifndef SHOOTER2DSFML_LOADER_H
#define SHOOTER2DSFML_LOADER_H

#include <string>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

class Loader{
    public:
    Loader();

    sf::Texture defaultEnemyTexture;
    sf::Texture twoTimePatrolEnemyTexture;
    sf::Texture bulletTexture;
    sf::Texture playerTexture;

    sf::Font font;


    private:
        void Loader::loadDefaultEnemyTexture(std::string fileName);
        void Loader::loadTwoTimePatrolEnemyTexture(std::string fileName);
        void Loader::loadBulletTexture(std::string fileName);
        void Loader::loadPlayerTexture(std::string fileName);
        void Loader::loadFont(std::string fileName);

    public:
        void Loader::loadGame();

    virtual ~Loader();
};
#endif //SHOOTER2DSFML_LOADER_H
