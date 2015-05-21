#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "state_machine.hpp"
#include "asset_manager.hpp"

#define DEBUG

namespace kg {
    struct GameData {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
#ifdef DEBUG
        int FPS, UPS;
#endif
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
        public:
            Game(int width, int height, std::string title);

        private:
            // Updates run at 30 per second.
            const float dt = 1.0f / 30.0f;
            sf::Clock _clock;
#ifdef DEBUG
            sf::Clock _upsClock;
            sf::Clock _fpsClock;
            int _updates;
            int _frames;

            void calculateUpdatesPerSecond();
            void calculateFramesPerSecond();
#endif
            GameDataRef _data = std::make_shared<GameData>();

            void run();
    };
}

#endif // GAME_HPP
