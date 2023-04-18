#pragma once
#include <SFML/Graphics.hpp>

class BrickPlaceholder
{
public:
	BrickPlaceholder(
		const sf::Vector2f& position,
		const sf::Vector2f& size
	);

	void handleEvent(sf::Event& event);
	void draw(sf::RenderWindow& window);

	bool isFilled();

private:
	sf::RectangleShape shape;

	bool isButtonPressed(sf::Event& event, sf::Mouse::Button button);

	const float OUTLINE_THICKNESS = -1.f;
	const sf::Color OUTLINE_COLOR = sf::Color::Black;
};

