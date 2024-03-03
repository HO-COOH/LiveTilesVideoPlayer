#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"


namespace winrt::UWPTiles::implementation
{
	void MainPage::NavigationView_SelectionChanged(
		winrt::Windows::UI::Xaml::Controls::NavigationView const& sender, 
		winrt::Windows::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args)
	{
		static bool isFirst = true;
		if (isFirst)
		{
			isFirst = false;
			return;
		}
		auto tag = winrt::unbox_value<winrt::hstring>(args.SelectedItem().as<winrt::Windows::UI::Xaml::Controls::NavigationViewItem>().Tag());
		if (tag == L"TileCreationPage")
			RootFrame().Navigate(winrt::xaml_typename<UWPTiles::TileCreationPage>());
		else if (tag == L"VideoPage")
			RootFrame().Navigate(winrt::xaml_typename<UWPTiles::VideoPage>());
		else if (tag == L"PhotoPage")
			RootFrame().Navigate(winrt::xaml_typename<UWPTiles::PhotoPage>());
	}

}
