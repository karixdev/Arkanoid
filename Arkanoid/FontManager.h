#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

class FontManager
{
public:
	static const sf::Font& getFont(std::string filename);
private:
	static std::unordered_map<std::string, sf::Font> fonts;
};
