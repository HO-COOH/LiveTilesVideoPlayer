#pragma once
#include "TileUpdaterWrapper.h"
#include "TileImageGenerator.h"
#include "Config.h"
class TileVideoPlayer
{
	std::array<TileUpdaterWrapper, Config::row * Config::col> updaters;

	TileImageGenerator generator{ 
		.row = Config::row, 
		.column = Config::col, 
		.tileResolution = static_cast<int>(Config::blockResolution)
	};
public:
	TileVideoPlayer();
	winrt::Windows::Foundation::IAsyncAction MakeTile();
	winrt::fire_and_forget Update();
};

