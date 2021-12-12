#pragma once
#include <cnpch.h>
#include "Carbon/Events/Event.h"

namespace Carbon {

	struct WindowData
	{
		using EventFnCallback = std::function<void(Event&)>;
		
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		EventFnCallback EventCallback;

		WindowData()
			: Title("Carbon"), Width(1920), Height(1080) {}
	};

	class Window
	{
	public:
		Window(const WindowData& args)
			: m_WindowData(args) {}
		~Window() {}

		inline const WindowData& GetWindowArguments() const { return m_WindowData; }

		inline unsigned int GetWidth() const { return m_WindowData.Width; }
		inline unsigned int GetHeight() const { return m_WindowData.Height; }
		inline const std::string& GetTitle() const { return m_WindowData.Title; }

		virtual void OnUpdate() = 0;

		virtual void* GetNativeWindow() = 0;

		virtual void SetEventCallback(WindowData::EventFnCallback callback) = 0;

		static Window* Create(const WindowData& args);

	protected:
		WindowData m_WindowData;
	};

}