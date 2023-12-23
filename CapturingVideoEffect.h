#pragma once

#include "CapturingVideoEffect.g.h"
#include <winrt/Windows.Media.MediaProperties.h>

namespace winrt::UWPTiles::implementation
{
    struct CapturingVideoEffect : CapturingVideoEffectT<CapturingVideoEffect>
    {
        CapturingVideoEffect()
        {
            //properties.Append(
            //    winrt::Windows::Media::MediaProperties::VideoEncodingProperties::CreateUncompressed(L"ARGB32", 640, 480)
            //);
        }
        
        bool IsReadOnly();
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::MediaProperties::VideoEncodingProperties> SupportedEncodingProperties();
        winrt::Windows::Media::Effects::MediaMemoryTypes SupportedMemoryTypes();
        bool TimeIndependent();

        /*Methods*/
        void DiscardQueuedFrames() {}
        void Close(winrt::Windows::Media::Effects::MediaEffectClosedReason reason);
        void ProcessFrame(winrt::Windows::Media::Effects::ProcessVideoFrameContext context);
        void SetEncodingProperties(winrt::Windows::Media::MediaProperties::VideoEncodingProperties encodingProperties, winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice device);
        void SetProperties(winrt::Windows::Foundation::Collections::IPropertySet property);

        static winrt::Windows::Graphics::Imaging::SoftwareBitmap Snap()
        {
            return s_snapshot;
        }
    private:
        winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Media::MediaProperties::VideoEncodingProperties> properties = winrt::single_threaded_vector< winrt::Windows::Media::MediaProperties::VideoEncodingProperties>();
        static inline winrt::Windows::Graphics::Imaging::SoftwareBitmap s_snapshot{ nullptr };
    };
}

namespace winrt::UWPTiles::factory_implementation
{
    struct CapturingVideoEffect : CapturingVideoEffectT<CapturingVideoEffect, implementation::CapturingVideoEffect>
    {
    };
}
