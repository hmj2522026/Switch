#include "Button.h"
#include "BoxCollider.h"

Button::Button(Vector2 pos) :
	Actor2D(pos,Tag::Button),
	m_isPush(false),
	m_sprite(0)
{
	m_collider = new BoxCollider(Vector2(30, 30));
}

void Button::Load()
{
	Actor2D::Load();
	m_sprite = LoadGraph("Resource/button.png");
}

void Button::Release()
{
	Actor2D::Release();
	DeleteGraph(m_sprite);
}

void Button::Draw()
{
	DrawRotaGraph(static_cast<int>(m_transform.position.x), static_cast<int>(m_transform.position.y), 1.0f, 0.0f, m_sprite, true);
}

void Button::OnCollisionEnter(const Actor2D* other)
{
	if (other->GetTag() == Tag::Punch)
	{
		m_isPush = !m_isPush;
	}
}
