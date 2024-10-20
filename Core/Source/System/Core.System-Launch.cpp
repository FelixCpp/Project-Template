module;

#include <chrono>
#include <spdlog/spdlog.h>

module Core.System;

import Core.Window;
import Core.Graphics;

import <memory>;

namespace Core
{
	namespace
	{
		std::unique_ptr<Window> s_Window;
		std::unique_ptr<Sketch> s_Sketch;
		std::unique_ptr<RenderTarget> s_RenderTarget;
	}

	Window& GetWindow()
	{
		return *s_Window;
	}

	Sketch& GetSketch()
	{
		return *s_Sketch;
	}

	RenderTarget& GetRenderTarget()
	{
		return *s_RenderTarget;
	}

	int Launch(const std::function<std::unique_ptr<Sketch>()>& createSketch)
	{
		s_Window = std::make_unique<Window>(Window::Properties {
			.Size = { 1280, 720 },
			.Title = "Core",
			.MajorVersion = 4,
			.MinorVersion = 6
		});

		s_RenderTarget = std::make_unique<RenderTarget>(*s_Window);
		s_Sketch = createSketch();

		if (not s_Sketch->OnSetup())
		{
			return -1;
		}

		bool running = true;

		auto timeStamp = std::chrono::high_resolution_clock::now();

		while (running)
		{
			const auto now = std::chrono::high_resolution_clock::now();
			const auto difference = now - timeStamp;
			timeStamp = now;

			const auto deltaTime = std::chrono::duration<float>(difference).count();

			s_Window->HandleEvents(
				[&](const WindowEvents::Close& event)
				{
					running = false;
				},
				[](const WindowEvents::Resize& event)
				{
					s_RenderTarget->SetViewport(Int2 { event.Width, event.Height });
				}
			);

			s_Sketch->OnDraw(deltaTime);
			s_RenderTarget->Present();
		}

		s_Sketch->OnDestroy();

		return 0;
	}
}
