#pragma once
#include "TileUpdaterWrapper.h"
#include "TileImageGenerator.h"
#include "Config.h"
#include <vector>
class TileVideoPlayer
{
	int const row = Config::row();
	int const col = Config::col();

	std::vector<TileUpdaterWrapper> updaters{ static_cast<size_t>(row * col) };

	TileImageGenerator generator{ 
		.row = row,
		.column = col,
		.tileResolution = static_cast<int>(Config::blockResolution())
	};
public:
	TileVideoPlayer();

	winrt::fire_and_forget Update();
};

