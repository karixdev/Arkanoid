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
	gameManager(gameManager),

	playAgainBtn(Button(sf::Vector2f(300, 500), sf::Vector2f(200, 50), "Restart")),
	mainMenuBtn(Button(sf::Vector2f(300, 575), sf::Vector2f(200, 50), "Menu")),

	messageLabel(Label(50.f, text, color)),
	scoreLabel(Label(40.f, std::to_string(gameManager.getPoints()), sf::Color::White))
{
	playAgainBtn.setCallback(std::bind(&EndGameScene::playAgain, this));
	mainMenuBtn.setCallback(std::bind(&EndGameScene::goToMainMenu, this));

	messageLabel.setPosition(sf::Vector2f(300.f, 100.f));
	scoreLabel.setPosition(sf::Vector2f(300.f, 200.f));
}

void EndGameScene::draw(sf::RenderWindow& window)
{
	messageLabel.draw(window);
	playAgainBtn.draw(window);
	mainMenuBtn.draw(window);
	scoreLabel.draw(window);
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

void EndGameScene::start()
{
	scoreLabel.setText("Score: " + std::to_string(gameManager.getPoints()));
	scoreLabel.setPosition(sf::Vector2f(300.f, 200.f));
}

void EndGameScene::playAgain()
{
	sceneManager.switchScene(gameManager.getActiveLevel());
	gameManager.reset();
}

void EndGameScene::goToMainMenu()
{
	sceneManager.switchScene("main-menu");
	gameManager.reset();
}