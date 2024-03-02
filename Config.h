#pragma once

namespace Config
{
	enum class BlockResolution : int
	{
		Small = 71,
		Medium = 150,
		Large = 310
	};
	//constexpr inline int row = 4;
	//constexpr inline int col = 4;
	//constexpr inline BlockResolution blockResolution = BlockResolution::Medium;
	constexpr inline int tileUpdateIntervalSeconds = 3;

	int row();
	int col();
	BlockResolution blockResolution();
	
}

