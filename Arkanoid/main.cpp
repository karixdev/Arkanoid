#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> levelsFilenames = {
        "Levels/level1.txt",
        "Levels/level2.txt",
        "Levels/level3.txt"
    };

    Game game(levelsFilenames);

    game.init();
    game.start();
}