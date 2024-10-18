module Core.Window;

namespace Core
{

	void WindowEventQueue::Push(const WindowEvent& event)
	{
		m_Events.push(event);
	}

	std::optional<WindowEvent> WindowEventQueue::Pop()
	{
		if (IsEmpty())
		{
			return std::nullopt;
		}

		const WindowEvent event = m_Events.front();
		m_Events.pop();

		return event;
	}

	bool WindowEventQueue::IsEmpty() const
	{
		return m_Events.empty();
	}

}