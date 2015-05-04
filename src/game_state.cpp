#include <sstream>
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

        _stats.setFont(_font);
        _stats.setCharacterSize(12);
        _stats.setColor(sf::Color::Black);
        _stats.setPosition(4, 4);

        _texture.loadFromFile("assets/test.png");
        _texture.setSmooth(true);

        _sprite.setTexture(_texture);
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

        while (_window->isOpen()) {
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

            // Don't make render call if window is closed.
            if (_window->isOpen()) {
                interpolation = accumulator / dt;
                render(interpolation);
            }
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
        //****************************
        // This is just to display FPS
        _frames++;
        float time = _fpsClock.getElapsedTime().asSeconds();
        if (time >= 1.0f) {
            _fps = _frames;

            _fpsClock.restart();
            _frames = 0;
        }
        std::stringstream ss;
        ss << "UPS: " << _ups << " FPS: " << _fps << " (approx.)";
        _stats.setString(ss.str());
        //****************************

        _window->clear(sf::Color::Red);
        _window->draw(_sprite);
        _window->draw(_text);
        _window->draw(_stats); // Show UPS: # FPS: #
        _window->display();
    }
}
