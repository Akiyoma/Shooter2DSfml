#ifndef SHOOTER2DSFML_MAINMENU_H
#define SHOOTER2DSFML_MAINMENU_H


#include <SFML/Graphics.hpp>
#include "Loader.h"
#include "GameState.h"

class MainMenu {
private:
    sf::Text titleText;
    sf::Text playText;
    sf::Text quitText;

    int currentPos = 0;

public:
    MainMenu(sf::RenderWindow& window, Loader& loader);

    virtual ~MainMenu();

    void update(sf::RenderWindow& window, std::map<std::string, bool>& keys, GameState& state);
    void render(sf::RenderWindow& window);
};


#endif //SHOOTER2DSFML_MAINMENU_H
