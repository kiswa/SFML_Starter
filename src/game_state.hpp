#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "state_machine.hpp"

namespace kg {
    class GameState : public State {
        public:
            GameState(WindowRef window, StateMachineRef machine);

            void start();
            // No pause() method here because this is a very simple
            // example of a game state.
            void resume();

            void handleInput();
            void update(float dt);
            void render(float dt);

        private:
            WindowRef _window;
            StateMachineRef _machine;

            sf::Texture _texture;
            sf::Sprite _sprite;

            sf::Font _font;
            sf::Text _text;

            void init();
            void mainLoop();
    };
}

#endif // GAME_STATE_HPP
