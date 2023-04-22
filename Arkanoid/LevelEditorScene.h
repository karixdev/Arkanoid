#pragma once
#include "Scene.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "BrickPlaceholder.h"
#include "BrickConfigManager.h"
#include "SceneManager.h"
#include "InMemoryBrickConfig.h"
#include "GamePanel.h"

class LevelEditorScene :
    public Scene
{
public:
	LevelEditorScene(
		sf::RenderWindow& window,
		SceneManager& sceneManager,
		BrickConfigManager& brickConfigManager
	);

	void draw() override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;
	void start() override;
private:
	sf::RectangleShape line;

	Button backBtn;
	Button playBtn;

	const float BRICK_WIDTH = 52.72f;
	const float BRICK_HEIGHT = 52.72f;
	const float BRICK_MARGIN = 0.f;
	const float WINDOW_MARGIN = 10.f;

	BrickConfigManager& brickConfigManager;
	SceneManager& sceneManager;

	std::vector<BrickPlaceholder> placeholders;

	GamePanel gamePanel;

	void play();
	void exit();
};

