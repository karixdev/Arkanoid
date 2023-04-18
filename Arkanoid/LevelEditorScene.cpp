#include "LevelEditorScene.h"
#include <functional>

LevelEditorScene::LevelEditorScene(
	sf::RenderWindow& window,
	SceneManager& sceneManager,
	BrickConfigManager& brickConfigManager
) :
	Scene(window),
	playBtn(Button(sf::Vector2f(150, 750), sf::Vector2f(200, 50), "Play")),
	backBtn(Button(sf::Vector2f(450, 750), sf::Vector2f(200, 50), "Exit")),
	brickConfigManager(brickConfigManager),
	sceneManager(sceneManager)
{
	line.setFillColor(sf::Color::Black);
	line.setSize(sf::Vector2f(600, 5.f));
	line.setPosition(sf::Vector2f(0.f, 695.f + 2.5f));

	playBtn.setCallback(std::bind(&LevelEditorScene::play, this));
	backBtn.setCallback(std::bind(&LevelEditorScene::exit, this));
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

void LevelEditorScene::play()
{
	std::vector<std::vector<int>> config;

	int k = 0;
	for (int rowIdx = 0; rowIdx < 6; ++rowIdx)
	{
		std::vector<int> row;
		for (int columnIdx = 0; columnIdx < 11; ++columnIdx)
		{
			BrickPlaceholder placeholder = placeholders.at(k++);

			if (placeholder.isFilled())
			{
				row.push_back(1);
			}
			else
			{
				row.push_back(0);
			}
		}

		config.push_back(row);
	}

	placeholders.clear();
	brickConfigManager.getInMemoryConfig().setBrickConfig(config);

	sceneManager.switchScene("custom-level");
}

void LevelEditorScene::exit()
{
}
