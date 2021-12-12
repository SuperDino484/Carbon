#pragma once
#include "Carbon/Window.h"

class GLFWwindow;

namespace Carbon {

	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(const WindowData& args);
		~OpenGLWindow();

		void* GetNativeWindow() override;
		void SetEventCallback(WindowData::EventFnCallback callback) override;

		void OnUpdate() override;

	private:
		void Init();

	private:
		GLFWwindow* m_GLFWWindow;
	};

}

