// Project Name : Core
// File Name    : Launch.ixx
// Author       : Felix Busch
// Created Date : 2024/10/19

export module Core.System:Launch;

import :Sketch;

import <functional>;

export namespace Core
{
	class Window;
	class RenderTarget;

	Window& GetWindow();
	Sketch& GetSketch();
	RenderTarget& GetRenderTarget();

	int Launch(const std::function<std::unique_ptr<Sketch>()>& createSketch);
}