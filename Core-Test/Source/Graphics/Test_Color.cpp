#include <gtest/gtest.h>

import Core.Graphics;

TEST(Color, DefaultConstructor)
{
	constexpr Core::Color color;
	EXPECT_EQ(color.R, 255);
	EXPECT_EQ(color.G, 255);
	EXPECT_EQ(color.B, 255);
	EXPECT_EQ(color.A, 255);
}

TEST(Color, Constructor)
{
	constexpr Core::Color color(0, 1, 2, 3);
	EXPECT_EQ(color.R, 0);
	EXPECT_EQ(color.G, 1);
	EXPECT_EQ(color.B, 2);
	EXPECT_EQ(color.A, 3);
}

TEST(Color, ConstructorFromValue)
{
	constexpr Core::Color color(0x12345678);
	EXPECT_EQ(color.R, 0x12);
	EXPECT_EQ(color.G, 0x34);
	EXPECT_EQ(color.B, 0x56);
	EXPECT_EQ(color.A, 0x78);
}

TEST(Color, WithRed)
{
	constexpr Core::Color color(0, 1, 2, 3);
	constexpr Core::Color newColor = color.WithRed(4);
	EXPECT_EQ(newColor.R, 4);
	EXPECT_EQ(newColor.G, 1);
	EXPECT_EQ(newColor.B, 2);
	EXPECT_EQ(newColor.A, 3);
}

TEST(Color, WithGreen)
{
	constexpr Core::Color color(0, 1, 2, 3);
	constexpr Core::Color newColor = color.WithGreen(4);
	EXPECT_EQ(newColor.R, 0);
	EXPECT_EQ(newColor.G, 4);
	EXPECT_EQ(newColor.B, 2);
	EXPECT_EQ(newColor.A, 3);
}

TEST(Color, WithBlue)
{
	constexpr Core::Color color(0, 1, 2, 3);
	constexpr Core::Color newColor = color.WithBlue(4);
	EXPECT_EQ(newColor.R, 0);
	EXPECT_EQ(newColor.G, 1);
	EXPECT_EQ(newColor.B, 4);
	EXPECT_EQ(newColor.A, 3);
}

TEST(Color, WithAlpha)
{
	constexpr Core::Color color(0, 1, 2, 3);
	constexpr Core::Color newColor = color.WithAlpha(4);
	EXPECT_EQ(newColor.R, 0);
	EXPECT_EQ(newColor.G, 1);
	EXPECT_EQ(newColor.B, 2);
	EXPECT_EQ(newColor.A, 4);
}

TEST(Color, AsValue)
{
	constexpr Core::Color color(0x12, 0x34, 0x56, 0x78);
	EXPECT_EQ(color.AsValue(), 0x12345678);
}

TEST(Color, Equality)
{
	constexpr Core::Color color1(0x12, 0x34, 0x56, 0x78);
	constexpr Core::Color color2(0x12, 0x34, 0x56, 0x78);
	constexpr Core::Color color3(0x12, 0x34, 0x56, 0x79);
	EXPECT_TRUE(color1 == color2);
	EXPECT_FALSE(color1 == color3);
}

TEST(Color, Inequality)
{
	constexpr Core::Color color1(0x12, 0x34, 0x56, 0x78);
	constexpr Core::Color color2(0x12, 0x34, 0x56, 0x78);
	constexpr Core::Color color3(0x12, 0x34, 0x56, 0x79);
	EXPECT_FALSE(color1 != color2);
	EXPECT_TRUE(color1 != color3);
}