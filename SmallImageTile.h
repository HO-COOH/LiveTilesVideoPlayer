#pragma once
#include <winrt/Windows.UI.Notifications.h>
class SmallImageTile : public winrt::Windows::UI::Notifications::TileNotification
{
public:
	SmallImageTile(std::wstring fileName);
};

