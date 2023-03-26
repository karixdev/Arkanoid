#include "EndGameScene.h"
#include <functional>

EndGameScene::EndGameScene(sf::RenderWindow& window, SceneManager& sceneManager, GameManager& gameManager) :
	Scene(window),
	sceneManager(sceneManager),
	playAgainBtn(Button(sf::Vector2f(300, 500), sf::Vector2f(200, 50), "Play")),
	mainMenuBtn(Button(sf::Vector2f(300, 575), sf::Vector2f(200, 50), "Exit"))
{
	playAgainBtn.setCallback(std::bind(&EndGameScene::playAgain, this));
	mainMenuBtn.setCallback(std::bind(&EndGameScene::goToMainMenu, this));
}

void EndGameScene::draw(sf::RenderWindow& window)
{
	playAgainBtn.draw(window);
	mainMenuBtn.draw(window);
}

void EndGameScene::update(float dt)
{
}

void EndGameScene::handleEvent(sf::Event& event)
{
}

void EndGameScene::playAgain()
{
}

void EndGameScene::goToMainMenu()
{
	sceneManager.switchScene("main-menu");
}

