#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "state_machine.hpp"

namespace kg {
    class Game {
        public:
            Game(int width, int height, std::string title);

        private:
            StateMachineRef _machine = std::make_shared<StateMachine>();
            WindowRef _window = std::make_shared<sf::RenderWindow>();
    };
}

#endif // GAME_HPP
