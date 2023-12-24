#include "pch.h"
#include "TileVideoPlayer.h"
#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.UI.StartScreen.h>
#include "SmallNumberTile.h"
#include "SmallImageTile.h"
#include "MediumImageTile.h"
#include "MediumNumberTile.h"
#include "CapturingVideoEffect.g.h"

TileVideoPlayer::TileVideoPlayer()
{
	generator.ClearCache();
}

winrt::Windows::Foundation::IAsyncAction TileVideoPlayer::MakeTile()
{
	for (int i = 0; i < std::size(updaters); ++i)
	{
		winrt::Windows::UI::StartScreen::SecondaryTile tile
		{
			winrt::to_hstring(i),
			L"UWPTile",
			L"arg",
			winrt::Windows::Foundation::Uri{L"ms-appx:///Assets/StoreLogo.png"},
			winrt::Windows::UI::StartScreen::TileSize::Default
		};
		co_await tile.RequestCreateAsync();
		updaters[i] = winrt::Windows::UI::Notifications::TileUpdateManager::CreateTileUpdaterForSecondaryTile(
			tile.TileId()
		);
		
		updaters[i].Update(MediumNumberTile{ i });

	}
}

winrt::fire_and_forget TileVideoPlayer::Update()
{
	co_await generator.Generate(winrt::UWPTiles::CapturingVideoEffect::Snap());

	static int index = 0;
	for (int i = 0; i < Config::row; ++i)
	{
		for (int j = 0; j < Config::col; ++j)
		{
			auto& updater = updaters[i * Config::col + j];
			updater.Clear();
			switch (Config::blockResolution)
			{
			case Config::BlockResolution::Small:
				updater.Update(SmallImageTile{ std::format(L"ms-appdata:///local/{}_{}_{}.png", i, j, index++) });
				break;
			default:
				updater.Update(MediumImageTile{ std::format(L"ms-appdata:///local/{}_{}_{}.png", i, j, index++) });
				break;
			}

		}
	}
}
