module Core.System;

import Core.Window;

import <memory>;

namespace Core
{
	namespace
	{
		std::unique_ptr<Window> s_Window;
		std::unique_ptr<Sketch> s_Sketch;
	}

	Window& GetWindow()
	{
		return *s_Window;
	}

	Sketch& GetSketch()
	{
		return *s_Sketch;
	}

	int Launch(const std::function<std::unique_ptr<Sketch>()>& createSketch)
	{
		s_Window = std::make_unique<Window>(Window::Properties {
			.Size = { 1280, 720 },
			.Title = "Core"
		});

		s_Sketch = createSketch();

		while (true)
		{
			s_Window->HandleEvents(
				[](const WindowEvents::Close& event)
				{
					
				},
				[](const WindowEvents::Resize& event)
				{

				}
			);


		}

		return 0;
	}
}
