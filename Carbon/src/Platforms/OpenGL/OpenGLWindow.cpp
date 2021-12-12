#include "cnpch.h"
#include "OpenGLWindow.h"

#include "Carbon/Events/KeyEvents.h"
#include "Carbon/Events/MouseEvents.h"
#include "Carbon/Events/ApplicationEvents.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Carbon {

	Window* Window::Create(const WindowData& args)
	{
		// TODO: Choose renderer
		return new OpenGLWindow(args);
	}

	OpenGLWindow::OpenGLWindow(const WindowData& args)
		: Window(args)
	{
		Init();
	}

	OpenGLWindow::~OpenGLWindow()
	{
		//glfwDestroyWindow(m_GLFWWindow);
	}

	void* OpenGLWindow::GetNativeWindow()
	{
		return m_GLFWWindow;
	}

	void OpenGLWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_GLFWWindow);
	}

	void OpenGLWindow::SetEventCallback(WindowData::EventFnCallback callback)
	{
		m_WindowData.EventCallback = callback;
	}

	void OpenGLWindow::Init()
	{
		int success = glfwInit();
		CN_ASSERT(success, "Could not initialize glfw");

		m_GLFWWindow = glfwCreateWindow(m_WindowData.Width, m_WindowData.Height, m_WindowData.Title.c_str(), NULL, NULL);
		if (!m_GLFWWindow)
			CN_ASSERT(0, "Could not create window");

		glfwMakeContextCurrent(m_GLFWWindow);
		glfwSetWindowUserPointer(m_GLFWWindow, &m_WindowData);
		glfwSwapInterval(1);

		glfwSetKeyCallback(m_GLFWWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
				WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));
				if (action == GLFW_PRESS)
				{
					KeyPressedEvent e(key, 0);
					data.EventCallback(e);
				}
				else if (action == GLFW_REPEAT)
				{
					KeyPressedEvent e(key, 1);
					data.EventCallback(e);
				}
				else if (action == GLFW_RELEASE)
				{
					KeyReleasedEvent e(key);
					data.EventCallback(e);
				}
			});

		glfwSetCharCallback(m_GLFWWindow, [](GLFWwindow* window, unsigned int codepoint) {
				WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));
				KeyTypedEvent e(codepoint);
				data.EventCallback(e);
			});

		glfwSetCursorPosCallback(m_GLFWWindow, [](GLFWwindow* window, double xpos, double ypos) {
				WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));
				MouseMovedEvent e((float)xpos, (float)ypos);
				data.EventCallback(e);
			});

		glfwSetMouseButtonCallback(m_GLFWWindow, [](GLFWwindow* window, int button, int action, int mods) {
				WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));
				if (action == GLFW_PRESS)
				{
					MouseButtonPressedEvent e(button);
					data.EventCallback(e);
				}
				else if (action == GLFW_RELEASE)
				{
					MouseButtonReleasedEvent e(button);
					data.EventCallback(e);
				}
			});

		glfwSetScrollCallback(m_GLFWWindow, [](GLFWwindow* window, double xoffset, double yoffset) {
				WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));
				MouseScrolledEvent e((float)xoffset, (float)yoffset);
				data.EventCallback(e);
			});

		glfwSetWindowCloseCallback(m_GLFWWindow, [](GLFWwindow* window) {
				WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));
				WindowClosedEvent e;
				data.EventCallback(e);
			});

		glfwSetWindowPosCallback(m_GLFWWindow, [](GLFWwindow* window, int xpos, int ypos) {
				WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));
				WindowMovedEvent e(xpos, ypos);
				data.EventCallback(e);
			});

		glfwSetWindowSizeCallback(m_GLFWWindow, [](GLFWwindow* window, int width, int height) {
				WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));
				WindowResizedEvent e(width, height);
				data.EventCallback(e);
			});

		success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CN_ASSERT(success, "Could not initialize glad");


	}

}