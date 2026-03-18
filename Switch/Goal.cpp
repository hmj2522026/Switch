#include "Goal.h"
#include "BoxCollider.h"
#include "SceneManager.h"
#include "SceneGame.h"

Goal::Goal(Vector2 pos) :
	Actor2D(pos,Tag::Goal,Rigidbody2D::BodyType::Static),
	m_sprite(0)
{
	m_collider = new BoxCollider(HitBoxSize);
	m_collider->SetAllPhysicsBehavior(PhysicsBehavior::Trigger);
}

void Goal::Load()
{
	Actor2D::Load();
	m_sprite = LoadGraph("Resource/goal_flag.png");
}

void Goal::Release()
{
	Actor2D::Release();
	DeleteGraph(m_sprite);
}

void Goal::Draw()
{
	DrawRotaGraph(static_cast<int>(m_transform.position.x), static_cast<int>(m_transform.position.y), 1.0f, 0.0f, m_sprite, true);
}

void Goal::OnCollisionEnter(const Actor2D* other)
{
	if (other->GetTag() == Tag::PlayerJump)
	{
		SceneManager::GetInstance()->LoadScene(new SceneGame());
	}
}
