#pragma once
#include <vector>
#include "Brick.h"
#include "BrickConfigLoader.h"
#include "Paddle.h"
#include "Ball.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "Scene.h"

class LevelScene : public Scene 
{
public:
	LevelScene(
		sf::RenderWindow& window,
		std::string filename,
		GameManager& gameManager,
		SceneManager& sceneManager
	);

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;
	void start() override;

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

