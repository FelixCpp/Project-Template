import Core.System;

#include <gtest/gtest.h>

TEST(Value2, Initializes_To_Zero)
{
	constexpr Core::Int2 value;
	EXPECT_EQ(value.X, 0);
	EXPECT_EQ(value.Y, 0);
}

TEST(Value2, Initializes_To_Scalar)
{
	constexpr Core::Int2 value(42);
	EXPECT_EQ(value.X, 42);
	EXPECT_EQ(value.Y, 42);
}

TEST(Value2, Initializes_To_XY)
{
	constexpr Core::Int2 value(42, 24);
	EXPECT_EQ(value.X, 42);
	EXPECT_EQ(value.Y, 24);
}

TEST(Value2, Converts_To_Int2)
{
	constexpr Core::Float2 value(42.0f, 24.0f);
	constexpr Core::Int2 converted(value);
	EXPECT_EQ(converted.X, 42);
	EXPECT_EQ(converted.Y, 24);
}

TEST(Value2, LengthSquared)
{
	constexpr Core::Float2 value(3.0f, 4.0f);
	EXPECT_EQ(value.LengthSquared(), 25.0f);
}

TEST(Value2, Length)
{
	constexpr Core::Float2 value(3.0f, 4.0f);
	EXPECT_EQ(value.Length(), 5.0f);
}

TEST(Value2, DotProduct)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 b(5.0f, 6.0f);
	EXPECT_EQ(a.Dot(b), 39.0f);
}

TEST(Value2, CrossProduct)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 b(5.0f, 6.0f);
	EXPECT_EQ(a.Cross(b), -2.0f);
}

TEST(Value2, Perpendicular)
{
	constexpr Core::Float2 value(3.0f, 4.0f);
	constexpr Core::Float2 perpendicular = value.Perpendicular();
	EXPECT_FLOAT_EQ(perpendicular.X, 4.0f);
	EXPECT_FLOAT_EQ(perpendicular.Y, -3.0f);
}

TEST(Value2, Normalize)
{
	constexpr Core::Float2 value(3.0f, 4.0f);
	constexpr Core::Float2 normalized = value.Normalized();
	EXPECT_FLOAT_EQ(normalized.X, 0.6f);
	EXPECT_FLOAT_EQ(normalized.Y, 0.8f);
}

TEST(Value2, Add_With_Value2)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 b(5.0f, 6.0f);
	constexpr Core::Float2 result = a + b;
	EXPECT_FLOAT_EQ(result.X, 8.0f);
	EXPECT_FLOAT_EQ(result.Y, 10.0f);
}

TEST(Value2, Subtract_With_Value2)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 b(5.0f, 6.0f);
	constexpr Core::Float2 result = a - b;
	EXPECT_FLOAT_EQ(result.X, -2.0f);
	EXPECT_FLOAT_EQ(result.Y, -2.0f);
}

TEST(Value2, Multiply_With_Value2)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 b(5.0f, 6.0f);
	constexpr Core::Float2 result = a * b;
	EXPECT_FLOAT_EQ(result.X, 15.0f);
	EXPECT_FLOAT_EQ(result.Y, 24.0f);
}

TEST(Value2, Divide_With_Value2)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 b(5.0f, 6.0f);
	constexpr Core::Float2 result = a / b;
	EXPECT_FLOAT_EQ(result.X, 0.6f);
	EXPECT_FLOAT_EQ(result.Y, 0.6666666666666666f);
}

TEST(Value2, Add_With_Scalar)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 result = a + 2.0f;
	EXPECT_FLOAT_EQ(result.X, 5.0f);
	EXPECT_FLOAT_EQ(result.Y, 6.0f);
}

TEST(Value2, Subtract_With_Scalar)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 result = a - 2.0f;
	EXPECT_FLOAT_EQ(result.X, 1.0f);
	EXPECT_FLOAT_EQ(result.Y, 2.0f);
}

TEST(Value2, Multiply_With_Scalar)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 result = a * 2.0f;
	EXPECT_FLOAT_EQ(result.X, 6.0f);
	EXPECT_FLOAT_EQ(result.Y, 8.0f);
}

TEST(Value2, Divide_With_Scalar)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 result = a / 2.0f;
	EXPECT_FLOAT_EQ(result.X, 1.5f);
	EXPECT_FLOAT_EQ(result.Y, 2.0f);
}

TEST(Value2, Negate)
{
	constexpr Core::Float2 value(3.0f, 4.0f);
	constexpr Core::Float2 result = -value;
	EXPECT_FLOAT_EQ(result.X, -3.0f);
	EXPECT_FLOAT_EQ(result.Y, -4.0f);
}

TEST(Value2, AddAssign_With_Value2)
{
	Core::Float2 value(3.0f, 4.0f);
	value += Core::Float2(5.0f, 6.0f);
	EXPECT_FLOAT_EQ(value.X, 8.0f);
	EXPECT_FLOAT_EQ(value.Y, 10.0f);
}

TEST(Value2, SubtractAssign_With_Value2)
{
	Core::Float2 value(3.0f, 4.0f);
	value -= Core::Float2(5.0f, 6.0f);
	EXPECT_FLOAT_EQ(value.X, -2.0f);
	EXPECT_FLOAT_EQ(value.Y, -2.0f);
}

TEST(Value2, MultiplyAssign_With_Value2)
{
	Core::Float2 value(3.0f, 4.0f);
	value *= Core::Float2(5.0f, 6.0f);
	EXPECT_FLOAT_EQ(value.X, 15.0f);
	EXPECT_FLOAT_EQ(value.Y, 24.0f);
}

TEST(Value2, DivideAssign_With_Value2)
{
	Core::Float2 value(3.0f, 4.0f);
	value /= Core::Float2(5.0f, 6.0f);
	EXPECT_FLOAT_EQ(value.X, 0.6f);
	EXPECT_FLOAT_EQ(value.Y, 0.6666666666666666f);
}

TEST(Value2, AddAssign_With_Scalar)
{
	Core::Float2 value(3.0f, 4.0f);
	value += 2.0f;
	EXPECT_FLOAT_EQ(value.X, 5.0f);
	EXPECT_FLOAT_EQ(value.Y, 6.0f);
}

TEST(Value2, SubtractAssign_With_Scalar)
{
	Core::Float2 value(3.0f, 4.0f);
	value -= 2.0f;
	EXPECT_FLOAT_EQ(value.X, 1.0f);
	EXPECT_FLOAT_EQ(value.Y, 2.0f);
}

TEST(Value2, MultiplyAssign_With_Scalar)
{
	Core::Float2 value(3.0f, 4.0f);
	value *= 2.0f;
	EXPECT_FLOAT_EQ(value.X, 6.0f);
	EXPECT_FLOAT_EQ(value.Y, 8.0f);
}

TEST(Value2, DivideAssign_With_Scalar)
{
	Core::Float2 value(3.0f, 4.0f);
	value /= 2.0f;
	EXPECT_FLOAT_EQ(value.X, 1.5f);
	EXPECT_FLOAT_EQ(value.Y, 2.0f);
}

TEST(Value2, Equality)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 b(3.0f, 4.0f);
	EXPECT_EQ(a, b);
}

TEST(Value2, Inequality)
{
	constexpr Core::Float2 a(3.0f, 4.0f);
	constexpr Core::Float2 b(5.0f, 6.0f);
	EXPECT_NE(a, b);
}

TEST(Value2, Constants)
{
	EXPECT_EQ(Core::Float2::Zero, Core::Float2(0.0f, 0.0f));
	EXPECT_EQ(Core::Float2::One, Core::Float2(1.0f, 1.0f));
	EXPECT_EQ(Core::Float2::Left, Core::Float2(-1.0f, 0.0f));
	EXPECT_EQ(Core::Float2::Right, Core::Float2(1.0f, 0.0f));
	EXPECT_EQ(Core::Float2::Up, Core::Float2(0.0f, 1.0f));
	EXPECT_EQ(Core::Float2::Down, Core::Float2(0.0f, -1.0f));
}