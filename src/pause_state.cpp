#include "pause_state.hpp"

namespace kg {
    PauseState::PauseState(WindowRef window, StateMachineRef machine)
        : _window(window), _machine(machine) { }

    void PauseState::start() {
        init();
        mainLoop();
    }

    void PauseState::init() {
        _font.loadFromFile("assets/FiraMono-Regular.otf");

        _text.setFont(_font);
        _text.setString("This is the Pause state! Esc to return to Game.");
        _text.setCharacterSize(24);
        _text.setColor(sf::Color::Red);
        _text.setPosition(4, _window->getSize().y - 30);
    }

    void PauseState::mainLoop() {
        while (_window->isOpen()) {
            handleInput();
            update(0);
            render(0);
        }
    }

    void PauseState::handleInput() {
        sf::Event evt;
        while (_window->pollEvent(evt)) {
            if (sf::Event::Closed == evt.type) {
                _window->close();
            }

            if (sf::Event::KeyPressed == evt.type) {
                if (sf::Keyboard::Escape == evt.key.code) {
                    _machine->exitState();
                }
            }
        }
    }

    void PauseState::update(float dt) {
    }

    void PauseState::render(float dt) {
        if (!_window->isOpen()) return;

        _window->clear(sf::Color::Black);
        _window->draw(_text);
        _window->display();
    }
}
