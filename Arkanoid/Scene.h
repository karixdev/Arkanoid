#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:
	Scene(sf::RenderWindow& window);

	virtual void draw() = 0;
	virtual void update(float dt) = 0;
	virtual void handleEvent(sf::Event& event) = 0;
	virtual void start() = 0;

protected:
	sf::RenderWindow& window;
};

