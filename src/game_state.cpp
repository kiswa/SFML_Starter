#include "game_state.hpp"
#include "pause_state.hpp"

namespace kg {
    GameState::GameState(WindowRef window, StateMachineRef machine)
        : _window(window), _machine(machine) { }

    void GameState::start() {
        init();
        mainLoop();
    }

    void GameState::init() {
        _font.loadFromFile("assets/FiraMono-Regular.otf");

        _text.setFont(_font);
        _text.setString("This is the Game state! Esc to Pause");
        _text.setCharacterSize(24);
        _text.setColor(sf::Color::Black);
        _text.setPosition(4, _window->getSize().y - 30);

        _texture.loadFromFile("assets/test.png");
        _texture.setSmooth(true);

        _sprite.setTexture(_texture);
        _sprite.scale(0.5, 0.5);
    }

    void GameState::resume() {
        mainLoop();
    }

    void GameState::mainLoop() {
        while (_window->isOpen()) {
            handleInput();
            update(0);
            render(0);
        }
    }

    void GameState::handleInput() {
        sf::Event evt;
        while (_window->pollEvent(evt)) {
            if (sf::Event::Closed == evt.type) {
                _window->close();
            }
            if (sf::Event::KeyPressed == evt.type) {
                if (sf::Keyboard::Escape == evt.key.code) {
                    StateRef pauseState(new PauseState(_window, _machine));
                    _machine->startState(std::move(pauseState), false);
                }
            }
        }
    }

    void GameState::update(float dt) {
        float x = 0;
        float y = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            --x;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            ++x;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            --y;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            ++y;
        }

        _sprite.move(x, y);
    }

    void GameState::render(float dt) {
        _window->clear(sf::Color::Red);
        _window->draw(_sprite);
        _window->draw(_text);
        _window->display();
    }
}
