#include "Button.h"
#include "BoxCollider.h"

Button::Button(Vector2 pos) :
	Actor2D(pos,Tag::Button),
	m_isPush(false),
	m_sprite(0),
	m_sePush(0)
{
	m_collider = new BoxCollider(HitBoxSize);
}

void Button::Load()
{
	Actor2D::Load();
	m_sprite = LoadGraph("Resource/button.png");
	m_sePush = LoadSoundMem("Resource/sound/push.wav");
	ChangeVolumeSoundMem(128, m_sePush);
}

void Button::Release()
{
	Actor2D::Release();

	if (m_sprite)
	{
		DeleteGraph(m_sprite);
	}
	if (m_sePush)
	{
		DeleteSoundMem(m_sePush);
	}
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
		PlaySoundMem(m_sePush, DX_PLAYTYPE_BACK);
	}
}
