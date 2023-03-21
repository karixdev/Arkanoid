#pragma once
#include "Scene.h"
#include "Button.h"
#include "SceneManager.h"

class MainMenuScene : public Scene
{
public:
	MainMenuScene(SceneManager& sceneManager, sf::RenderWindow& window);

	virtual ~MainMenuScene();

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;

private:
	SceneManager& sceneManager;

	sf::Font font;
	sf::Text title;

	Button* playBtn = nullptr;
	Button* exitBtn = nullptr;

	void startGame();
	void exit();
};

