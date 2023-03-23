#pragma once
#include "Scene.h"
#include "Paddle.h"
#include "Level.h"

class GameScene : public Scene
{
public:
	GameScene(sf::RenderWindow& window, const std::string& levelFilename);

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;
private:
	Level level;
};

