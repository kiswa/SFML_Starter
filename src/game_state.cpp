#include <sstream>
#include "game_state.hpp"
#include "pause_state.hpp"

namespace kg {
    GameState::GameState(GameDataRef data)
        : _data(data) { }

    void GameState::start() {
        init();
        mainLoop();
    }

    void GameState::init() {
        _data->assets.loadFont("FiraMono", "assets/FiraMono-Regular.otf");
        _data->assets.loadTexture("alien", "assets/test.png");

        _text.setFont(_data->assets.getFont("FiraMono"));
        _text.setString("This is the Game state! Esc to Pause");
        _text.setCharacterSize(24);
        _text.setColor(sf::Color::Black);
        _text.setPosition(4, _data->window.getSize().y - 30);

        _stats.setFont(_data->assets.getFont("FiraMono"));
        _stats.setCharacterSize(12);
        _stats.setColor(sf::Color::Black);
        _stats.setPosition(4, 4);

        _sprite.setTexture(_data->assets.getTexture("alien"));
        _sprite.setPosition(30, 30);
        _sprite.scale(0.5, 0.5);
    }

    void GameState::resume() {
        mainLoop();
    }

    void GameState::mainLoop() {
        float newTime, frameTime, interpolation;

        float currentTime = _clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        _upsClock.restart();
        _fpsClock.restart();

        while (_data->window.isOpen()) {
            newTime = _clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt) {
                handleInput();
                update(dt);

                accumulator -= dt;
            }

            interpolation = accumulator / dt;
            render(interpolation);
        }
    }

    void GameState::handleInput() {
        sf::Event evt;
        while (_data->window.pollEvent(evt)) {
            if (sf::Event::Closed == evt.type) {
                _data->window.close();
            }

            if (sf::Event::KeyPressed == evt.type) {
                if (sf::Keyboard::Escape == evt.key.code) {
                    _data->machine.startState(StateRef(new PauseState(_data)), false);
                }
            }
        }
    }

    void GameState::update(float dt) {
        float x = 0;
        float y = 0;

        //****************************
        // This is just to display UPS
        _updates++;
        float time = _upsClock.getElapsedTime().asSeconds();
        if (time >= 1.0f) {
            _ups = _updates;

            _upsClock.restart();
            _updates = 0;
        }
        //****************************

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
        if (!_data->window.isOpen()) return;

        //****************************
        // This is just to display FPS
        _frames++;
        float time = _fpsClock.getElapsedTime().asSeconds();
        if (time >= 1.0f) {
            _fps = _frames;

            _fpsClock.restart();
            _frames = 0;
        }
        //****************************
        std::stringstream ss;
        ss << "UPS: " << _ups << " FPS: " << _fps << " (approx.)";
        _stats.setString(ss.str());

        _data->window.clear(sf::Color::Red);
        _data->window.draw(_sprite);
        _data->window.draw(_text);
        _data->window.draw(_stats); // Show UPS: # FPS: #
        _data->window.display();
    }
}
