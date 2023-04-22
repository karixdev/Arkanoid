#include "BrickConfigLoader.h"
#include <fstream>

std::vector<std::vector<int>> BrickConfigLoader::load(std::string filename) const
{
	std::vector<std::vector<int>> bricks;

	std::ifstream file(filename);

	if (!file.is_open())
	{
		throw std::runtime_error("Failed to load file " + filename);
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::vector<int> row;

		for (char c : line)
		{
			switch (c)
			{
			case '0':
				row.push_back(0);
				break;
			case '1':
				row.push_back(1);
				break;
			case '2':
				row.push_back(2);
				break;
			default:
				throw std::runtime_error("Invalid character");
			}
		}

		bricks.push_back(row);
	}

	file.close();

	return bricks;
}