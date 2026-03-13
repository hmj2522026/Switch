#pragma once
#include "Vector2.h"

class Rigidbody2D
{
public:
	enum class BodyType
	{
		Dynamic,	// 動的
		Kinematic,	// 運動（重力などの影響を受けないDynamic）
		Static,		// 静的
	};
	Vector2 velocity;	// 速度
	float gravityScale;	// 重力の影響度合
	float bounciness;	// 反発係数
	float mass;			// 重さ

private:
	BodyType bodyType;

public:
	Rigidbody2D(BodyType bodytype = BodyType::Dynamic,float gravityscale = 1.0f,float bounciness = 0.4f,float mass = 1.0f) :
		bodyType(bodytype),
		gravityScale(gravityscale),
		bounciness(bounciness),
		mass(mass)
	{ }

	void AddForce(const Vector2& force) { velocity += force; }

	const BodyType GetBodyType() const { return bodyType; }
};
