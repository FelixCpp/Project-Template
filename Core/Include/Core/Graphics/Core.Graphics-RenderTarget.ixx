// Project Name : Core
// File Name    : Core.Graphics-RenderTarget.ixx
// Author       : Felix Busch
// Created Date : 2024/10/20

export module Core.Graphics:RenderTarget;

import Core.System;

import :Color;

export namespace Core
{

	class Window;

	class RenderTarget
	{
	public:

		explicit RenderTarget(const Window& window);

		void SetViewport(const Int2& size);

		void Background(const Color& color);
		void Present();

	private:

		const Window* m_Window;

	};

}