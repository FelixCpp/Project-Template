module Core.Window;

namespace Core
{
	class Window::Impl
	{
	public:

		explicit Impl(WindowEventQueue& eventQueue) :
			m_EventQueue(&eventQueue)
		{
		}

	private:

		WindowEventQueue* m_EventQueue;

	};

	Window::Window(const Properties& properties):
		m_Impl(std::make_unique<Impl>(m_EventQueue))
	{
	}

	Window::~Window() = default;

	void Window::SetPosition(const Int2& position)
	{
		
	}

	Int2 Window::GetPosition() const
	{
		return Int2::Zero;
	}

	void Window::SetSize(const Int2& size)
	{
		
	}

	Int2 Window::GetSize() const
	{
		return Int2::Zero;
	}

	void Window::SetTitle(const std::string& title)
	{
		
	}

	std::string Window::GetTitle() const
	{
		return {};
	}

	void Window::QueueEvents()
	{
		
	}

}