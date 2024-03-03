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
