#pragma once
#include "Carbon/Window.h"

struct GLFWwindow;

namespace Carbon {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowData& args);
		~WindowsWindow();

		/* Returns the GLFW window in this case as a void pointer */
		void* GetNativeWindow() override;
		/* Sets the function pointer for the event callback */
		void SetEventCallback(WindowData::EventFnCallback callback) override;
		/* Runs some OpenGL specific code */
		void OnUpdate() override;

	private:
		void Shutdown();
		void Init();

	private:
		GLFWwindow* m_GLFWWindow;
	};

}

