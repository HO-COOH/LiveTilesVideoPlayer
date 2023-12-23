#include "pch.h"
#include "TileUpdaterWrapper.h"

TileUpdaterWrapper::TileUpdaterWrapper() : TileUpdater{nullptr} {}

TileUpdaterWrapper::TileUpdaterWrapper(winrt::Windows::UI::Notifications::TileUpdater rhs) : TileUpdater{ rhs } {}