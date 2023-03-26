#define _USE_MATH_DEFINES

#include "Ball.h"
#include "WindowConfig.h"
#include <math.h>

Ball::Ball()
{
	shape.setPosition(300, 400);

	shape.setRadius(RADIUS);
	shape.setFillColor(COLOR);

	shape.setOutlineThickness(-2.f);
	shape.setOutlineColor(sf::Color::Black);
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
	if (shape.getPosition().x + shape.getRadius() <= 10.f ||
		shape.getPosition().x + shape.getRadius() >= WindowConfig::WINDOW_WIDTH - 10.f
	)
	{
		velocity.x *= -1;
	}
}

void Ball::verticalWallCollision()
{
	if (shape.getPosition().y + shape.getRadius() <= 90.f + 10.f ||
		shape.getPosition().y + shape.getRadius() >= WindowConfig::WINDOW_HEIGHT
	)
	{
		velocity.y *= -1;
	}
}

void Ball::handleCollision(const Paddle& paddle)
{
	sf::FloatRect overlap;

	if (!shape.getGlobalBounds().intersects(paddle.getGlobalBounds(), overlap)) return;

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

bool Ball::handleCollision(Brick& brick)
{
	sf::FloatRect ballBounds = shape.getGlobalBounds();
	sf::FloatRect brickBounds = brick.getGlobalBounds();

	if (!ballBounds.intersects(brickBounds) || brick.getIsDestroyed()) return false;

	sf::Vector2f brickPos = brick.getPosition();
	sf::Vector2f brickSize = brick.getSize();
	sf::Vector2f ballPos = shape.getPosition();

	float ballRadius = shape.getRadius();

	// Find the side of the brick that the ball collided with
	float overlapLeft = ballPos.x + ballRadius - brickPos.x;
	float overlapRight = brickPos.x + brickSize.x - (ballPos.x - ballRadius);
	float overlapTop = ballPos.y + ballRadius - brickPos.y;
	float overlapBottom = brickPos.y + brickSize.y - (ballPos.y - ballRadius);

	bool ballFromLeft = abs(overlapLeft) < abs(overlapRight);
	bool ballFromTop = abs(overlapTop) < abs(overlapBottom);

	float minOverlapX = ballFromLeft ? overlapLeft : overlapRight;
	float minOverlapY = ballFromTop ? overlapTop : overlapBottom;

	// Update ball velocity based on the side of the collision
	if (abs(minOverlapX) < abs(minOverlapY))
	{
		velocity.x = ballFromLeft ? -abs(velocity.x) : abs(velocity.x);
	}
	else
	{
		velocity.y = ballFromTop ? -abs(velocity.y) : abs(velocity.y);
	}

	return true;
}

sf::FloatRect Ball::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}
