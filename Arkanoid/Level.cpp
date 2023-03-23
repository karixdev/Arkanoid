#include "Level.h"

Level::Level(std::string filename) : 
    filename(filename), paddle(Paddle())
{
}

void Level::init()
{
    BrickConfigLoader loader;
	std::vector<std::vector<int>> config = loader.load(filename);

    for (std::size_t i = 0; i < config.size(); ++i)
    {
        for (std::size_t j = 0; j < config[i].size(); ++j)
        {
            int lives = config[i][j];

            if (lives == 0) continue;

            float posX = j * (BRICK_MARGIN + BRICK_WIDTH) + WINDOW_MARGIN;
            float posY = i * (BRICK_MARGIN + BRICK_HEIGHT) + WINDOW_MARGIN;

            Brick brick(sf::Vector2f(posX, posY), sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT), lives);

            bricks.push_back(brick);
        }
    }
}

void Level::draw(sf::RenderWindow& window)
{
	for (Brick& brick : bricks)
	{
		brick.draw(window);
	}

    paddle.draw(window);
}

void Level::update(float dt)
{
    paddle.update(dt);
}
