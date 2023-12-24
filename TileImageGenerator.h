#pragma once
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Graphics.Imaging.h>
class TileImageGenerator
{
public:
	int row;
	int column;
	int tileResolution = 71;

	winrt::Windows::Foundation::IAsyncAction Generate(winrt::Windows::Graphics::Imaging::SoftwareBitmap bitmap);

	void ClearCache();
private:
	winrt::Windows::Foundation::IAsyncAction save(winrt::Windows::Graphics::Imaging::SoftwareBitmap bitmap, winrt::hstring name);
};

