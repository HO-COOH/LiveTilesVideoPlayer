#pragma once
#include <winrt/Windows.UI.StartScreen.h>
//TileType can be SmallNumberTile, MediumNumberTile, LargeNumberTile
template<typename TileType>
class SecondaryTileWrapper : public TileType,
	public winrt::Windows::UI::StartScreen::SecondaryTile
{
public:
	SecondaryTileWrapper(
		winrt::hstring tileId,
		winrt::hstring displayName,
		winrt::hstring arguments,
		winrt::Windows::Foundation::Uri squareLogo = winrt::Windows::Foundation::Uri{ L"ms-appx:///Assets/StoreLogo.png" },
		winrt::Windows::UI::StartScreen::TileSize desiredSize = winrt::Windows::UI::StartScreen::TileSize::Default
	) : TileType{tileId},
		SecondaryTile{ tileId, displayName, arguments, squareLogo, desiredSize }
	{
		auto visualElements = VisualElements();
		visualElements.Wide310x150Logo(winrt::Windows::Foundation::Uri{ L"ms-appx:///Assets/Wide310x150Logo.scale-200.png" });
		visualElements.Square310x310Logo(winrt::Windows::Foundation::Uri{ L"ms-appx:///Assets/Square150x150Logo.scale-200.png" });
	}
};