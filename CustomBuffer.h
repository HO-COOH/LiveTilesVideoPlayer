#pragma once
#include <winrt/base.h>
#include <winrt/Windows.Storage.Streams.h>
struct __declspec(uuid("905a0fef-bc53-11df-8c49-001e4fc686da")) IBufferByteAccess : ::IUnknown
{
	virtual HRESULT __stdcall Buffer(void** value) = 0;
};

struct CustomBuffer : winrt::implements<CustomBuffer, winrt::Windows::Storage::Streams::IBuffer, IBufferByteAccess>
{
	void* m_address;
	uint32_t m_capacity;
	uint32_t m_length;

	CustomBuffer(void* address, uint32_t capacity) : m_address(address), m_capacity(capacity), m_length(m_capacity) { }
	uint32_t Capacity() const { return m_capacity; }
	uint32_t Length() const { return m_length; }
	void Length(uint32_t length) { m_length = length; }

	HRESULT __stdcall Buffer(void** value) override final
	{
		*value = m_address;
		return S_OK;
	}

};
