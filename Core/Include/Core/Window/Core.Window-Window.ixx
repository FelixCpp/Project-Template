export module Core.Window:Window;

import :WindowEventQueue;

import Core.System;

import <string>;
import <memory>;
import <variant>;

export namespace Core
{

	class Window
	{

		template <typename... Handlers>
		struct Overload : Handlers...
		{
			using Handlers::operator()...;
		};

	public:

		struct Properties
		{
			Int2		Size;
			std::string Title;

			int32_t MajorVersion;
			int32_t MinorVersion;
		};

		explicit Window(const Properties& properties);
		~Window();

		void SetPosition(const Int2& position);
		Int2 GetPosition() const;

		void SetSize(const Int2& size);
		Int2 GetSize() const;

		void SetTitle(const std::string& title);
		std::string GetTitle() const;

		void* GetWindowHandle() const;

		template <typename... Handlers>
		inline void HandleEvents(Handlers&&... handlers)
		{
			QueueEvents();

			while (const auto event = m_EventQueue.Pop())
			{
				std::visit(Overload { std::forward<Handlers>(handlers)... }, *event);
			}
		}

	private:

		void QueueEvents();

	private:

		WindowEventQueue m_EventQueue;

		class Impl;
		std::unique_ptr<Impl> m_Impl;

	};

}