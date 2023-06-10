#define _USE_MATH_DEFINES

#include "Ball.h"
#include <math.h>
#include <iostream>

#define _USE_MATH_DEFINES

Ball::Ball()
{
	shape.setPosition(INIT_POSITION);

	shape.setRadius(RADIUS);
	shape.setFillColor(COLOR);

	shape.setOutlineThickness(OUTLINE_THICKNESS);
	shape.setOutlineColor(OUTLINE_COLOR);

	rd = new std::random_device;
	gen = new std::mt19937((*rd)());
}

Ball::~Ball()
{
	delete gen;
	delete rd;
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Ball::update(float dt)
{
	if (hasStarted)
	{
		afterStartMovement(dt);
	}
	else
	{
		beforeStartMovement(dt);
	}
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

void Ball::beforeStartMovement(float dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && canMoveLeft())
	{
		shape.move(-BEFORE_START_SPEED * dt, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && canMoveRight())
	{
		shape.move(BEFORE_START_SPEED * dt, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		hasStarted = true;
	}
}

void Ball::afterStartMovement(float dt)
{
	horizontalWallCollision();
	verticalWallCollision();

	shape.move(dt * velocity.x, dt * velocity.y);
}

void Ball::handleCollision(const Paddle& paddle)
{
	sf::FloatRect overlap;

	if (!shape.getGlobalBounds().intersects(paddle.getGlobalBounds(), overlap)) return;

	shape.setPosition(getPosition().x, paddle.getPosition().y - RADIUS * 2 - 2);

	sf::Vector2f rndVector = calculateRandomReflectionVector();

	if (getPosition().x <= paddle.getPosition().x + paddle.getGlobalBounds().width / 2.f)
	{
		rndVector = sf::Vector2f(rndVector.x * SPEED_MULTIPLICATION_FACTOR, rndVector.y);
	}
	else
	{
		rndVector = sf::Vector2f(rndVector.x, rndVector.y * SPEED_MULTIPLICATION_FACTOR);
	}

	velocity = rndVector;
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

	float overlapLeft = ballPos.x + ballRadius - brickPos.x;
	float overlapRight = brickPos.x + brickSize.x - (ballPos.x - ballRadius);
	float overlapTop = ballPos.y + ballRadius - brickPos.y;
	float overlapBottom = brickPos.y + brickSize.y - (ballPos.y - ballRadius);

	bool ballFromLeft = abs(overlapLeft) < abs(overlapRight);
	bool ballFromTop = abs(overlapTop) < abs(overlapBottom);

	float minOverlapX = ballFromLeft ? overlapLeft : overlapRight;
	float minOverlapY = ballFromTop ? overlapTop : overlapBottom;

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

bool Ball::canMoveLeft() const
{
	return shape.getPosition().x > LEFT_SIDE_BOUNDARY;
}

bool Ball::canMoveRight() const
{

	return shape.getPosition().x < RIGHT_SIDE_BOUNDARY;
}

sf::Vector2f Ball::calculateRandomReflectionVector() const
{
	std::uniform_int_distribution<int> dist(MIN_ANGLE, MAX_ANGLE);

	int angleDeg = dist(*gen);
	angleDeg -= ANGLE_OFFSET;

	float angleRad = angleDeg * M_PI / 180.f;

	float x1 = INIT_VELOCITY.x;
	float y1 = -INIT_VELOCITY.y;

	float x2 = x1 * std::cos(angleRad) + y1 * std::sin(angleRad);
	float y2 = -x1 * std::sin(angleRad) + y1 * std::cos(angleRad);

	if (velocity.x < 0)
	{
		x2 *= -1.f;
	}

	return sf::Vector2f(x2, -y2);
}

float Ball::getRadius() const
{
	return RADIUS;
}

sf::Vector2f Ball::getPosition() const
{
	return shape.getPosition();
}

void Ball::reset()
{
	shape.setPosition(INIT_POSITION);
	velocity = INIT_VELOCITY;
	hasStarted = false;
}
