#pragma once
#include <winrt/Windows.UI.Notifications.h>
class MediumImageTile : public winrt::Windows::UI::Notifications::TileNotification
{
public:
	MediumImageTile(std::wstring fileName);
};

