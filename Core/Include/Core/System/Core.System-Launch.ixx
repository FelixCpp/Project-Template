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

	Window& GetWindow();
	Sketch& GetSketch();

	int Launch(const std::function<std::unique_ptr<Sketch>()>& createSketch);
}