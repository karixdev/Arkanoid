#include "Game.h"
#include "WindowConfig.h"

Game::Game(std::vector<std::string> levelsFilenames) :
    window(sf::VideoMode(
        WindowConfig::WINDOW_WIDTH, 
        WindowConfig::WINDOW_HEIGHT
    ), TITLE),
	sceneManager(SceneManager(window)),
	levelsFilenames(levelsFilenames)
{
}

void Game::init()
{
    sceneManager.addScene("main-menu", std::make_unique<MainMenuScene>(
        sceneManager,
        window,
        gameManager,
        levelsFilenames.size()
    ));

    sceneManager.addScene("lose", std::make_unique<EndGameScene>(
        window,
        sceneManager,
        gameManager,
        "You lose!",
        sf::Color::Red
    ));

    sceneManager.addScene("win", std::make_unique<EndGameScene>(
        window,
        sceneManager,
        gameManager,
        "You win!",
        sf::Color::Green
    ));

    sceneManager.addScene("editor", std::make_unique<LevelEditorScene>(
        window,
        sceneManager,
        brickConfigManager
    ));

    sceneManager.addScene("custom-level", std::make_unique<LevelScene>(
        window,
        gameManager,
        sceneManager,
        brickConfigManager
    ));

    for (int i = 0; i < levelsFilenames.size(); ++i)
    {
        std::string name = "lvl-" + std::to_string(i + 1);
        std::string filename = levelsFilenames.at(i);

        sceneManager.addScene(name, std::make_unique<LevelScene>(
            window,
            gameManager,
            sceneManager,
            brickConfigManager,
            filename
        ));
    }

    sceneManager.switchScene("main-menu");
}

void Game::start()
{
	sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time dtTimer = clock.restart();
        float dt = dtTimer.asMicroseconds() / 1000.f;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            sceneManager.handleEvent(event);
        }

        window.clear(BACKGROUND_COLOR);

        sceneManager.update(dt);
        sceneManager.draw();

        window.display();
    }
}
