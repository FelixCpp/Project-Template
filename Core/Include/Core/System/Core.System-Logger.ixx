// Project Name : Core
// File Name    : Core.System-Logger.ixx
// Author       : Felix Busch
// Created Date : 2024/10/20

module;

#include <spdlog/spdlog.h>

export module Core.System:Logger;

import <string_view>;

export namespace Core
{
	class Logger
	{
	public:

		Logger();

		template <typename ... Args>
		void Trace(const spdlog::format_string_t<Args...> format, Args&& ... args)
		{
			m_Logger.trace(format, std::forward<Args>(args)...);
		}

		template <typename ... Args>
		void Debug(const spdlog::format_string_t<Args...> format, Args&& ... args)
		{
			m_Logger.debug(format, std::forward<Args>(args)...);
		}

		template <typename ... Args>
		void Info(const spdlog::format_string_t<Args...> format, Args&& ... args)
		{
			m_Logger.info(format, std::forward<Args>(args)...);
		}

		template <typename ... Args>
		void Warn(const spdlog::format_string_t<Args...> format, Args&& ... args)
		{
			m_Logger.warn(format, std::forward<Args>(args)...);
		}

		template <typename ... Args>
		void Error(const spdlog::format_string_t<Args...> format, Args&& ... args)
		{
			m_Logger.error(format, std::forward<Args>(args)...);
		}

		template <typename ... Args>
		void Critical(const spdlog::format_string_t<Args...> format, Args&& ... args)
		{
			m_Logger.critical(format, std::forward<Args>(args)...);
		}

		void SetLevel(spdlog::level::level_enum level);
		void SetPattern(const std::string_view pattern, spdlog::pattern_time_type type = spdlog::pattern_time_type::local);

		static Logger& Get();

	private:

		spdlog::logger m_Logger;

	};
}
