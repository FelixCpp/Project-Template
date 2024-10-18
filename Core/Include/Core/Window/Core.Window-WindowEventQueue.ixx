export module Core.Window:WindowEventQueue;

import :WindowEvent;

import <queue>;
import <optional>;

export namespace Core
{
	class WindowEventQueue
	{
	public:

		void Push(const WindowEvent& event);
		std::optional<WindowEvent> Pop();

		bool IsEmpty() const;

	private:

		std::queue<WindowEvent> m_Events;

	};
}