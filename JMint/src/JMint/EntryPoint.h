#pragma once

#ifdef JM_PLATFORM_WINDOWS

extern JMint::Application* JMint::CreateApplication();

int main(int argc, char** argv) 
{
	JMint::Log::Init();
	JM_CORE_WARN("Initialized Log!");
	int a = 5;
	JM_INFO("Hello! var-{0}", a);

	auto app = JMint::CreateApplication();
	app->Run();
	delete app;
}
#endif
