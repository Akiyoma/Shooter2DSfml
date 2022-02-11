#include "../headers/Game.h"

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Shooter 2D SFML");
    window->setVerticalSyncEnabled(true);
}

Game::Game() {

    loader = new Loader();
    loader->loadGame();

    initWindow();

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
            level->update(*window, fixedPhysic, keys);
            updateTime -= fixedPhysic;
        }

        render();
    }
}

void Game::updatePollEvents() {
    sf::Event event;

    while (window->pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void Game::updateInput() {
    keys["Left"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    keys["Right"] = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    keys["Up"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    keys["Down"] = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    keys["Shoot"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    keys["ChangeWeapon"] = sf::Keyboard::isKeyPressed(sf::Keyboard::X);
}

void Game::update() {
    updatePollEvents();
    updateInput();
}

void Game::render() {
    window->clear();

    level->render(*window);

    window->display();
}
