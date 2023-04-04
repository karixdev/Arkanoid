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

    title(Label(65, "Arkanoid")),

    lvlBtn1(Button(sf::Vector2f(300, 300), sf::Vector2f(200, 50), "Level 1")),
    lvlBtn2(Button(sf::Vector2f(300, 365), sf::Vector2f(200, 50), "Level 2"))
{
    title.setPosition(sf::Vector2f(300, 100));

    lvlBtn1.setCallback(std::bind(&MainMenuScene::startLevel, this, "lvl-1"));
    lvlBtn2.setCallback(std::bind(&MainMenuScene::startLevel, this, "lvl-2"));

    playBtn.setCallback(std::bind(&MainMenuScene::startGame, this));
    exitBtn.setCallback(std::bind(&MainMenuScene::exit, this));
}
void MainMenuScene::draw(sf::RenderWindow& window)
{
    lvlBtn1.draw(window);
    lvlBtn2.draw(window);

    title.draw(window);
    //playBtn.draw(window);
    exitBtn.draw(window);
}

void MainMenuScene::update(float dt)
{
    lvlBtn1.update(window);
    lvlBtn2.update(window);

    playBtn.update(window);
    exitBtn.update(window);
}

void MainMenuScene::handleEvent(sf::Event& event)
{
    lvlBtn1.handleEvent(event);
    lvlBtn2.handleEvent(event);

    playBtn.handleEvent(event);
    exitBtn.handleEvent(event);
}

void MainMenuScene::start()
{
}

void MainMenuScene::exit()
{
    window.close();
}

void MainMenuScene::startLevel(std::string levelName)
{
    gameManager.setActiveLevel(levelName);
    sceneManager.switchScene(levelName);
}
