#ifndef SHOOTER2DSFML_MAINMENU_H
#define SHOOTER2DSFML_MAINMENU_H


#include <SFML/Graphics.hpp>
#include "Loader.h"
#include "GameState.h"

class MainMenu {
private:
    sf::Text titleText;
    sf::Text playText;
    sf::Text commandText;
    sf::Text quitText;
    sf::Text enterText;

    sf::Text movementText;
    sf::Text weaponText;
    sf::Text returnText;

    int currentPos = 0;

public:
    MainMenu(sf::RenderWindow& window, Loader& loader);

    virtual ~MainMenu();

    void update(sf::RenderWindow& window, std::map<std::string, bool>& keys, GameState& state);
    void render(sf::RenderWindow& window, GameState& state);
};


#endif //SHOOTER2DSFML_MAINMENU_H
