#include "Level.h"

Level::Level(
    std::string filename, 
    GameManager& gameManager,
    SceneManager& sceneManager
) :
    filename(filename), 
    paddle(Paddle()),
    ball(Ball()),
    gameManager(gameManager),
    sceneManager(sceneManager)
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
            float posY = i * (BRICK_MARGIN + BRICK_HEIGHT) + WINDOW_MARGIN + 90.f;

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
    ball.draw(window);

    gameManager.draw(window);
}

void Level::update(float dt)
{
    if (checkForLose())
    {
        sceneManager.switchScene("lose");
    }

    for (Brick& brick : bricks)
    {
        if (!ball.handleCollision(brick)) continue;

        gameManager.updatePoints(brick.getLives());

        brick.descreaseLives();
    }

    // check for paddle ball collisions
    ball.handleCollision(paddle);

    ball.update(dt);
    paddle.update(dt);
}

bool Level::checkForLose()
{
    return ball.getPosition().y + 2.f * ball.getRadius() > LOSE_LINE_HEIGHT;
}
