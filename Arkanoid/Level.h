#pragma once
#include <vector>
#include "Brick.h"
#include "BrickConfigLoader.h"
#include "Paddle.h"
#include "Ball.h"

class Level
{
public:
	Level(std::string filename);

	void init();

	void draw(sf::RenderWindow& window);
	void update(float dt);

private:
	std::string filename;

	const float BRICK_WIDTH = 58.f;
	//const float BRICK_WIDTH = 52.6f;
	const float BRICK_HEIGHT = 58.f;
	const float BRICK_MARGIN = 0.f;
	//const float BRICK_MARGIN = 6.f;
	const float WINDOW_MARGIN = 10.f;

	std::vector<Brick> bricks;
	Paddle paddle;
	Ball ball;
};

