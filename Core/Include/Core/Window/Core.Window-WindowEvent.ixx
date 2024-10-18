// Project Name : Core
// File Name    : Core.Window-WindowEvent.ixx
// Author       : Felix Busch
// Created Date : 2024/10/19

module;

#include <cstdint>

export module Core.Window:WindowEvent;

import <variant>;

export namespace Core
{
	namespace WindowEvents
	{
		struct Close {};
		struct Resize
		{
			int32_t Width;
			int32_t Height;
		};
	}

	typedef std::variant<
		WindowEvents::Close,
		WindowEvents::Resize
	> WindowEvent;
}