#include "game.hpp"
#include "game_state.hpp"

namespace kg {
    Game::Game(int width, int height, std::string title) {
        _window->create(sf::VideoMode(width, height), title);

        _machine->startState(StateRef(new GameState(_window, _machine)));
    }
}
