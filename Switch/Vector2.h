#pragma once
#include <cmath>
#include <cassert>
#include "Math.h"

class Vector2
{
public:
	float x;
	float y;

	constexpr Vector2() :
		x(0),
		y(0) {}

	template<typename T1, typename T2>
	constexpr Vector2(T1 x, T2 y) :
		x(static_cast<float>(x)),
		y(static_cast<float>(y)) {}

	// â¡éZ
	constexpr Vector2 operator+(const Vector2& other) const	// Vector2 + Vector2
	{
		return Vector2(x + other.x, y + other.y);
	}
	constexpr Vector2 operator+=(const Vector2& other)	// Vector2 += Vector2
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	// å∏éZ
	constexpr Vector2 operator-(const Vector2& other) const	// Vector2 - Vector2
	{
		return Vector2(x - other.x, y - other.y);
	}
	constexpr Vector2 operator-=(const Vector2& other)	// Vector2 -= Vector2
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	// èÊéZ
	constexpr Vector2 operator*(const float& scalar) const	// Vector2 * scalar
	{
		return Vector2(x * scalar, y * scalar);
	}
	constexpr friend Vector2 operator*(const float& scalar, const Vector2& v)	// scalar * Vector2
	{
		return v * scalar;
	}
	constexpr Vector2& operator*=(const float& scalar)	// Vector2 *= scalar
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	// èúéZ
	constexpr Vector2 operator/(const float& scalar) const	// Vector2 / scalar
	{
		return Vector2(x / scalar, y / scalar);
	}
	constexpr Vector2& operator/=(const float& scalar)	// Vector2 /= scalar
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

	// ïâ
	constexpr Vector2 operator-() const // -Vector2
	{
		return Vector2(-x, -y);
	}

	// ìôâø
	constexpr bool operator==(const Vector2& other) const	// Vector2 == Vector2
	{
		return Math::Equal(x, other.x) && Math::Equal(y, other.y);
	}

	// îÒìôâø
	constexpr bool operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}

	// É[ÉçîªíË
	constexpr bool IsZero() const
	{
		return Math::Equal0(x) && Math::Equal0(y);
	}
};