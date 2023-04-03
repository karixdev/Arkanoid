#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "BrickConfigLoader.h"
#include <iostream>
#include "Level.h"
#include "GamePanel.h"
#include "GameManager.h"
#include "EndGameScene.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "Arkanoid");

    SceneManager sceneManager(window);
    GameManager gameManager;

    std::unique_ptr<GameScene> lvl1 = std::make_unique<GameScene>(window, "Levels/Level1.txt", gameManager, sceneManager);
    //std::unique_ptr<GameScene> lvl2 = std::make_unique<GameScene>(window, "Levels/Level2.txt", gameManager, sceneManager);
    //std::unique_ptr<GameScene> lvl3 = std::make_unique<GameScene>(window, "Levels/Level3.txt", gameManager, sceneManager);

    sceneManager.addScene("game", std::make_unique<GameScene>(
        window, "Levels/Level2.txt", gameManager, sceneManager));

    sceneManager.addScene("main-menu", std::make_unique<MainMenuScene>(
        sceneManager, window, gameManager));

    sceneManager.addScene("lose", std::make_unique<EndGameScene>(
        window, sceneManager, gameManager, "You lose!", sf::Color::Red));

    sceneManager.switchScene("main-menu");

    BrickConfigLoader configLoader;

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time dtTimer = clock.restart();
        float dt = dtTimer.asMicroseconds() / 1000.f;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            sceneManager.handleEvent(event);
        }

        window.clear(sf::Color(54, 19, 135));

        sceneManager.update(dt);
        sceneManager.draw();

        window.display();
    }
}