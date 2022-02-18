#include "../headers/GameOverMenu.h"

GameOverMenu::GameOverMenu(sf::RenderWindow &window, Loader &loader) {
    titleText.setFont(loader.font);
    titleText.setString("Game Over");
    titleText.setFillColor(sf::Color::White);
    titleText.setCharacterSize(64);
    titleText.setStyle(sf::Text::Bold);
    sf::FloatRect titleRect = titleText.getLocalBounds();
    titleText.setPosition(window.getSize().x / 2 - titleRect.width / 2, 200 - titleRect.height / 2);

    retryText.setFont(loader.font);
    retryText.setString("Retry");
    retryText.setFillColor(sf::Color::Yellow);
    retryText.setCharacterSize(40);
    sf::FloatRect playRect = retryText.getLocalBounds();
    retryText.setPosition(window.getSize().x / 2 - playRect.width / 2, 400 - playRect.height / 2);

    menuText.setFont(loader.font);
    menuText.setString("Menu");
    menuText.setFillColor(sf::Color::White);
    menuText.setCharacterSize(40);
    sf::FloatRect quitRect = menuText.getLocalBounds();
    menuText.setPosition(window.getSize().x / 2 - quitRect.width / 2, 500 - quitRect.height / 2);

    enterText.setFont(loader.font);
    enterText.setString("Enter : Confirm");
    enterText.setFillColor(sf::Color::White);
    enterText.setCharacterSize(30);
    sf::FloatRect enterRect = enterText.getLocalBounds();
    enterText.setPosition(window.getSize().x - enterRect.width-10, window.getSize().y - 40);
}

GameOverMenu::~GameOverMenu() {

}

void GameOverMenu::update(sf::RenderWindow &window, std::map<std::string, bool> &keys, GameState &state) {
    if (keys["UpMenu"] && currentPos == 1) {
        keys["UpMenu"] = false;
        currentPos = 0;
        retryText.setFillColor(sf::Color::Yellow);
        menuText.setFillColor(sf::Color::White);
    }
    if (keys["DownMenu"] && currentPos == 0) {
        keys["DownMenu"] = false;
        currentPos = 1;
        retryText.setFillColor(sf::Color::White);
        menuText.setFillColor(sf::Color::Yellow);
    }
    if (keys["EnterMenu"]) {
        switch (currentPos) {
            case 0:
                keys["EnterMenu"] = false;
                state = GameState::RestartLevel;
                break;
            case 1:
                keys["EnterMenu"] = false;
                state = GameState::GoBackMenu;
                break;
        }
    }
}

void GameOverMenu::render(sf::RenderWindow &window) {
    window.draw(titleText);
    window.draw(retryText);
    window.draw(menuText);
    window.draw(enterText);
}
