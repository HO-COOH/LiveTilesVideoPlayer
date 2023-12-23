#include "pch.h"
#include "CapturingVideoEffect.h"
#if __has_include("CapturingVideoEffect.g.cpp")
#include "CapturingVideoEffect.g.cpp"
#endif
#include <winrt/Windows.Graphics.Imaging.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>

namespace winrt::UWPTiles::implementation
{
	bool CapturingVideoEffect::IsReadOnly()
	{
		return true;
	}
	winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::MediaProperties::VideoEncodingProperties> CapturingVideoEffect::SupportedEncodingProperties()
	{
		return properties.GetView();
	}
	winrt::Windows::Media::Effects::MediaMemoryTypes CapturingVideoEffect::SupportedMemoryTypes()
	{
		return winrt::Windows::Media::Effects::MediaMemoryTypes::Cpu;
	}
	bool CapturingVideoEffect::TimeIndependent()
	{
		return true;
	}
	void CapturingVideoEffect::Close(winrt::Windows::Media::Effects::MediaEffectClosedReason reason)
	{
	}
	void CapturingVideoEffect::ProcessFrame(winrt::Windows::Media::Effects::ProcessVideoFrameContext context)
	{
		s_snapshot = context.InputFrame().SoftwareBitmap();
	}
	void CapturingVideoEffect::SetEncodingProperties(winrt::Windows::Media::MediaProperties::VideoEncodingProperties encodingProperties, winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice device)
	{
	}
	void CapturingVideoEffect::SetProperties(winrt::Windows::Foundation::Collections::IPropertySet property)
	{
	}
}
