#pragma once

#include "Carbon/Core.h"
#include "Carbon/Window.h"
#include "Carbon/Events/Event.h"
#include "Carbon/Events/ApplicationEvents.h"
#include "Carbon/ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Window; }
		inline static Application* Get() { return s_Instance; }

		static Application* CreateApplication();

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		static Application* s_Instance;

		LayerStack m_LayerStack;
	};

}

