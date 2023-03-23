#pragma once
#include "Scene.h"
#include "Button.h"
#include "SceneManager.h"
#include "Label.h"

class MainMenuScene : public Scene
{
public:
	MainMenuScene(SceneManager& sceneManager, sf::RenderWindow& window);

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;

private:
	SceneManager& sceneManager;

	sf::Font font;

	Label title;

	Button playBtn;
	Button exitBtn;

	void startGame();
	void exit();
};

