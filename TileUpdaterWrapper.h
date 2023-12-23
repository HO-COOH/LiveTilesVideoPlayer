#pragma once

#include <winrt/Windows.UI.Notifications.h>
class TileUpdaterWrapper : public winrt::Windows::UI::Notifications::TileUpdater
{
public:
    TileUpdaterWrapper();
    TileUpdaterWrapper(winrt::Windows::UI::Notifications::TileUpdater rhs);
};