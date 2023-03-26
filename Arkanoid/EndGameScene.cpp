#include "EndGameScene.h"
#include <functional>

EndGameScene::EndGameScene(
	sf::RenderWindow& window, 
	SceneManager& sceneManager, 
	GameManager& gameManager,
	std::string text,
	sf::Color color
) :
	Scene(window),
	sceneManager(sceneManager),
	playAgainBtn(Button(sf::Vector2f(300, 500), sf::Vector2f(200, 50), "Play")),
	mainMenuBtn(Button(sf::Vector2f(300, 575), sf::Vector2f(200, 50), "Exit")),
	label(Label(80.f, text, color))
{
	playAgainBtn.setCallback(std::bind(&EndGameScene::playAgain, this));
	mainMenuBtn.setCallback(std::bind(&EndGameScene::goToMainMenu, this));

	label.setPosition(sf::Vector2f(300.f, 400.f));
}

void EndGameScene::draw(sf::RenderWindow& window)
{
	label.draw(window);
	playAgainBtn.draw(window);
	mainMenuBtn.draw(window);
}

void EndGameScene::update(float dt)
{
	playAgainBtn.update(window);
	mainMenuBtn.update(window);
}

void EndGameScene::handleEvent(sf::Event& event)
{
	playAgainBtn.handleEvent(event);
	mainMenuBtn.handleEvent(event);
}

void EndGameScene::playAgain()
{
}

void EndGameScene::goToMainMenu()
{
	sceneManager.switchScene("main-menu");
}

