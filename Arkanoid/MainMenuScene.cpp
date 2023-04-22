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
    title(Label(65, "Arkanoid")),
    levelsNumber(levelsNumber),
    lvlEditorBtn(Button(sf::Vector2f(300, 500), sf::Vector2f(200, 65), "Level\nEditor"))
{
    title.setPosition(sf::Vector2f(300, 100));
    exitBtn.setCallback(std::bind(&MainMenuScene::exit, this));
    lvlEditorBtn.setCallback(std::bind(&MainMenuScene::levelEditor, this));
}
void MainMenuScene::draw()
{
    for (Button& lvlBtn : lvlBtns)
    {
        lvlBtn.draw(window);
    }

    title.draw(window);
    exitBtn.draw(window);
    lvlEditorBtn.draw(window);
}

void MainMenuScene::update(float dt)
{
    for (Button& lvlBtn : lvlBtns)
    {
        lvlBtn.update(window);
    }

    exitBtn.update(window);
    lvlEditorBtn.update(window);
}

void MainMenuScene::handleEvent(sf::Event& event)
{
    for (Button& lvlBtn : lvlBtns)
    {
        lvlBtn.handleEvent(event);
    }

    exitBtn.handleEvent(event);
    lvlEditorBtn.handleEvent(event);
}

void MainMenuScene::start()
{
    if (!lvlBtns.empty()) return;

    for (int i = 0; i < levelsNumber; i++)
    {
        int yPos = 300.f + i * 65.f;
        std::string displatName = "Level " + std::to_string(i + 1);
        Button btn(sf::Vector2f(300, yPos), sf::Vector2f(200, 50), displatName);

        std::string lvlName = "lvl-" + std::to_string(i + 1);
        btn.setCallback(std::bind(&MainMenuScene::startLevel, this, lvlName));

        lvlBtns.push_back(btn);
    }
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

void MainMenuScene::levelEditor()
{
    gameManager.setActiveLevel("custom-level");
    sceneManager.switchScene("editor");
}
