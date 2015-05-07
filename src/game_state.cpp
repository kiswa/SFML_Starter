#include <sstream>
#include "game_state.hpp"
#include "pause_state.hpp"

namespace kg {
    GameState::GameState(GameDataRef data)
        : _data(data) { }

    void GameState::init() {
        _data->assets.loadFont("FiraMono", "assets/FiraMono-Regular.otf");
        _data->assets.loadTexture("alien", "assets/test.png");

        _text.setFont(_data->assets.getFont("FiraMono"));
        _text.setString("This is the Game state! Esc to Pause");
        _text.setCharacterSize(24);
        _text.setColor(sf::Color::Black);
        _text.setPosition(4, _data->window.getSize().y - 30);
#ifdef DEBUG
        _stats.setFont(_data->assets.getFont("FiraMono"));
        _stats.setCharacterSize(12);
        _stats.setColor(sf::Color::Black);
        _stats.setPosition(4, 4);
#endif
        _sprite.setTexture(_data->assets.getTexture("alien"));
        _sprite.setPosition(30, 30);
        _sprite.scale(0.5, 0.5);
    }

    void GameState::handleInput() {
        sf::Event evt;
        while (_data->window.pollEvent(evt)) {
            if (sf::Event::Closed == evt.type) {
                _data->window.close();
            }

            if (sf::Event::KeyPressed == evt.type) {
                if (sf::Keyboard::Escape == evt.key.code) {
                    _data->machine.addState(StateRef(new PauseState(_data)),
                            false);
                }
            }
        }
    }

    void GameState::update(float dt) {
        float x = 0;
        float y = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            x -= 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            x += 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            y -= 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            y += 2;
        }

        _sprite.move(x, y);
    }

    void GameState::render(float dt) {
#ifdef DEBUG
        std::stringstream ss;
        ss << "UPS: " << _data->UPS << " FPS: " << _data->FPS << " (approx.)";
        _stats.setString(ss.str());
#endif
        _data->window.clear(sf::Color::Red);
        _data->window.draw(_sprite);
        _data->window.draw(_text);
#ifdef DEBUG
        _data->window.draw(_stats); // Show "UPS: # FPS: #"
#endif
        _data->window.display();
    }
}
