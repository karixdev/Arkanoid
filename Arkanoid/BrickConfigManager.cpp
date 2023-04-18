#include "BrickConfigManager.h"

InMemoryBrickConfig& BrickConfigManager::getInMemoryConfig()
{
	return inMemoryConfig;
}

FileBrickConfig& BrickConfigManager::getFileConfig()
{
	return fileBrickConfig;
}
