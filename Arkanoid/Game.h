#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "MainMenuScene.h"
#include "LevelScene.h"
#include "GameManager.h"
#include "EndGameScene.h"
#include "LevelEditorScene.h"
#include "BrickConfigManager.h"
#include <vector>
#include <string>

class Game
{
public:
	Game(std::vector<std::string> levelsFilenames);

	void init();
	void start();

private:
	sf::RenderWindow window;

	SceneManager sceneManager;
	GameManager gameManager;
	BrickConfigManager brickConfigManager;

	std::vector<std::string> levelsFilenames;

	const sf::Color BACKGROUND_COLOR = sf::Color(54, 19, 135);
	const std::string TITLE = "Arkanoid";
};

