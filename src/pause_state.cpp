#include "pause_state.hpp"

namespace kg {
    PauseState::PauseState(GameDataRef data)
        : _data(data) { }

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
        _text.setPosition(4, _data->window.getSize().y - 30);
    }

    void PauseState::mainLoop() {
        while (_data->window.isOpen()) {
            handleInput();
            update(0);
            render(0);
        }
    }

    void PauseState::handleInput() {
        sf::Event evt;
        while (_data->window.pollEvent(evt)) {
            if (sf::Event::Closed == evt.type) {
                _data->window.close();
            }

            if (sf::Event::KeyPressed == evt.type) {
                if (sf::Keyboard::Escape == evt.key.code) {
                    _data->machine.exitState();
                }
            }
        }
    }

    void PauseState::update(float dt) {
    }

    void PauseState::render(float dt) {
        if (!_data->window.isOpen()) return;

        _data->window.clear(sf::Color::Black);
        _data->window.draw(_text);
        _data->window.display();
    }
}
