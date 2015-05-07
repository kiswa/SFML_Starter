#include "pause_state.hpp"

namespace kg {
    PauseState::PauseState(GameDataRef data)
        : _data(data) { }

    void PauseState::init() {
        _data->assets.loadFont("FiraMono", "assets/FiraMono-Regular.otf");

        _text.setFont(_data->assets.getFont("FiraMono"));
        _text.setString("This is the Pause state! Esc to return to Game.");
        _text.setCharacterSize(24);
        _text.setColor(sf::Color::Red);
        _text.setPosition(4, _data->window.getSize().y - 30);
    }

    void PauseState::handleInput() {
        sf::Event evt;
        while (_data->window.pollEvent(evt)) {
            if (sf::Event::Closed == evt.type) {
                _data->window.close();
            }

            if (sf::Event::KeyPressed == evt.type) {
                if (sf::Keyboard::Escape == evt.key.code) {
                    _data->machine.removeState();
                }
            }
        }
    }

    void PauseState::render(float dt) {
        _data->window.clear(sf::Color::Black);
        _data->window.draw(_text);
        _data->window.display();
    }
}
