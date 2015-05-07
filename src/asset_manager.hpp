#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <map>

namespace sf {
    class Texture;
    class Font;
}

namespace kg {
    class AssetManager {
    public:
        AssetManager() { }
        ~AssetManager() { }

        void loadTexture(std::string name, std::string fileName);
        sf::Texture& getTexture(std::string name);

        void loadFont(std::string name, std::string fileName);
        sf::Font& getFont(std::string name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}

#endif // ASSET_MANAGER_HPP
