#pragma once
#include "Scene.h"
#include "Paddle.h"

class GameScene : public Scene
{
public:
	GameScene(sf::RenderWindow& window);

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;

private:
	Paddle paddle;
};

