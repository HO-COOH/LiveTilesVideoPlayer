#pragma once
#include <winrt/Windows.UI.Notifications.h>
class LargeNumberTile : public winrt::Windows::UI::Notifications::TileNotification
{
public:
	explicit LargeNumberTile(int i);
	explicit LargeNumberTile(std::wstring_view i);
};

