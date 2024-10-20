// Project Name : Core
// File Name    : Core.Graphics-Color.ixx
// Author       : Felix Busch
// Created Date : 2024/10/20

module;

#include <cstdint>

export module Core.Graphics:Color;

export namespace Core
{
	class Color
	{
	public:

		constexpr Color():
			R(255), G(255), B(255), A(255)
		{}

		constexpr Color(const std::uint8_t r, const std::uint8_t g, const std::uint8_t b, const std::uint8_t a = 255) :
			R(r), G(g), B(b), A(a)
		{}

		constexpr explicit Color(const std::uint32_t color) :
			R((color >> 24) & 0xFF),
			G((color >> 16) & 0xFF),
			B((color >> 8) & 0xFF),
			A(color & 0xFF)
		{}

		constexpr Color WithRed(const std::uint8_t r) const	{ return Color(r, G, B, A); }
		constexpr Color WithGreen(const std::uint8_t g) const { return Color(R, g, B, A); }
		constexpr Color WithBlue(const std::uint8_t b) const { return Color(R, G, b, A); }
		constexpr Color WithAlpha(const std::uint8_t a) const { return Color(R, G, B, a); }

		constexpr std::uint32_t AsValue() const { return (static_cast<std::uint32_t>(R) << 24) | (static_cast<std::uint32_t>(G) << 16) | (static_cast<std::uint32_t>(B) << 8) | static_cast<std::uint32_t>(A); }

		constexpr bool operator==(const Color& other) const { return AsValue() == other.AsValue(); }
		constexpr bool operator!=(const Color& other) const { return AsValue() != other.AsValue(); }

		std::uint8_t R;
		std::uint8_t G;
		std::uint8_t B;
		std::uint8_t A;

	};
}