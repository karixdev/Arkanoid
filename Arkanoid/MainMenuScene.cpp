#include "MainMenuScene.h"
#include <iostream>

MainMenuScene::MainMenuScene(SceneManager& sceneManager, sf::RenderWindow& window) : Scene(window), 
    sceneManager(sceneManager)
{
	font.loadFromFile("Fonts/arcade.ttf");

    title.setFont(font);
    title.setCharacterSize(90);
    title.setString("Arkanoid");
    title.setFillColor(sf::Color::White);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(2);
    title.setPosition(300 - title.getLocalBounds().width / 2.f, 100);

    playBtn = new Button(sf::Vector2f(300, 500), sf::Vector2f(200, 50), font, "Play");
    playBtn->setCallback(std::bind(&MainMenuScene::startGame, this));

    exitBtn = new Button(sf::Vector2f(300, 575), sf::Vector2f(200, 50), font, "Exit");
    exitBtn->setCallback(std::bind(&MainMenuScene::exit, this));
}

MainMenuScene::~MainMenuScene()
{
    delete playBtn;
    delete exitBtn;
}

void MainMenuScene::draw(sf::RenderWindow& window)
{
    window.draw(title);
    playBtn->draw(window);
    exitBtn->draw(window);
}

void MainMenuScene::update(float dt)
{
    playBtn->update(window);
    exitBtn->update(window);
}

void MainMenuScene::handleEvent(sf::Event& event)
{
    playBtn->handleEvent(event);
    exitBtn->handleEvent(event);
}

void MainMenuScene::startGame()
{
    sceneManager.switchScene("game");
}

void MainMenuScene::exit()
{
    window.close();
}
