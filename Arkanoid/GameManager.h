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
	int getPoints() const;

	void setActiveLevel(std::string levelName);
	std::string getActiveLevel() const;

	void reset(bool resetLvlName);

	Ball& getBall();
	Paddle& getPaddle();

private:
	int points = 0;

	GamePanel panel;

	std::string activeLevelName;

	Paddle paddle;
	Ball ball;
};