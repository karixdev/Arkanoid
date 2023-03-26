#pragma once
#include "Button.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "Scene.h"

class EndGameScene : public Scene
{
public:
	EndGameScene(
		sf::RenderWindow& window, 
		SceneManager& sceneManager, 
		GameManager& gameManager
	);

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;

private:
	Button playAgainBtn;
	Button mainMenuBtn;

	void playAgain();
	void goToMainMenu();

	SceneManager& sceneManager;
};

