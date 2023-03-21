#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow& window) : window(window)
{
}

SceneManager::~SceneManager()
{
	scenes.clear();
}

void SceneManager::update(float dt)
{
	if (currentScene)
	{
		currentScene->update(dt);
	}
}

void SceneManager::draw()
{
	if (currentScene)
	{
		currentScene->draw(window);
	}
}

void SceneManager::handleEvent(sf::Event& event)
{
	if (currentScene)
	{
		currentScene->handleEvent(event);
	}
}

void SceneManager::addScene(std::string name, std::unique_ptr<Scene> scene)
{
	scenes[name] = std::move(scene);
}

void SceneManager::switchScene(std::string name)
{
	auto it = scenes.find(name);

	if (it != scenes.end())
	{
		currentScene = it->second.get();
	}
}
