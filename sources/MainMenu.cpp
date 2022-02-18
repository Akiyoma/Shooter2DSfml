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

    commandText.setFont(loader.font);
    commandText.setString("Commands");
    commandText.setFillColor(sf::Color::Yellow);
    commandText.setCharacterSize(40);
    sf::FloatRect commandRect = playText.getLocalBounds();
    commandText.setPosition(window.getSize().x / 2 - commandRect.width / 2, 450 - commandRect.height / 2);

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

    movementText.setFont(loader.font);
    movementText.setString("Movement\nMove up : Z or Up\nMove down : S or Down\nMove right : D or Right\nMove left : Q or Left");
    movementText.setFillColor(sf::Color::White);
    movementText.setCharacterSize(40);
    movementText.setPosition(50, window.getSize().y / 2 - 100);

    weaponText.setFont(loader.font);
    weaponText.setString("Weapon\nShoot : Space\nChange weapon : X");
    weaponText.setFillColor(sf::Color::White);
    weaponText.setCharacterSize(40);
    weaponText.setPosition(window.getSize().x / 2 + 50, window.getSize().y / 2 - 100);

    returnText.setFont(loader.font);
    returnText.setString("Enter : Return");
    returnText.setFillColor(sf::Color::White);
    returnText.setCharacterSize(30);
    sf::FloatRect returnRect = enterText.getLocalBounds();
    returnText.setPosition(window.getSize().x - returnRect.width-10, window.getSize().y - 40);
}

MainMenu::~MainMenu() {

}

void MainMenu::update(sf::RenderWindow& window, std::map<std::string, bool>& keys, GameState& state) {
    if (state == GameState::Menu) {
        if (keys["UpMenu"]) {
            keys["UpMenu"] = false;
            --currentPos;
            if (currentPos < 0)
                currentPos = 0;
        }
        if (keys["DownMenu"]) {
            keys["DownMenu"] = false;
            ++currentPos;
            if (currentPos > 2)
                currentPos = 2;
        }
        switch (currentPos) {
            case 0:
                playText.setFillColor(sf::Color::Yellow);
                commandText.setFillColor(sf::Color::White);
                quitText.setFillColor(sf::Color::White);
                break;
            case 1:
                playText.setFillColor(sf::Color::White);
                commandText.setFillColor(sf::Color::Yellow);
                quitText.setFillColor(sf::Color::White);
                break;
            case 2:
                playText.setFillColor(sf::Color::White);
                commandText.setFillColor(sf::Color::White);
                quitText.setFillColor(sf::Color::Yellow);
                break;
        }

        if (keys["EnterMenu"]) {
            switch (currentPos) {
                case 0:
                    keys["EnterMenu"] = false;
                    state = GameState::PlayLevel;
                    break;
                case 1:
                    keys["EnterMenu"] = false;
                    titleText.setString("Commands");
                    state = GameState::Commands;
                    break;
                case 2:
                    keys["EnterMenu"] = false;
                    window.close();
                    break;
            }
        }
    }
    else if (state == GameState::Commands) {
        if (keys["EnterMenu"]) {
            keys["EnterMenu"] = false;
            titleText.setString("Shooter 2D");
            state = GameState::Menu;
        }
    }
}

void MainMenu::render(sf::RenderWindow &window, GameState& state) {
    window.draw(titleText);
    if (state == GameState::Menu) {
        window.draw(playText);
        window.draw(commandText);
        window.draw(quitText);
        window.draw(enterText);
    }
    else if (state == GameState::Commands) {
        window.draw(movementText);
        window.draw(weaponText);
        window.draw(returnText);
    }
}
