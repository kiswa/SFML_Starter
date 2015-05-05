#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "state_machine.hpp"
#include "asset_manager.hpp"

namespace kg {
    struct GameData {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
        public:
            Game(int width, int height, std::string title);

        private:
            GameDataRef _data = std::make_shared<GameData>();
    };
}

#endif // GAME_HPP
