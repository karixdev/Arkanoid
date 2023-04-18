#pragma once
#include <vector>
#include <string>

class FileBrickConfig
{
public:
	std::vector<std::vector<int>> load(std::string filename) const;
};

