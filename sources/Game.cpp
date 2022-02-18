#include "../headers/Game.h"

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Shooter 2D SFML");
    window->setVerticalSyncEnabled(true);

    sf::Image icon;
    icon.loadFromFile("../GalaxiaSpritePack/Enemy/idle_bomber_green.png");
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

}

Game::Game() {

    loader = new Loader();
    loader->loadGame();

    initWindow();

    mainMenu = new MainMenu(*window, *loader);
    level = new Level(*window, *loader);
}

Game::~Game() {
    delete window;
}

void Game::run() {
    while (window->isOpen()) {
        // Update delta time
        sf::Time elapsed = clock.restart();
        if (elapsed.asSeconds() > 0.1f)
            elapsed = sf::seconds(0.1f);
        updateTime += elapsed;

        update();

        while (updateTime >= fixedPhysic) {
            if (state == GameState::Menu || state == GameState::Commands)
                mainMenu->update(*window, keys, state);
            if (state == GameState::PlayLevel)
                level->update(*window, fixedPhysic, keys, state);
            updateTime -= fixedPhysic;
        }

        render();
    }
}

void Game::restartLevel(GameState gameState) {
    delete level;
    level = new Level(*window, *loader);
    state = gameState;
}


void Game::updatePollEvents() {
    sf::Event event;

    while (window->pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::X){
                keys["ChangeWeapon"] = true;
            }
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z){
                keys["UpMenu"] = true;
            }
            if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S){
                keys["DownMenu"] = true;
            }
            if (event.key.code == sf::Keyboard::Enter){
                keys["EnterMenu"] = true;
            }
            if (event.key.code == sf::Keyboard::Escape){
                keys["ReturnMenu"] = true;
            }
            if (event.key.code == sf::Keyboard::R){
                delete level;
                level = new Level(*window, *loader);
            }
        }
    }
}

void Game::updateInput() {
    keys["Left"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    keys["Right"] = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    keys["Up"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    keys["Down"] = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    keys["Shoot"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void Game::update() {
    updatePollEvents();
    updateInput();

    if (state == GameState::RestartLevel)
        restartLevel(GameState::PlayLevel);
    if (state == GameState::GoBackMenu)
        restartLevel(GameState::Menu);
}

void Game::render() {
    window->clear();

    if (state == GameState::Menu || state == GameState::Commands)
        mainMenu->render(*window, state);
    if (state == GameState::PlayLevel)
        level->render(*window);

    window->display();
}
