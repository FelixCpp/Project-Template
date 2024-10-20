module;

#include <GLFW/glfw3.h>
#include <stdexcept>

module Core.Window;

namespace Core
{
	class Window::Impl
	{

		inline static uint32_t s_WindowCount = 0;

	public:

		explicit Impl(WindowEventQueue& eventQueue, const Properties& properties) :
			m_EventQueue(&eventQueue),
			m_Window(nullptr)
		{
			if (s_WindowCount == 0)
			{
				glfwSetErrorCallback(&GLFWErrorCallback);

				if (not glfwInit())
				{
					throw std::runtime_error("Failed to initialize GLFW");
				}
			}

			if (GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor())
			{
				if (const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor))
				{
					glfwWindowHint(GLFW_RED_BITS, videoMode->redBits);
					glfwWindowHint(GLFW_GREEN_BITS, videoMode->greenBits);
					glfwWindowHint(GLFW_BLUE_BITS, videoMode->blueBits);
					glfwWindowHint(GLFW_REFRESH_RATE, videoMode->refreshRate);

					const int windowLeft = (videoMode->width - properties.Size.X) / 2;
					const int windowTop = (videoMode->height - properties.Size.Y) / 2;
					glfwWindowHint(GLFW_POSITION_X, windowLeft);
					glfwWindowHint(GLFW_POSITION_Y, windowTop);
				}
			}

			glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, properties.MajorVersion);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, properties.MinorVersion);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		#ifndef NDEBUG
			glfwWindowHint(GLFW_CONTEXT_DEBUG, GLFW_TRUE);
		#endif

			m_Window = glfwCreateWindow(properties.Size.X, properties.Size.Y, properties.Title.c_str(), nullptr, nullptr);
			if (m_Window == nullptr)
			{
				throw std::runtime_error("Failed to create GLFW window");
			}

			glfwSetWindowUserPointer(m_Window, m_EventQueue);

			glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				if (const auto queue = static_cast<WindowEventQueue*>(glfwGetWindowUserPointer(window)))
				{
					queue->Push(WindowEvents::Close());
				}
			});

			glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, const int width, const int height)
			{
				if (const auto queue = static_cast<WindowEventQueue*>(glfwGetWindowUserPointer(window)))
				{
					queue->Push(WindowEvents::Resize { .Width =  width, .Height = height });
				}
			});

			++s_WindowCount;
		}

		~Impl()
		{
			if (m_Window)
			{
				glfwDestroyWindow(m_Window);
				--s_WindowCount;
			}

			if (s_WindowCount == 0)
			{
				glfwTerminate();
			}
		}

		void SetPosition(const Int2& position) const
		{
			glfwSetWindowPos(m_Window, position.X, position.Y);
		}

		Int2 GetPosition() const
		{
			Int2 position;
			glfwGetWindowPos(m_Window, &position.X, &position.Y);
			return position;
		}

		void SetSize(const Int2& size) const
		{
			glfwSetWindowSize(m_Window, size.X, size.Y);
		}

		Int2 GetSize() const
		{
			Int2 size;
			glfwGetWindowSize(m_Window, &size.X, &size.Y);
			return size;
		}

		void SetTitle(const std::string& title) const
		{
			glfwSetWindowTitle(m_Window, title.c_str());
		}

		std::string GetTitle() const
		{
			const char* title = glfwGetWindowTitle(m_Window);
			return title ? title : "";
		}

		GLFWwindow* GetHandle() const
		{
			return m_Window;
		}

	private:

		static void GLFWErrorCallback(const int error, const char* description)
		{
			printf("GLFW-Error (%d): %s", error, description);
		}

	private:

		WindowEventQueue* m_EventQueue;
		GLFWwindow* m_Window;

	};

	Window::Window(const Properties& properties):
		m_Impl(std::make_unique<Impl>(m_EventQueue, properties))
	{
	}

	Window::~Window() = default;

	void Window::SetPosition(const Int2& position)
	{
		m_Impl->SetPosition(position);
	}

	Int2 Window::GetPosition() const
	{
		return m_Impl->GetPosition();
	}

	void Window::SetSize(const Int2& size)
	{
		m_Impl->SetSize(size);
	}

	Int2 Window::GetSize() const
	{
		return m_Impl->GetSize();
	}

	void Window::SetTitle(const std::string& title)
	{
		m_Impl->SetTitle(title);
	}

	std::string Window::GetTitle() const
	{
		return m_Impl->GetTitle();
	}

	void* Window::GetWindowHandle() const
	{
		return m_Impl->GetHandle();
	}

	void Window::QueueEvents()
	{
		glfwPollEvents();
	}

}