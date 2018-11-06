#pragma once

#ifdef JM_PLATFORM_WINDOWS
	#ifdef JM_BUILD_DLL
		#define JMINT_API __declspec(dllexport)
	#else
		#define JMINT_API __declspec(dllimport)
	#endif
#else
	#error JMint only supports Windows!
#endif