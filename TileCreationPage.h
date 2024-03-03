#pragma once

#include "TileCreationPage.g.h"
#include <winrt/Windows.UI.StartScreen.h>
#include "SecondaryTileWrapper.h"

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

        template<typename TileType>
        winrt::Windows::Foundation::IAsyncAction pinTilesAsync(int tileId)
        {
            SecondaryTileWrapper<TileType> tile
            {
                winrt::to_hstring(tileId),
                L"UWPTile",
                L"arg",
                winrt::Windows::Foundation::Uri{L"ms-appx:///Assets/StoreLogo.png"},
                winrt::Windows::UI::StartScreen::TileSize::Default
            };

            auto result = co_await tile.RequestCreateAsync();
            winrt::Windows::Storage::ApplicationData::Current().LocalSettings().Values().Insert(NumTilesLeftSettingsKey, winrt::box_value(m_numTilesLeft));
            if (!result)
            {
                ProgressBar().ShowError(true);
                co_return;
            }
            winrt::Windows::UI::Notifications::TileUpdateManager::CreateTileUpdaterForSecondaryTile(
                tile.TileId()
            ).Update(tile);

            raisePropertyChange(L"NumTilesLeft");
            raisePropertyChange(L"NumTilesPinned");
        }

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
