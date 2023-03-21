#include "GameScene.h"

GameScene::GameScene(sf::RenderWindow& window) : Scene(window), paddle(Paddle(300, 750))
{
}

void GameScene::draw(sf::RenderWindow& window)
{
	paddle.draw(window);
}

void GameScene::update(float dt)
{
	paddle.update(dt);
}

void GameScene::handleEvent(sf::Event& event)
{

}
