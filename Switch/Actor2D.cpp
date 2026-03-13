#include "Actor2D.h"
#include "Physics2D.h"
#include "Vector2.h"

Actor2D::Actor2D(
	const Vector2& position,
	const Tag& tag,
	const Rigidbody2D::BodyType bodyType
) :
	m_tag(tag),
	m_rigidbody2D(bodyType),
	m_collider(nullptr)
{
	m_transform.position = position;
}

void Actor2D::Load()
{
	if (m_collider)
	{
		Physics2D::GetInstance()->Register(this);
	}
}

void Actor2D::Release()
{
	if (m_collider)
	{
		Physics2D::GetInstance()->Remove(this);
		m_collider = nullptr;
	}
}

void Actor2D::TreeUpdate()
{
	Node::TreeUpdate();
}
