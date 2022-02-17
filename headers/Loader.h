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
    sf::Texture circleEnemyTexture;
    sf::Texture aimEnemyTexture;
    sf::Texture bulletTexture;
    sf::Texture redBulletTexture;
    sf::Texture playerTexture;

    sf::Font font;


    private:
        void loadDefaultEnemyTexture(std::string fileName);
        void loadTwoTimePatrolEnemyTexture(std::string fileName);
        void loadCircleEnemyTexture(std::string fileName);
        void loadAimEnemyTexture(std::string fileName);
        void loadBlueBulletTexture(std::string fileName);
        void loadRedBulletTexture(std::string fileName);
        void loadPlayerTexture(std::string fileName);
        void loadFont(std::string fileName);

    public:
        void loadGame();

    virtual ~Loader();
};
#endif //SHOOTER2DSFML_LOADER_H
