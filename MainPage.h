#pragma once

#include "MainPage.g.h"
#include <winrt/Windows.UI.StartScreen.h>
#include <winrt/Windows.UI.Notifications.h>
#include "TileVideoPlayer.h"

namespace winrt::UWPTiles::implementation
{

    struct MainPage : MainPageT<MainPage>
    {
        MainPage() = default;


        void NavigationView_SelectionChanged(winrt::Windows::UI::Xaml::Controls::NavigationView const& sender, winrt::Windows::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args);
    };
}

namespace winrt::UWPTiles::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
