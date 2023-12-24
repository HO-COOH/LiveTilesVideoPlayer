#include "pch.h"
#include "PhotoPage.h"
#if __has_include("PhotoPage.g.cpp")
#include "PhotoPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UWPTiles::implementation
{
	winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> PhotoPage::PhotosPath()
	{
		return m_photos;
	}
}
