#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Label
{
public:
	Label(float size, std::string content);
	Label(float size, std::string content, sf::Color color);

	void setPosition(sf::Vector2f position);
	void centerRelativily(sf::RectangleShape shape);

	void draw(sf::RenderWindow& window);

private:
	sf::Text text;

	const float OUTLINE_THICKNESS = 2.f;
	const sf::Color OUTLINE_COLOR = sf::Color::Black;

	const sf::Color DEFAULT_COLOR = sf::Color::White;
};

