#pragma once
#include <string>
#include <vector>

class BrickConfigLoader
{
public:
	BrickConfigLoader();

	std::vector<std::vector<int>> load(std::string filename) const;
};

