#pragma once
#include <vector>
#include "Brick.h"
#include "Paddle.h"
#include "Ball.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "BrickConfigManager.h"

class LevelScene : public Scene 
{
public:
	LevelScene(
		sf::RenderWindow& window,
		std::string filename,
		GameManager& gameManager,
		SceneManager& sceneManager,
		BrickConfigManager& brickConfigManager,
		bool isInMemory
	);

	LevelScene(
		sf::RenderWindow& window,
		GameManager& gameManager,
		SceneManager& sceneManager,
		BrickConfigManager& brickConfigManager
	);

	LevelScene(
		sf::RenderWindow& window,
		GameManager& gameManager,
		SceneManager& sceneManager,
		BrickConfigManager& brickConfigManager,
		std::string filename
	);

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;
	void start() override;

	void reset();

private:
	std::string filename;

	GamePanel panel;

	const float BRICK_WIDTH = 52.72f;
	const float BRICK_HEIGHT = 52.72f;
	const float BRICK_MARGIN = 0.f;
	const float WINDOW_MARGIN = 10.f;

	bool isInMemory = false;

	SceneManager& sceneManager;
	GameManager& gameManager;

	BrickConfigManager& brickConfigManager;

	std::vector<Brick> bricks;

	const float LOSE_LINE_HEIGHT = 770.f;
	bool checkForLose(Ball& ball);
	bool checkForWin();
};

