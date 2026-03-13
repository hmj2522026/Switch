#pragma once
#include "Transform2D.h"
#include "PhysicsBehavior.h"
#include "Tag.h"
#include "DxLib.h"
#include <array>

class BoxCollider
{
private:
	std::array <PhysicsBehavior, static_cast<int>(Tag::Length)> m_physicsBehavior;

public:
	BoxCollider(const Vector2 size, const Vector2 offset = Vector2()) :
		m_physicsBehavior{PhysicsBehavior::Collision},
		size(size),
		offset(offset)
	{ }

	Vector2 size;
	Vector2 offset;

	void SetPhysicsBehavior(Tag tag, PhysicsBehavior pb) { m_physicsBehavior[static_cast<int>(tag)] = pb; }
	void SetAllPhysicsBehavior(PhysicsBehavior pb)
	{
		for (auto& ref : m_physicsBehavior)
		{
			ref = pb;
		}
	}
	PhysicsBehavior GetPhysicsBehavior(Tag tag) { return m_physicsBehavior[static_cast<int>(tag)]; }

#ifdef _DEBUG
	void Draw(const Transform2D& t)
	{
		DrawBoxAA(
			t.position.x + offset.x * t.scale - size.x * t.scale / 2,
			t.position.y + offset.y * t.scale - size.y * t.scale / 2,
			t.position.x + offset.x * t.scale + size.x * t.scale / 2,
			t.position.y + offset.y * t.scale + size.y * t.scale / 2,
			GetColor(0, 255, 0),
			false
		);
	}
#endif // _DEBUG

};
