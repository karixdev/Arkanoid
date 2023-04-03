#pragma once
#include <vector>
#include "Brick.h"
#include "BrickConfigLoader.h"
#include "Paddle.h"
#include "Ball.h"
#include "GameManager.h"
#include "SceneManager.h"

class Level
{
public:
	Level(
		std::string filename,
		GameManager& gameManager,
		SceneManager& sceneManager
	);

	void init();

	void draw(sf::RenderWindow& window);
	void update(float dt);

	void reset();

private:
	std::string filename;

	GamePanel panel;

	const float BRICK_WIDTH = 58.f;
	const float BRICK_HEIGHT = 58.f;
	const float BRICK_MARGIN = 0.f;
	const float WINDOW_MARGIN = 10.f;

	SceneManager& sceneManager;
	GameManager& gameManager;

	std::vector<Brick> bricks;

	const float LOSE_LINE_HEIGHT = 760.f;
	bool checkForLose(Ball& ball);
};

