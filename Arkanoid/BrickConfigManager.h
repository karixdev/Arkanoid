#pragma once
#include "InMemoryBrickConfig.h"
#include "FileBrickConfig.h"

class BrickConfigManager
{
public:
	InMemoryBrickConfig& getInMemoryConfig();
	FileBrickConfig& getFileConfig();
private:
	InMemoryBrickConfig inMemoryConfig;
	FileBrickConfig fileBrickConfig;
};

