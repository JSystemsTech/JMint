#pragma once

#include "Core.h"

namespace JMint {
	class JMINT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	// DEFINED IN 
	Application* CreateApplication();
}

