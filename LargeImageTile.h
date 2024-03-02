#pragma once
#include <winrt/Windows.UI.Notifications.h>
class LargeImageTile : public winrt::Windows::UI::Notifications::TileNotification
{
public:
	LargeImageTile(std::wstring fileName);
};
