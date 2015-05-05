#ifndef PAUSE_STATE_HPP
#define PAUSE_STATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"

namespace kg {
    class PauseState : public State {
        public:
            PauseState(GameDataRef data);

            void start();

            void handleInput();
            void update(float dt);
            void render(float dt);

        private:
            GameDataRef _data;

            sf::Font _font;
            sf::Text _text;

            void init();
            void mainLoop();
    };
}

#endif // PAUSE_STATE_HPP
