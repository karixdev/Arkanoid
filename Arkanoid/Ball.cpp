#define _USE_MATH_DEFINES

#include "Ball.h"
#include "WindowConfig.h"
#include <math.h>
#include <iostream>

Ball::Ball()
{
	shape.setPosition(300, 400);

	shape.setRadius(RADIUS);
	shape.setFillColor(COLOR);
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Ball::update(float dt)
{
	horizontalWallCollision();
	verticalWallCollision();

	shape.move(dt * velocity.x, dt * velocity.y);
}

void Ball::horizontalWallCollision()
{
	if (shape.getPosition().x + shape.getRadius() <= 0 ||
		shape.getPosition().x + shape.getRadius() >= WindowConfig::WINDOW_WIDTH
	)
	{
		velocity.x *= -1;
	}
}

void Ball::verticalWallCollision()
{
	if (shape.getPosition().y + shape.getRadius() <= 0 ||
		shape.getPosition().y + shape.getRadius() >= WindowConfig::WINDOW_HEIGHT
	)
	{
		velocity.y *= -1;
	}
}

void Ball::handleCollision(const Paddle& paddle)
{
	sf::FloatRect overlap;
	if (shape.getGlobalBounds().intersects(paddle.getGlobalBounds(), overlap))
	{
		float ballPosition = shape.getPosition().x;
		float paddlePosition = paddle.getPosition().x;
		float paddleWidth = paddle.getGlobalBounds().width;

		float overlapLeft = ballPosition - (paddlePosition - paddleWidth / 2);
		float overlapRight = (paddlePosition + paddleWidth / 2) - ballPosition;

		bool ballFromLeft = overlapLeft < overlapRight;

		if (ballFromLeft)
		{
			velocity.x = -abs(velocity.x);
		}
		else
		{
			velocity.x = abs(velocity.x);
		}

		velocity.y = -abs(velocity.y);
	}
}
