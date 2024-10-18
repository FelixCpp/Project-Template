module;

#include <concepts>
#include <cstdint>

#include <gcem.hpp>

export module Core.System:Value2;

export namespace Core
{

	template <typename T>
	class Value2
	{
	public:

		constexpr Value2() : X(T{}), Y(T{}) {}
		constexpr Value2(T x, T y) : X(x), Y(y) {}
		constexpr explicit Value2(T scalar) : X(scalar), Y(scalar) {}

		template <std::convertible_to<T> Other>
		constexpr Value2(const Value2<Other>& other) : X(static_cast<T>(other.X)), Y(static_cast<T>(other.Y)) {}

		constexpr T LengthSquared() const { return X * X + Y * Y; }
		constexpr T Length() const { return gcem::sqrt(LengthSquared()); }

		constexpr T Dot(const Value2& other) const { return X * other.X + Y * other.Y; }
		constexpr T Cross(const Value2& other) const { return X * other.Y - Y * other.X; }

		constexpr Value2 Perpendicular() const { return Value2(Y, -X); }
		constexpr Value2 Normalized() const
		{
			if (const auto length = Length(); length != static_cast<T>(0))
			{
				return Value2(X / length, Y / length);
			}

			return *this;
		}

		constexpr Value2 operator+(const Value2& other) const { return Value2(X + other.X, Y + other.Y); }
		constexpr Value2 operator-(const Value2& other) const { return Value2(X - other.X, Y - other.Y); }
		constexpr Value2 operator*(const Value2& other) const { return Value2(X * other.X, Y * other.Y); }
		constexpr Value2 operator/(const Value2& other) const { return Value2(X / other.X, Y / other.Y); }
		constexpr Value2 operator+(T scalar) const { return Value2(X + scalar, Y + scalar); }
		constexpr Value2 operator-(T scalar) const { return Value2(X - scalar, Y - scalar); }
		constexpr Value2 operator*(T scalar) const { return Value2(X * scalar, Y * scalar); }
		constexpr Value2 operator/(T scalar) const { return Value2(X / scalar, Y / scalar); }

		constexpr Value2 operator-() const { return Value2(-X, -Y); }

		inline Value2& operator+=(const Value2& other) { return *this = *this + other; }
		inline Value2& operator-=(const Value2& other) { return *this = *this - other; }
		inline Value2& operator*=(const Value2& other) { return *this = *this * other; }
		inline Value2& operator/=(const Value2& other) { return *this = *this / other; }

		inline Value2& operator+=(T scalar) { return *this = *this + scalar; }
		inline Value2& operator-=(T scalar) { return *this = *this - scalar; }
		inline Value2& operator*=(T scalar) { return *this = *this * scalar; }
		inline Value2& operator/=(T scalar) { return *this = *this / scalar; }

		constexpr bool operator==(const Value2& other) const { return X == other.X && Y == other.Y; }
		constexpr bool operator!=(const Value2& other) const { return !(*this == other); }

	public:

		static const Value2 Zero;
		static const Value2 One;
		static const Value2 Left;
		static const Value2 Right;
		static const Value2 Up;
		static const Value2 Down;

	public:

		T X, Y;

	};

	template <typename T> inline const Value2<T> Value2<T>::Zero = Value2();
	template <typename T> inline const Value2<T> Value2<T>::One = Value2(static_cast<T>(1));
	template <typename T> inline const Value2<T> Value2<T>::Left = Value2(static_cast<T>(-1), static_cast<T>(0));
	template <typename T> inline const Value2<T> Value2<T>::Right = Value2(static_cast<T>(1), static_cast<T>(0));
	template <typename T> inline const Value2<T> Value2<T>::Up = Value2(static_cast<T>(0), static_cast<T>(1));
	template <typename T> inline const Value2<T> Value2<T>::Down = Value2(static_cast<T>(0), static_cast<T>(-1));

	typedef Value2<int32_t>	Int2;
	typedef Value2<uint32_t> UInt2;
	typedef Value2<float> Float2;


}