#include "pch.h"
#include "TileVideoPlayer.h"
#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.UI.StartScreen.h>
#include "SmallImageTile.h"
#include "MediumImageTile.h"
#include "LargeImageTile.h"
#include "CapturingVideoEffect.g.h"
#include <ranges>

TileVideoPlayer::TileVideoPlayer()
{
	generator.ClearCache();
	std::ranges::transform(updaters, updaters.begin(), [i = 0](auto const&) mutable {
		return winrt::Windows::UI::Notifications::TileUpdateManager::CreateTileUpdaterForSecondaryTile(winrt::to_hstring(i++));
	});
}

winrt::fire_and_forget TileVideoPlayer::Update()
{
	co_await generator.Generate(winrt::UWPTiles::CapturingVideoEffect::Snap());

	static int index = 0;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			auto& updater = updaters[i * col + j];
			updater.Clear();
			auto const imagePath = std::format(L"ms-appdata:///local/{}_{}_{}.png", i, j, index++);
			switch (blockResolution)
			{
			case Config::BlockResolution::Small:
				updater.Update(SmallImageTile{ imagePath });
				break;
			case Config::BlockResolution::Medium:
				updater.Update(MediumImageTile{ imagePath });
				break;
			case Config::BlockResolution::Large:
				updater.Update(LargeImageTile{ imagePath });
				break;
			default:
				updater.Update(MediumImageTile{ imagePath });
				break;
			}

		}
	}
}
