#include "FontManager.h"

std::unordered_map<std::string, sf::Font> FontManager::fonts;

const sf::Font& FontManager::getFont(std::string filename)
{
    auto it = fonts.find(filename);

    if (it == fonts.end()) 
    {
        sf::Font font;
        if (!font.loadFromFile(filename)) 
        {
            throw std::runtime_error("Unable to load font " + filename);
        }

        fonts[filename] = font;
    }
    return fonts[filename];

}
