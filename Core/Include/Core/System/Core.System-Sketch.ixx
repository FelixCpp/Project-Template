// Project Name : Core
// File Name    : Core.System-Sketch.ixx
// Author       : Felix Busch
// Created Date : 2024/10/19

export module Core.System:Sketch;

import <memory>;

export namespace Core
{
	class Sketch
	{
	public:

		inline Sketch() = default;
		inline virtual ~Sketch() = default;

		inline virtual bool OnSetup() { return true; }
		inline virtual void OnDraw(const float deltaTime) {}
		inline virtual void OnDestroy() {}

	};
}