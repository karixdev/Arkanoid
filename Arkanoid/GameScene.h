#pragma once
#include "Scene.h"
#include "Paddle.h"
#include "Level.h"
#include "GameManager.h"
#include "SceneManager.h"

class GameScene : public Scene
{
public:
	GameScene(
		sf::RenderWindow& window, 
		const std::string& levelFilename, 
		GameManager& gameManager,
		SceneManager& sceneManger
	);

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override; 
	void start() override;

private:
	Level level;
};

