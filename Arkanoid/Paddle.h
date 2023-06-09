#pragma once
#include <SFML/Graphics.hpp>
#include "WindowConfig.h"

class Paddle
{
public:
	Paddle();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	sf::RectangleShape getShape() const;

	sf::Vector2f getPosition() const;
	sf::FloatRect getGlobalBounds() const;
	sf::Vector2f getSize() const;

	void reset();

private:
	sf::RectangleShape shape;

	bool canMoveLeft();
	bool canMoveRight();

	const float SPEED = .5f;

	const float WIDTH = 100.f;
	const float HEIGHT = 10.f;

	const sf::Color COLOR = sf::Color::Green;

	const float OUTLINE_THICKNESS = 2.f;
	const sf::Color OUTLINE_COLOR = sf::Color::Black;

	const float WINDOW_BOUNDARY_MARGIN = 10.f;

	const float Y_POISITION = 750;

	const sf::Vector2f INIT_POSITION = sf::Vector2f(
		WindowConfig::WINDOW_WIDTH / 2.f - WIDTH / 2.f, 
		Y_POISITION - HEIGHT / 2.f
	);
};

