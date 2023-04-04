#include "MainMenuScene.h"
#include <iostream>

MainMenuScene::MainMenuScene(
    SceneManager& sceneManager,
    sf::RenderWindow& window,
    GameManager& gameManager,
    int levelsNumber
) : 
    Scene(window),
    sceneManager(sceneManager),
    gameManager(gameManager),
    exitBtn(Button(sf::Vector2f(300, 725), sf::Vector2f(200, 50), "Exit")),
    title(Label(65, "Arkanoid"))
{
    title.setPosition(sf::Vector2f(300, 100));

    for (int i = 0; i < levelsNumber; i++)
    {
        int yPos = 300.f + i * 65.f;
        std::string displatName = "Level " + std::to_string(i + 1);
        Button btn(sf::Vector2f(300, yPos), sf::Vector2f(200, 50), displatName);

        std::string lvlName = "lvl-" + std::to_string(i + 1);
        btn.setCallback(std::bind(&MainMenuScene::startLevel, this, lvlName));

        lvlBtns.push_back(btn);
    }

    exitBtn.setCallback(std::bind(&MainMenuScene::exit, this));
}
void MainMenuScene::draw(sf::RenderWindow& window)
{
    for (Button& lvlBtn : lvlBtns)
    {
        lvlBtn.draw(window);
    }

    title.draw(window);
    exitBtn.draw(window);
}

void MainMenuScene::update(float dt)
{
    for (Button& lvlBtn : lvlBtns)
    {
        lvlBtn.update(window);
    }

    exitBtn.update(window);
}

void MainMenuScene::handleEvent(sf::Event& event)
{
    for (Button& lvlBtn : lvlBtns)
    {
        lvlBtn.handleEvent(event);
    }

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
