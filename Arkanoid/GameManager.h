#pragma once
#include <SFML/Graphics.hpp>
#include "GamePanel.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class GameManager
{
public:
	GameManager(std::vector<Brick>& bricks, Ball& ball, Paddle& paddle);

	void draw(sf::RenderWindow& window);
	void update(float dt);

private:
	int points = 0;

	GamePanel panel;

	Ball& ball;
	Paddle& paddle;
	std::vector<Brick>& bricks;
};

