import Core.Window;

#include <gtest/gtest.h>

import <variant>;

TEST(WindowEventQueue, IsEmptyReturnsFalseAfterPush)
{
	Core::WindowEventQueue eventQueue;
	eventQueue.Push(Core::WindowEvents::Close{});
	EXPECT_FALSE(eventQueue.IsEmpty());
}

TEST(WindowEventQueue, IsEmptyReturnsTrueAfterPushAndPop)
{
	Core::WindowEventQueue eventQueue;
	eventQueue.Push(Core::WindowEvents::Close{});
	eventQueue.Pop();
	EXPECT_TRUE(eventQueue.IsEmpty());
}

TEST(WindowEventQueue, PopReturnsEvent)
{
	Core::WindowEventQueue eventQueue;
	eventQueue.Push(Core::WindowEvents::Resize{
		.Width = 1280,
		.Height = 720
	});

	const auto& [width, height] = std::get<Core::WindowEvents::Resize>(*eventQueue.Pop());
	EXPECT_EQ(width, 1280);
	EXPECT_EQ(height, 720);
}