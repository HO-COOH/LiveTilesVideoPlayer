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

        void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        winrt::Windows::Foundation::IAsyncAction Button_Click_1(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void Player_CurrentStateChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);

        winrt::Windows::Foundation::IAsyncAction Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    private:
        TileVideoPlayer m_tilePlayer;
        winrt::fire_and_forget startPlayingTiles(); 

    };
}

namespace winrt::UWPTiles::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
