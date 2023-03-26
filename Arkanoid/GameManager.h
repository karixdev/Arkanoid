#pragma once
#include <SFML/Graphics.hpp>
#include "GamePanel.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class GameManager
{
public:
	GameManager();

	void draw(sf::RenderWindow& window);
	void update(float dt);

	void updatePoints(int lives);

private:
	int points = 0;

	GamePanel panel;
};