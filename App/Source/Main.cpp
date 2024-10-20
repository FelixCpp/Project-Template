#include <iostream>

import Core;

class MySketch final : public Core::Sketch
{
public:

	bool OnSetup() override
	{
		Core::GetWindow().SetSize(Core::Int2(900, 900));
		Core::GetWindow().SetTitle("Core Window");

		std::cout << "Hello, World!" << std::endl;
		return true;
	}

	void OnDraw(const float deltaTime) override
	{
		Core::GetRenderTarget().Background(Core::Color(255, 0, 0));
		
	}

	void OnDestroy() override
	{
		std::cout << "Goodbye, World!" << std::endl;
	}

};

int main()
{
	return Core::Launch([]
	{
		return std::make_unique<MySketch>();
	});
}