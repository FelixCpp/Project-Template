module;

#include <GLFW/glfw3.h>
#include <Glad/glad.h>

#include <stdexcept>
#include <bit>

module Core.Graphics;

import Core.Window;

namespace Core
{

	RenderTarget::RenderTarget(const Window& window):
		m_Window(&window)
	{
		const auto windowHandle = static_cast<GLFWwindow*>(window.GetWindowHandle());

		glfwMakeContextCurrent(windowHandle);
		if (not gladLoadGLLoader(std::bit_cast<GLADloadproc>(&glfwGetProcAddress)))
		{
			throw std::runtime_error("Failed to initialize GLAD");
		}
	}

	void RenderTarget::Background(const Color& color)
	{
		glClearColor(color.R / 255.0f, color.G / 255.0f, color.B / 255.0f, color.A / 255.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void RenderTarget::Present()
	{
		const auto windowHandle = static_cast<GLFWwindow*>(m_Window->GetWindowHandle());
		glfwSwapBuffers(windowHandle);
	}


}