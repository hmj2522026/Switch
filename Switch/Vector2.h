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

	// ‰ÁZ
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

	// Œ¸Z
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

	// æZ
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

	// œZ
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

	// •‰
	constexpr Vector2 operator-() const // -Vector2
	{
		return Vector2(-x, -y);
	}

	// “™‰¿
	constexpr bool operator==(const Vector2& other) const	// Vector2 == Vector2
	{
		return Math::Equal(x, other.x) && Math::Equal(y, other.y);
	}

	// ”ñ“™‰¿
	constexpr bool operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}

	// ƒ[ƒ”»’è
	constexpr bool IsZero() const
	{
		return Math::Equal0(x) && Math::Equal0(y);
	}

	// “àÏ
	static constexpr float Dot(const Vector2& v1, const Vector2& v2)
	{
		return v1.x* v2.x + v1.y * v2.y;
	}

	// ŠOÏ
	static constexpr float Cross(const Vector2& v1, const Vector2& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}

	// ’·‚³‚Ì2æ‚ğæ“¾
	constexpr float SqrMagnitude() const
	{
		return Dot(*this, *this);
	}

	// ’·‚³‚ğæ“¾
	float Magnitude() const
	{
		return std::sqrtf(SqrMagnitude());
	}

	// ³‹K‰»
	Vector2 Normalized() const
	{
		float m = Magnitude();
		assert(!Math::Equal0(m) && "0œZ");
		return *this / m;
	}
	const Vector2& Normalize()
	{
		*this = Normalized();
		return *this;
	}
};