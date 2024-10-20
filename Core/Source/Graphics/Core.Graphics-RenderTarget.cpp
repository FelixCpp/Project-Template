module;

#include <GLFW/glfw3.h>
#include <Glad/glad.h>

#include <stdexcept>
#include <bit>

module Core.Graphics;

import Core.Window;
import Core.System;

namespace Core
{

	RenderTarget::RenderTarget(const Window& window):
		m_Window(&window)
	{
		const auto windowHandle = static_cast<GLFWwindow*>(window.GetWindowHandle());

		glfwMakeContextCurrent(windowHandle);
		if (not gladLoadGLLoader(std::bit_cast<GLADloadproc>(&glfwGetProcAddress)))
		{
			Logger::Get().Error("Failed to initialize GLAD");
			throw std::runtime_error("Failed to initialize GLAD");
		}

		Logger::Get().Info("OpenGL Information:");
		Logger::Get().Info("\tOpenGL Version: {0}", std::bit_cast<const char*>(glGetString(GL_VERSION)));
		Logger::Get().Info("\tRenderer: {0}", std::bit_cast<const char*>(glGetString(GL_RENDERER)));
		Logger::Get().Info("\tVendor: {0}", std::bit_cast<const char*>(glGetString(GL_VENDOR)));
		Logger::Get().Info("\tGLSL Version: {0}", std::bit_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));
	}

	void RenderTarget::SetViewport(const Int2& size)
	{
		glViewport(0, 0, size.X, size.Y);
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