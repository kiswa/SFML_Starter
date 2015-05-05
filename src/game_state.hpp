#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"

namespace kg {
    class GameState : public State {
        public:
            GameState(GameDataRef data);

            void start();
            // No pause() method here because this is a very simple
            // example of a game state.
            void resume();

            void handleInput();
            void update(float dt);
            void render(float dt);

        private:
            // Updates run at 30 per second.
            const float dt = 1.0f / 30.0f;

            GameDataRef _data;

            sf::Sprite _sprite;
            sf::Text _text;
            sf::Text _stats;

            sf::Clock _clock;
            sf::Clock _upsClock;
            sf::Clock _fpsClock;

            int _updates, _ups;
            int _frames, _fps;

            void init();
            void mainLoop();
    };
}

#endif // GAME_STATE_HPP
