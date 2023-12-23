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
		.tileResolution = Config::blockResolution 
	};
public:
	winrt::Windows::Foundation::IAsyncAction MakeTile();
	winrt::fire_and_forget Update();
};

