module;

#include <spdlog/sinks/stdout_color_sinks.h>

module Core.System;

namespace Core
{

	Logger::Logger()
		: m_Logger("Core")
	{
		m_Logger.sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		SetLevel(spdlog::level::trace);
		SetPattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
	}

	void Logger::SetLevel(const spdlog::level::level_enum level)
	{
		m_Logger.set_level(level);
	}

	void Logger::SetPattern(const std::string_view pattern, const spdlog::pattern_time_type type)
	{
		m_Logger.set_pattern(pattern.data(), type);
	}

	Logger& Logger::Get()
	{
		static Logger logger = [] {
			Logger result;
			result.SetLevel(spdlog::level::trace);
			result.SetPattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
			return result;
		}();

		return logger;
	}

}