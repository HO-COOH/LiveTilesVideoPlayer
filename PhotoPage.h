#pragma once

#include "PhotoPage.g.h"

namespace winrt::UWPTiles::implementation
{
    struct PhotoPage : PhotoPageT<PhotoPage>
    {
        PhotoPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> PhotosPath();

        void UpdateTile();
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> m_photos = winrt::single_threaded_observable_vector<winrt::hstring>();
    };
}

namespace winrt::UWPTiles::factory_implementation
{
    struct PhotoPage : PhotoPageT<PhotoPage, implementation::PhotoPage>
    {
    };
}
