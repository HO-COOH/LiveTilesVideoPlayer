#pragma once

#include "VideoPage.g.h"
#include "TileVideoPlayer.h"

namespace winrt::UWPTiles::implementation
{
    struct VideoPage : VideoPageT<VideoPage>
    {
        VideoPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        winrt::Windows::Foundation::IAsyncAction Button_Click_1(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void Player_CurrentStateChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    private:
        TileVideoPlayer m_tilePlayer;
        winrt::fire_and_forget startPlayingTiles();

    };
}

namespace winrt::UWPTiles::factory_implementation
{
    struct VideoPage : VideoPageT<VideoPage, implementation::VideoPage>
    {
    };
}
