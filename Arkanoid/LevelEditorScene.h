#pragma once
#include "Scene.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "BrickPlaceholder.h"

class LevelEditorScene :
    public Scene
{
public:
	LevelEditorScene(sf::RenderWindow& window);

	void draw(sf::RenderWindow& window) override;
	void update(float dt) override;
	void handleEvent(sf::Event& event) override;
	void start() override;
private:
	sf::RectangleShape line;

	Button backBtn;
	Button playBtn;

	const float BRICK_WIDTH = 52.72f;
	const float BRICK_HEIGHT = 52.72f;
	const float BRICK_MARGIN = 0.f;
	const float WINDOW_MARGIN = 10.f;

	std::vector<BrickPlaceholder> placeholders;
};

