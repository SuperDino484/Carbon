#include <Carbon.h>

class SandboxLayer : public Carbon::Layer
{

public:
	SandboxLayer()
		: Carbon::Layer("SandboxLayer") {}

	void OnUpdate() override
	{
		
	}

	void OnEvent(Carbon::Event& e) override
	{

	}

};

class SandboxApp : public Carbon::Application
{
public:
	SandboxApp() 
	{
		PushLayer(new SandboxLayer());
	}

	~SandboxApp() 
	{
	}
};

Carbon::Application* Carbon::Application::CreateApplication()
{
	return new SandboxApp();
}