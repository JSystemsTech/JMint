#pragma once

#ifdef JM_PLATFORM_WINDOWS

extern JMint::Application* JMint::CreateApplication();

int main(int argc, char** argv) 
{
	auto app = JMint::CreateApplication();
	app->Run();
	delete app;
}
#endif
