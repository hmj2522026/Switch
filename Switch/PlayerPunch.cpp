#include "PlayerPunch.h"	
#include "Screen.h"
#include "Time.h"
#include "Keyboard.h"
#include "BoxCollider.h"
#include "Punch.h"

PlayerPunch::PlayerPunch() :
	Actor2D(StartPos,Tag::PlayerPunch,Rigidbody2D::BodyType::Dynamic),
	m_sprite(0),
	m_punch(nullptr),
	m_front(true)
{
	m_collider = new BoxCollider(HitBoxSize);

	m_punch = new Punch(this);
	AddChild(m_punch);
}

void PlayerPunch::Load()
{
	Actor2D::Load();

	m_sprite = LoadGraph("Resource/character_shikaku_red.png");
}

void PlayerPunch::Release()
{
	Actor2D::Release();
	if (m_sprite)
	{
		DeleteGraph(m_sprite);
	}
}

void PlayerPunch::Update()
{
	Vector2 input;
	m_rigidbody2D.velocity.x = 0;
	if (Keyboard::IsPress(KEY_INPUT_LEFT))
	{
		input.x = -MoveSpeed;
		m_front = false;
	}
	if (Keyboard::IsPress(KEY_INPUT_RIGHT))
	{
		input.x = MoveSpeed;
		m_front = true;
	}
	m_rigidbody2D.velocity.x = input.x;

	if (Keyboard::IsDown(KEY_INPUT_UP))
	{
		m_punch->Active();
	}

}

void PlayerPunch::Draw()
{
	DrawRotaGraph(static_cast<int>(m_transform.position.x), static_cast<int>(m_transform.position.y), 1.0f, 0.0f, m_sprite, true);
}
