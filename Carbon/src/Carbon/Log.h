#pragma once


#include "cnpch.h"
#include "Carbon/Core.h"
#include "spdlog/spdlog.h"

namespace Carbon {

	class Log
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

#define CN_CORE_TRACE(...)		::Carbon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CN_CORE_INFO(...)		::Carbon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CN_CORE_WARN(...)		::Carbon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CN_CORE_ERROR(...)		::Carbon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CN_CORE_CRITICAL(...)	::Carbon::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define CN_TRACE(...)			::Carbon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CN_INFO(...)			::Carbon::Log::GetClientLogger()->info(__VA_ARGS__)
#define CN_WARN(...)			::Carbon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CN_ERROR(...)			::Carbon::Log::GetClientLogger()->error(__VA_ARGS__)
#define CN_CRITICAL(...)		::Carbon::Log::GetClientLogger()->critical(__VA_ARGS__)

