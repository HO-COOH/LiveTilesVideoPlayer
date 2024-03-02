#include "pch.h"
#include "TileCreationPage.h"
#if __has_include("TileCreationPage.g.cpp")
#include "TileCreationPage.g.cpp"
#endif
#include <winrt/Windows.UI.StartScreen.h>
#include <winrt/Windows.Storage.h>
#include "MediumNumberTile.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UWPTiles::implementation
{
	TileCreationPage::TileCreationPage() 
	{
		InitializeComponent();
		auto value = winrt::Windows::Storage::ApplicationData::Current().LocalSettings().Values().TryLookup(TilesSettingsKey);
		bool const isSelected = (value != nullptr);
		
		if (isSelected)
		{
			switch (winrt::unbox_value<int>(value))
			{
			case 2*2:
				TwoByTwoButton().IsChecked(true); 
				winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"TwoByTwo", false);
				break;
			case 3*3: 
				ThreeByThreeButton().IsChecked(true); 
				winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"ThreeByThree", false);
				break;
			case 4 * 4: 
				FourByFourButton().IsChecked(true); 
				winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"FourByFour", false); 
				break;
			case 6 * 6: 
				SixBySixButton().IsChecked(true); 
				winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"SixBySix", false);
				break;
			case 8 * 8: 
				EightByEightButton().IsChecked(true); 
				winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"EightByEight", false);
				break;
			default:
				break;
			}
		
		}
		else
		{
			winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"FourByFour", false);
			FourByFourButton().IsChecked(true);
			ProgressBar().Maximum(4 * 4);
		}

		m_numTilesLeft = winrt::unbox_value_or(winrt::Windows::Storage::ApplicationData::Current().LocalSettings().Values().TryLookup(NumTilesLeftSettingsKey), 4 * 4);
		PinTilesButton().IsEnabled(m_numTilesLeft != 0);
	}
	int TileCreationPage::NumTilesPinned()
	{
		if (auto value = winrt::Windows::Storage::ApplicationData::Current().LocalSettings().Values().TryLookup(TilesSettingsKey);  value)
		{
			return winrt::unbox_value<int>(value) - m_numTilesLeft;
		}
		else
			return 0;
	}

	int TileCreationPage::NumTilesLeft()
	{
		return m_numTilesLeft;
	}
	winrt::Windows::Foundation::IAsyncAction TileCreationPage::PinTilesButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::Storage::ApplicationData::Current().LocalSettings().Values().Insert(TilesSettingsKey, winrt::box_value(m_selectedNumTiles));
		ProgressBar().ShowPaused(false);
		for(int i = 0; m_numTilesLeft--; ++i)
		{
			MediumNumberSecondaryTile tile
			{
				winrt::to_hstring(i),
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
				break;
			}
			winrt::Windows::UI::Notifications::TileUpdateManager::CreateTileUpdaterForSecondaryTile(
				tile.TileId()
			).Update(tile);

			raisePropertyChange(L"NumTilesLeft");
			raisePropertyChange(L"NumTilesPinned");
		}
		if (m_numTilesLeft == 0)
		{
			winrt::Windows::UI::Xaml::Controls::ContentDialog dialog;
			const wchar_t* content{};
			switch (m_selectedNumTiles)
			{
			case 4:
				content = L"Please manually adjust the size of pinned tiles to -> Large";
				break;
			case 36:
			case 64:
				content = L"Please manually adjust the size of pinned tiles to -> Small";
				break;
			default:
				assert(false);
				break;
			}
			if (content)
			{
				dialog.Content(winrt::box_value(content));
				dialog.ShowAsync();
			}
		}
	}


	void TileCreationPage::writeToSettings(int numTiles)
	{
		m_numTilesLeft = numTiles;
		winrt::Windows::Storage::ApplicationData::Current().LocalSettings().Values().Insert(TilesSettingsKey, winrt::box_value(m_numTilesLeft));
		ProgressBar().Maximum(m_numTilesLeft);
		raisePropertyChange(L"NumTilesLeft");
		PinTilesButton().IsEnabled(true);
		m_selectedNumTiles = numTiles;
	}

	void TileCreationPage::TwoByTwo_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		writeToSettings(2 * 2);
		winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"TwoByTwo", false);
	}


	void TileCreationPage::FourByFour_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		writeToSettings(4 * 4);
		winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"FourByFour", false);
	}


	void TileCreationPage::EightByEight_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		writeToSettings(8 * 8);
		winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"EightByEight", false);
	}


	void TileCreationPage::SixBySixButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		writeToSettings(6*6);
		winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"SixBySix", false);
	}


	void TileCreationPage::ThreeByThreeButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		writeToSettings(3*3);
		winrt::Windows::UI::Xaml::VisualStateManager::GoToState(*this, L"ThreeByThree", false);
	}


}

