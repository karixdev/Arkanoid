#include "GameScene.h"

GameScene::GameScene(sf::RenderWindow& window, const std::string& levelFilename) : Scene(window), level(Level(levelFilename))
{
	level.init();
}

void GameScene::draw(sf::RenderWindow& window)
{
	level.draw(window);
}

void GameScene::update(float dt)
{
	level.update(dt);
}

void GameScene::handleEvent(sf::Event& event)
{

}
