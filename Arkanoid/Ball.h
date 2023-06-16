#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Brick.h"
#include "WindowConfig.h"
#include <random>

class Ball
{
public:
	Ball();

	void draw(sf::RenderWindow& window);
	void update(float dt);

	void handleCollision(const Paddle& paddle);
	bool handleCollision(Brick& brick);

	sf::FloatRect getGlobalBounds() const;

	float getRadius() const;
	sf::Vector2f getPosition() const;

	void reset();

private:
	void horizontalWallCollision();
	void verticalWallCollision();

	void beforeStartMovement(float dt);
	void afterStartMovement(float dt);

	bool canMoveLeft() const;
	bool canMoveRight() const;

private:
	sf::CircleShape shape;

	const sf::Vector2f INIT_VELOCITY = { .4f, -.4f };
	sf::Vector2f velocity = INIT_VELOCITY;

	const float RADIUS = 10.f;
	const sf::Color COLOR = sf::Color::Red;

	const float OUTLINE_THICKNESS = -2.f;
	const sf::Color OUTLINE_COLOR = sf::Color::Black;

	bool hasStarted = false;
	const float BEFORE_START_SPEED = .5f;

	const sf::Vector2f INIT_POSITION = sf::Vector2f(
		WindowConfig::WINDOW_WIDTH / 2.f - RADIUS,
		720.f
	);

	const float WINDOW_BOUNDARY_MARGIN = 10.f;

	const float LEFT_SIDE_BOUNDARY = 50.f;
	const float RIGHT_SIDE_BOUNDARY = 530.f;

	const int MAX_ANGLE = 60.f;
	const int MIN_ANGLE = 20.f;
	const int ANGLE_OFFSET = 40.f;

	sf::Vector2f calculateRandomReflectionVector() const;

	std::shared_ptr<std::random_device> rd;
	std::shared_ptr<std::mt19937> gen;

	const float SPEED_MULTIPLICATION_FACTOR = 1.3f;
};
