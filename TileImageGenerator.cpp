#include "pch.h"
#include "TileImageGenerator.h"
#include <opencv2/opencv.hpp>
#include "CustomBuffer.h"
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Streams.h>
#include <filesystem>

winrt::Windows::Foundation::IAsyncAction TileImageGenerator::Generate(winrt::Windows::Graphics::Imaging::SoftwareBitmap bitmap)
{
	auto buffer = bitmap.LockBuffer(winrt::Windows::Graphics::Imaging::BitmapBufferAccessMode::Read);
	auto reference = buffer.CreateReference();
	auto ptr = reference.data();

	cv::Mat mat{ bitmap.PixelHeight(), bitmap.PixelWidth(), CV_8UC4, ptr }, resized;


	cv::resize(mat, resized, { row * tileResolution, column * tileResolution });
	static int index = 0;
	for (int rowBlock = 0; rowBlock < row; ++rowBlock)
	{
		for (int colBlock = 0; colBlock < column; ++colBlock)
		{
			auto sub = resized(cv::Rect{ colBlock * tileResolution, rowBlock * tileResolution, tileResolution, tileResolution }).clone();
			winrt::Windows::Graphics::Imaging::SoftwareBitmap seg{ bitmap.BitmapPixelFormat(), sub.cols, sub.rows, bitmap.BitmapAlphaMode() };

			//CustomBuffer buffer(mat.data, mat.total() * mat.elemSize());
			auto buffer = winrt::make<CustomBuffer>(sub.data, sub.total() * sub.elemSize());
			seg.CopyFromBuffer(buffer);
			co_await save(seg, std::format(L"{}_{}_{}.png", rowBlock, colBlock, index++).data());
		}
	}
}

void TileImageGenerator::ClearCache()
{
	try 
	{
		for (const auto& entry : std::filesystem::directory_iterator(winrt::Windows::Storage::ApplicationData::Current().LocalFolder().Path().data()))
			std::filesystem::remove_all(entry.path());
	}
	catch (...)
	{
	}
}

winrt::Windows::Foundation::IAsyncAction TileImageGenerator::save(winrt::Windows::Graphics::Imaging::SoftwareBitmap bitmap, winrt::hstring name)
{
	auto folder = winrt::Windows::Storage::ApplicationData::Current().LocalFolder();
	auto file = co_await folder.CreateFileAsync(name, winrt::Windows::Storage::CreationCollisionOption::ReplaceExisting);
	auto stream = co_await file.OpenAsync(winrt::Windows::Storage::FileAccessMode::ReadWrite);
	auto encoder = co_await winrt::Windows::Graphics::Imaging::BitmapEncoder::CreateAsync(winrt::Windows::Graphics::Imaging::BitmapEncoder::PngEncoderId(), stream);
	encoder.SetSoftwareBitmap(bitmap);
	co_await encoder.FlushAsync();
	co_await stream.FlushAsync();
	stream.Close();
}
