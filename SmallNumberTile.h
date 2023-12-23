#pragma once
#include <winrt/Windows.UI.Notifications.h>
class SmallNumberTile : public winrt::Windows::UI::Notifications::TileNotification
{
public:
	SmallNumberTile(int i);
};

