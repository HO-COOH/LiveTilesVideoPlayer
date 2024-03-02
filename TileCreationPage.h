#pragma once

#include "TileCreationPage.g.h"

namespace winrt::UWPTiles::implementation
{
    struct TileCreationPage : TileCreationPageT<TileCreationPage>, MvvmHelper::PropertyChangeHelper<TileCreationPage>
    {
        TileCreationPage();
        int NumTilesLeft();
        int NumTilesPinned();
        winrt::Windows::Foundation::IAsyncAction PinTilesButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        bool IsFinished() { return m_numTilesLeft == 0; }
        constexpr static auto TilesSettingsKey = L"NumTiles";
    private:
        int m_numTilesLeft;


        constexpr static auto DefaultNumTiles = 16;
        int m_selectedNumTiles = DefaultNumTiles;

        constexpr static auto NumTilesLeftSettingsKey = L"NumTilesLeft";
        void writeToSettings(int numTiles);
    public:
        void TwoByTwo_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void FourByFour_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void EightByEight_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void SixBySixButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void ThreeByThreeButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::UWPTiles::factory_implementation
{
    struct TileCreationPage : TileCreationPageT<TileCreationPage, implementation::TileCreationPage>
    {
    };
}
