#pragma once
class GridLayoutConfig
{
public:
	static const float BRICK_WIDTH;
	static const float BRICK_HEIGHT;
	static const float BRICK_MARGIN;
	static const float WINDOW_MARGIN;

	static const int ROW_NUM = 6;
	static const int COLUMN_NUM = 11;
};

const float GridLayoutConfig::BRICK_WIDTH = 52.72f;
const float GridLayoutConfig::BRICK_HEIGHT = 52.72f;
const float GridLayoutConfig::BRICK_MARGIN = 0.f;
const float GridLayoutConfig::WINDOW_MARGIN = 10.f;
