#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>
#include "Scene.h"

class SceneManager
{
public:
	SceneManager(sf::RenderWindow& window);
	~SceneManager();

	void update(float dt);
	void draw();
	void handleEvent(sf::Event& event);

	void addScene(std::string name, std::unique_ptr<Scene> scene);
	void switchScene(std::string name);

private:
	sf::RenderWindow& window;

	Scene* currentScene = nullptr;
	std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
};