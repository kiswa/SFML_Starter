#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"

namespace kg {
    class GameState : public State {
        public:
            GameState(GameDataRef data);

            void init();

            // No pause() or resume() methods here as this is a
            // very simple example of a game state.

            void handleInput();
            void update(float dt);
            void render(float dt);

        private:
            GameDataRef _data;

            sf::Sprite _sprite;
            sf::Text _text;
            sf::Text _stats;
    };
}

#endif // GAME_STATE_HPP
