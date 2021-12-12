#include "cnpch.h"
#include "Application.h"

#include <glad/glad.h>

namespace Carbon {


	Application::Application()
	{
		Log::Init();
		const WindowData args;
		m_Window = std::shared_ptr<Window>(Window::Create(args));
		m_Window->SetEventCallback(BIND_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.3f, 0.5f, 0.8f, 1.0f);

			for (auto it = m_LayerStack.begin(); it != m_LayerStack.end(); ++it)
			{
				(*it)->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		e.Execute<WindowClosedEvent>(BIND_FN(Application::OnWindowCloseEvent));
		
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}
	}

	bool Application::OnWindowCloseEvent(WindowClosedEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::PushLayer(Layer* layer)
	{
		layer->OnAttach();
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		overlay->OnAttach();
		m_LayerStack.PushOverlay(overlay);
	}

}