#include "game.hpp"
#include "game_state.hpp"

namespace kg {
    Game::Game(int width, int height, std::string title) {
        _data->window.create(sf::VideoMode(width, height), title);

        _data->machine.startState(StateRef(new GameState(_data)));
    }
}
