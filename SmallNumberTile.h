#pragma once
#include <winrt/Windows.UI.Notifications.h>
class SmallNumberTile : public winrt::Windows::UI::Notifications::TileNotification
{
public:
	explicit SmallNumberTile(int i);
	explicit SmallNumberTile(std::wstring_view i);
};

