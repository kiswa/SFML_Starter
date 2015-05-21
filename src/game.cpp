#include "game.hpp"
#include "game_state.hpp"

namespace kg {
    Game::Game(int width, int height, std::string title) {
        _data->window.create(sf::VideoMode(width, height), title,
                sf::Style::Close | sf::Style::Titlebar);
        _data->machine.addState(StateRef(new GameState(_data)));

        run();
    }

    void Game::run() {
        float newTime, frameTime, interpolation;

        float currentTime = _clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (_data->window.isOpen()) {
            _data->machine.processStateChanges();

            newTime = _clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt) {
                calculateUpdatesPerSecond();

                _data->machine.getActiveState()->handleInput();
                _data->machine.getActiveState()->update(dt);

                accumulator -= dt;
            }

            calculateFramesPerSecond();

            interpolation = accumulator / dt;
            _data->machine.getActiveState()->render(interpolation);
        }
    }

#ifdef DEBUG
    void Game::calculateUpdatesPerSecond() {
        _updates++;
        float time = _upsClock.getElapsedTime().asSeconds();
        if (time >= 1.0f) {
            _data->UPS = _updates;

            _upsClock.restart();
            _updates = 0;
        }
    }
#endif

#ifdef DEBUG
    void Game::calculateFramesPerSecond() {
        _frames++;
        float time = _fpsClock.getElapsedTime().asSeconds();
        if (time >= 1.0f) {
            _data->FPS = _frames;

            _fpsClock.restart();
            _frames = 0;
        }
    }
#endif
}
