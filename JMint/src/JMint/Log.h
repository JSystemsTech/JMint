#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace JMint {
	class JMINT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
//Core log macros
#define JM_CORE_INFO(...)     ::JMint::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JM_CORE_WARN(...)     ::JMint::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JM_CORE_TRACE(...)    ::JMint::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JM_CORE_ERROR(...)    ::JMint::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JM_CORE_FATAL(...)    ::JMint::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define JM_TRACE(...)		  ::JMint::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JM_INFO(...)		  ::JMint::Log::GetClientLogger()->info(__VA_ARGS__)
#define JM_WARN(...)		  ::JMint::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JM_ERROR(...)		  ::JMint::Log::GetClientLogger()->error(__VA_ARGS__)
#define JM_FATAL(...)		  ::JMint::Log::GetClientLogger()->fatal(__VA_ARGS__)