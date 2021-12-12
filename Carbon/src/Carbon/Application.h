#pragma once

#include "Carbon/Core.h"
#include "Carbon/Window.h"
#include "Carbon/Events/Event.h"
#include "Carbon/Events/ApplicationEvents.h"

#include "Carbon/Layer.h"
#include "Carbon/LayerStack.h"

namespace Carbon {

	class Application
	{
	public:
		Application();
		~Application();

		void Run();
		void OnEvent(Event& e);
		bool OnWindowCloseEvent(WindowClosedEvent& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		static Application* CreateApplication();

	private:
		std::shared_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

}

