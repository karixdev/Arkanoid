#include "LevelScene.h"
#include <iostream>

LevelScene::LevelScene(
    sf::RenderWindow& window,
    std::string filename, 
    GameManager& gameManager,
    SceneManager& sceneManager,
    BrickConfigManager& brickConfigManager,
    bool isInMemory
) : Scene(window),
    filename(filename),
    gameManager(gameManager),
    sceneManager(sceneManager),
    brickConfigManager(brickConfigManager),
    isInMemory(isInMemory)
{
}

LevelScene::LevelScene(
    sf::RenderWindow& window, 
    GameManager& gameManager, 
    SceneManager& sceneManager, 
    BrickConfigManager& brickConfigManager
) : LevelScene(
        window,
        "",
        gameManager,
        sceneManager,
        brickConfigManager,
        true
    )
{
}

LevelScene::LevelScene(
    sf::RenderWindow& window,
    GameManager& gameManager,
    SceneManager& sceneManager,
    BrickConfigManager& brickConfigManager,
    std::string filename
) : LevelScene(
    window,
    filename,
    gameManager,
    sceneManager,
    brickConfigManager,
    false
)
{
}

void LevelScene::draw(sf::RenderWindow& window)
{
	for (Brick& brick : bricks)
	{
		brick.draw(window);
	}

    gameManager.draw(window);
}

void LevelScene::update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        gameManager.reset();
        sceneManager.switchScene("main-menu");
    }

    Ball& ball = gameManager.getBall();
    Paddle& paddle = gameManager.getPaddle();

    if (checkForLose(ball))
    {
        reset();
        sceneManager.switchScene("lose");
    }

    for (Brick& brick : bricks)
    {
        if (!ball.handleCollision(brick)) continue;

        gameManager.updatePoints(brick.getLives());

        brick.descreaseLives();
    }

    if (checkForWin())
    {
        reset();
        sceneManager.switchScene("win");
    }

    ball.handleCollision(paddle);

    gameManager.update(dt);
}

void LevelScene::handleEvent(sf::Event& event)
{
}

void LevelScene::start()
{
    if (!bricks.empty()) return;

    BrickConfigLoader loader;

    std::vector<std::vector<int>> config;

    if (isInMemory)
    {
        config = brickConfigManager.getInMemoryConfig().load();
    }
    else
    {
        config = brickConfigManager.getFileConfig().load(filename);
    }

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

void LevelScene::reset()
{
    for (Brick& brick : bricks)
    {
        brick.reset();
    }
}

bool LevelScene::checkForLose(Ball& ball)
{
    return ball.getPosition().y + 2.f * ball.getRadius() > LOSE_LINE_HEIGHT;
}

bool LevelScene::checkForWin()
{
    int destroyedBlocksCount = 0;

    for (const Brick& brick : bricks)
    {
        if (brick.getLives() == 0)
        {
            destroyedBlocksCount++;
        }
    }

    return destroyedBlocksCount == bricks.size();
}
