#pragma once
#include <winrt/Windows.UI.Notifications.h>
class MediumNumberTile : public winrt::Windows::UI::Notifications::TileNotification
{
public:
	MediumNumberTile(int i);
};

