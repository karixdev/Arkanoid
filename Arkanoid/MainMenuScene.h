#pragma once
#include "Scene.h"
#include "Button.h"
#include "SceneManager.h"
#include "Label.h"
#include "GameManager.h"

class MainMenuScene : public Scene
{
public:
	MainMenuScene(
		SceneManager& sceneManager, 
		sf::RenderWindow& window,
		GameManager& gameManager
	);

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;
	void start() override;

private:
	SceneManager& sceneManager;

	sf::Font font;

	Label title;

	Button lvlBtn1;
	Button lvlBtn2;

	Button playBtn;
	Button exitBtn;

	GameManager& gameManager;

	void startLevel(std::string levelName);
	void exit();
};

