#include "Carbon/Application.h"



#ifdef CN_PLATFORM_WINDOWS
int main()
{
	auto app = Carbon::Application::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif