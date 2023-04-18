#include "InMemoryBrickConfig.h"

std::vector<std::vector<int>> InMemoryBrickConfig::load()
{
    return brickConfig;
}

void InMemoryBrickConfig::setBrickConfig(std::vector<std::vector<int>> config)
{
    brickConfig = config;
}
