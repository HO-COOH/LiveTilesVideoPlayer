#pragma once
#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.UI.StartScreen.h>
#include <string_view>
class MediumNumberTile : public winrt::Windows::UI::Notifications::TileNotification
{
public:
	explicit MediumNumberTile(int i);
	explicit MediumNumberTile(std::wstring_view i);
};


class MediumNumberSecondaryTile : 
	public MediumNumberTile, 
	public winrt::Windows::UI::StartScreen::SecondaryTile
{
public:
	MediumNumberSecondaryTile(
		winrt::hstring tileId,
		winrt::hstring displayName,
		winrt::hstring arguments,
		winrt::Windows::Foundation::Uri squareLogo = winrt::Windows::Foundation::Uri{ L"ms-appx:///Assets/StoreLogo.png" },
		winrt::Windows::UI::StartScreen::TileSize desiredSize = winrt::Windows::UI::StartScreen::TileSize::Default
	);
};