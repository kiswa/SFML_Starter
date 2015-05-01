#ifndef PAUSE_STATE_HPP
#define PAUSE_STATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "state_machine.hpp"

namespace kg {
    class PauseState : public State {
        public:
            PauseState(WindowRef window, StateMachineRef machine);

            void start();

            void handleInput();
            void update(float dt);
            void render(float dt);

        private:
            WindowRef _window;
            StateMachineRef _machine;

            sf::Font _font;
            sf::Text _text;

            void init();
            void mainLoop();
    };
}

#endif // PAUSE_STATE_HPP
