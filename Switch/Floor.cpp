#include "Floor.h"
#include "BoxCollider.h"

Floor::Floor(Vector2 pos) :
	Actor2D(pos,Tag::Floor),
	m_sprite(0)
{
	m_collider = new BoxCollider(Vector2(90, 5),Vector2(0,-2.5));
	m_collider->SetPhysicsBehavior(Tag::PlayerJump, PhysicsBehavior::Trigger);
}

void Floor::Load()
{
	Actor2D::Load();
	m_sprite = LoadGraph("Resource/floor.png");
}

void Floor::Release()
{
	Actor2D::Release();
	DeleteGraph(m_sprite);
}

void Floor::Draw()
{
	DrawRotaGraph(static_cast<int>(m_transform.position.x), static_cast<int>(m_transform.position.y), 1.0f, 0.0f, m_sprite, true);
}

void Floor::OnCollisionEnter(const Actor2D* other)
{
	if ((other->GetTag() == Tag::PlayerJump))
	{
		if (other->GetPosition().y < m_transform.position.y)
		{
			m_collider->SetPhysicsBehavior(Tag::PlayerJump, PhysicsBehavior::Collision);
		}
	}
}

void Floor::OnCollisionExit(const Actor2D* other)
{
	if ((other->GetTag() == Tag::PlayerJump))
	{
		m_collider->SetPhysicsBehavior(Tag::PlayerJump, PhysicsBehavior::Trigger);
	}
}
