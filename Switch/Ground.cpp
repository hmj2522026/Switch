#include "Ground.h"
#include "Screen.h"
#include "BoxCollider.h"

Ground::Ground() :
	Actor2D(Vector2(Screen::Center.x, Screen::Bottom), Tag::Ground, Rigidbody2D::BodyType::Static),
	m_sprite(0)
{
	m_collider = new BoxCollider(Vector2(Screen::Width, 30));
}

void Ground::Load()
{
	Actor2D::Load();
	m_sprite = LoadGraph("Resource/ground.png");
}

void Ground::Release()
{
	Actor2D::Release();
	if (m_sprite)
	{
		DeleteGraph(m_sprite);
	}
}

void Ground::Draw()
{
	DrawRotaGraph(static_cast<int>(m_transform.position.x), static_cast<int>(m_transform.position.y), 1.0f, 0.0f, m_sprite, true);
}
