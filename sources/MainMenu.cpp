#include "../headers/MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window, Loader& loader) {
    titleText.setFont(loader.font);
    titleText.setString("Shooter 2D");
    titleText.setFillColor(sf::Color::White);
    titleText.setCharacterSize(64);
    titleText.setStyle(sf::Text::Bold);
    sf::FloatRect titleRect = titleText.getLocalBounds();
    titleText.setPosition(window.getSize().x / 2 - titleRect.width / 2, 200 - titleRect.height / 2);

    playText.setFont(loader.font);
    playText.setString("Play");
    playText.setFillColor(sf::Color::Yellow);
    playText.setCharacterSize(40);
    sf::FloatRect playRect = playText.getLocalBounds();
    playText.setPosition(window.getSize().x / 2 - playRect.width / 2, 400 - playRect.height / 2);

    quitText.setFont(loader.font);
    quitText.setString("Quit");
    quitText.setFillColor(sf::Color::White);
    quitText.setCharacterSize(40);
    sf::FloatRect quitRect = quitText.getLocalBounds();
    quitText.setPosition(window.getSize().x / 2 - quitRect.width / 2, 500 - quitRect.height / 2);

    enterText.setFont(loader.font);
    enterText.setString("Enter : Confirm");
    enterText.setFillColor(sf::Color::White);
    enterText.setCharacterSize(30);
    sf::FloatRect enterRect = enterText.getLocalBounds();
    enterText.setPosition(window.getSize().x - enterRect.width-10, window.getSize().y - 40);
}

MainMenu::~MainMenu() {

}

void MainMenu::update(sf::RenderWindow& window, std::map<std::string, bool>& keys, GameState& state) {
    if (keys["UpMenu"] && currentPos == 1) {
        keys["UpMenu"] = false;
        currentPos = 0;
        playText.setFillColor(sf::Color::Yellow);
        quitText.setFillColor(sf::Color::White);
    }
    if (keys["DownMenu"] && currentPos == 0) {
        keys["DownMenu"] = false;
        currentPos = 1;
        playText.setFillColor(sf::Color::White);
        quitText.setFillColor(sf::Color::Yellow);
    }
    if (keys["EnterMenu"]) {
        switch (currentPos) {
            case 0:
                keys["EnterMenu"] = false;
                state = GameState::PlayLevel;
                break;
            case 1:
                keys["EnterMenu"] = false;
                window.close();
                break;
        }
    }
}

void MainMenu::render(sf::RenderWindow &window) {
    window.draw(titleText);
    window.draw(playText);
    window.draw(quitText);
    window.draw(enterText);
}
