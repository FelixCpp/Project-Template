#include <iostream>

import Core;

class MySketch final : public Core::Sketch
{
public:

	bool OnSetup() override
	{
		Core::GetWindow().SetSize(Core::Int2(900, 900));
		Core::GetWindow().SetTitle("Minecraft 2.0");

		std::cout << "Hello, World!" << std::endl;
		return true;
	}

	void OnDraw(const float deltaTime) override
	{
		std::cout << "Delta Time: " << deltaTime << std::endl;
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