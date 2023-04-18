#pragma once
#include <SFML/Graphics.hpp>
#include "Brick.h"

class BrickPlaceholder : public Brick
{
public:
	BrickPlaceholder(
		const sf::Vector2f& position,
		const sf::Vector2f& size
	);

	void handleEvent(sf::Event& event);

	bool isFilled();

private:
	bool isButtonPressed(sf::Event& event, sf::Mouse::Button button);

	const float OUTLINE_THICKNESS = -1.f;
	const sf::Color OUTLINE_COLOR = sf::Color::Black;
};

