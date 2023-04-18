#pragma once
#include <vector>

class InMemoryBrickConfig
{
public:
	std::vector<std::vector<int>> load();
	void setBrickConfig(std::vector<std::vector<int>> config);
private:
	std::vector<std::vector<int>> brickConfig;
};