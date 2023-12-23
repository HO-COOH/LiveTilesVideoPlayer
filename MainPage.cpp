#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <winrt/Windows.Storage.Pickers.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.Media.Core.h>
#include <winrt/Windows.Media.Effects.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.Graphics.Imaging.h>
#include <winrt/Windows.Media.Editing.h>

namespace winrt::UWPTiles::implementation
{
	void MainPage::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		auto snap = UWPTiles::CapturingVideoEffect::Snap();
		if (!snap)
			return;

		if (snap.BitmapPixelFormat() != winrt::Windows::Graphics::Imaging::BitmapPixelFormat::Bgra8 || snap.BitmapAlphaMode() == winrt::Windows::Graphics::Imaging::BitmapAlphaMode::Straight)
		{
			snap = winrt::Windows::Graphics::Imaging::SoftwareBitmap::Convert(
				snap, winrt::Windows::Graphics::Imaging::BitmapPixelFormat::Bgra8,
				winrt::Windows::Graphics::Imaging::BitmapAlphaMode::Premultiplied
			);
		}
		winrt::Windows::UI::Xaml::Media::Imaging::SoftwareBitmapSource source;
		source.SetBitmapAsync(snap);
		Snapshot().Source(source);
	}

	winrt::Windows::Foundation::IAsyncAction MainPage::Button_Click_1(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::Storage::Pickers::FileOpenPicker picker;
		picker.FileTypeFilter().Append(L"*");
		auto file = co_await picker.PickSingleFileAsync();

		auto source = winrt::Windows::Media::Core::MediaSource::CreateFromStorageFile(file);
		auto clip = co_await winrt::Windows::Media::Editing::MediaClip::CreateFromFileAsync(file);
		clip.VideoEffectDefinitions().Append(winrt::Windows::Media::Effects::VideoEffectDefinition{ winrt::xaml_typename<UWPTiles::CapturingVideoEffect>().Name });

		winrt::Windows::Media::Editing::MediaComposition comp;
		comp.Clips().Append(clip);

		Player().SetMediaStreamSource(comp.GenerateMediaStreamSource());
	}


	winrt::fire_and_forget MainPage::startPlayingTiles()
	{
		while (true)
		{
			co_await winrt::resume_foreground(Dispatcher());
			if (Player().CurrentState() != winrt::Windows::UI::Xaml::Media::MediaElementState::Playing)
				break;

			co_await winrt::resume_after(std::chrono::seconds{ Config::tileUpdateIntervalSeconds });

			m_tilePlayer.Update();
		}
	}

	void MainPage::Player_CurrentStateChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		if (Player().CurrentState() == winrt::Windows::UI::Xaml::Media::MediaElementState::Playing)
		{
			startPlayingTiles();
		}
	}

	winrt::Windows::Foundation::IAsyncAction MainPage::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		co_await m_tilePlayer.MakeTile();
	}

}