#ifndef SHOOTER2DSFML_GAMEOVERMENU_H
#define SHOOTER2DSFML_GAMEOVERMENU_H

#include <SFML/Graphics.hpp>
#include "Loader.h"
#include "GameState.h"

class GameOverMenu {
private:
    sf::Text titleText;
    sf::Text retryText;
    sf::Text menuText;
    sf::Text enterText;

    int currentPos = 0;

public:
    GameOverMenu(sf::RenderWindow& window, Loader& loader);

    virtual ~GameOverMenu();

    void update(sf::RenderWindow& window, std::map<std::string, bool>& keys, GameState& state);
    void render(sf::RenderWindow& window);
};


#endif //SHOOTER2DSFML_GAMEOVERMENU_H
