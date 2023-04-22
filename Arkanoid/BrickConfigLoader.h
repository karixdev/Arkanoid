#pragma once
#include <vector>
#include <string>

class BrickConfigLoader
{
public:
	std::vector<std::vector<int>> load(std::string filename) const;
};

