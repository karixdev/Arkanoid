#include "MainMenuScene.h"
#include <iostream>

MainMenuScene::MainMenuScene(
    SceneManager& sceneManager,
    sf::RenderWindow& window,
    GameManager& gameManager
) : 
    Scene(window),

    sceneManager(sceneManager),
    gameManager(gameManager),

    playBtn(Button(sf::Vector2f(300, 500), sf::Vector2f(200, 50), "Play")),
    exitBtn(Button(sf::Vector2f(300, 575), sf::Vector2f(200, 50), "Exit")),

    title(Label(65, "Arkanoid"))
{
    title.setPosition(sf::Vector2f(300, 100));

    playBtn.setCallback(std::bind(&MainMenuScene::startGame, this));
    exitBtn.setCallback(std::bind(&MainMenuScene::exit, this));
}
void MainMenuScene::draw(sf::RenderWindow& window)
{
    title.draw(window);
    playBtn.draw(window);
    exitBtn.draw(window);
}

void MainMenuScene::update(float dt)
{
    playBtn.update(window);
    exitBtn.update(window);
}

void MainMenuScene::handleEvent(sf::Event& event)
{
    playBtn.handleEvent(event);
    exitBtn.handleEvent(event);
}

void MainMenuScene::start()
{
}

void MainMenuScene::startGame()
{
    gameManager.setActiveLevel("game");
    sceneManager.switchScene("game");
}

void MainMenuScene::exit()
{
    window.close();
}