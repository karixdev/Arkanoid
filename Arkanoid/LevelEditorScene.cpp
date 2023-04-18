#include "LevelEditorScene.h"

LevelEditorScene::LevelEditorScene(sf::RenderWindow& window) :
	Scene(window),
	playBtn(Button(sf::Vector2f(150, 750), sf::Vector2f(200, 50), "Play")),
	backBtn(Button(sf::Vector2f(450, 750), sf::Vector2f(200, 50), "Exit"))
{
	line.setFillColor(sf::Color::Black);
	line.setSize(sf::Vector2f(600, 5.f));
	line.setPosition(sf::Vector2f(0.f, 695.f + 2.5f));
}

void LevelEditorScene::draw(sf::RenderWindow& window)
{
	backBtn.draw(window);
	playBtn.draw(window);
	window.draw(line);

	for (BrickPlaceholder& placeholder : placeholders)
	{
		placeholder.draw(window);
	}
}

void LevelEditorScene::update(float dt)
{
	backBtn.update(window);
	playBtn.update(window);
}

void LevelEditorScene::handleEvent(sf::Event& event)
{
	backBtn.handleEvent(event);
	playBtn.handleEvent(event);

	for (BrickPlaceholder& placeholder : placeholders)
	{
		placeholder.handleEvent(event);
	}
}

void LevelEditorScene::start()
{
	for (std::size_t i = 0; i < 6; ++i)
	{
		for (std::size_t j = 0; j < 11; ++j)
		{
			float posX = j * (BRICK_MARGIN + BRICK_WIDTH) + WINDOW_MARGIN;
			float posY = i * (BRICK_MARGIN + BRICK_HEIGHT) + WINDOW_MARGIN + 90.f;

			sf::Vector2f pos(posX, posY);
			sf::Vector2f size(BRICK_WIDTH, BRICK_HEIGHT);

			BrickPlaceholder placeholder(pos, size);

			placeholders.push_back(placeholder);
		}
	}
}
