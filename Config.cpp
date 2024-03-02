#include "pch.h"
#include "Config.h"
#include "TileCreationPage.h"
#include <winrt/Windows.Storage.h>

int Config::row()
{
    return sqrt(winrt::unbox_value<int>(winrt::Windows::Storage::ApplicationData::Current().LocalSettings().Values().Lookup(winrt::UWPTiles::implementation::TileCreationPage::TilesSettingsKey)));
}

int Config::col()
{
    return row();
}

Config::BlockResolution Config::blockResolution()
{
	switch (row())
	{
	case 2:
		return BlockResolution::Large;
	case 3:
	case 4:
		return BlockResolution::Medium;
	case 6:
	case 8:
		return BlockResolution::Small;
	default:
		assert(false);
	}
}
