#include "PlayerJump.h"	
#include "Screen.h"
#include "Time.h"
#include "Keyboard.h"
#include "BoxCollider.h"

PlayerJump::PlayerJump() :
	Actor2D(StartPos, Tag::PlayerJump, Rigidbody2D::BodyType::Dynamic),
	m_sprite(0),
	m_isJump(false)
{
	m_collider = new BoxCollider(HitBoxSize);
}

void PlayerJump::Load()
{
	Actor2D::Load();
	m_sprite = LoadGraph("Resource/character_shikaku_blue.png");
}

void PlayerJump::Release()
{
	Actor2D::Release();
	DeleteGraph(m_sprite);
}

void PlayerJump::Update()
{
	Vector2 input;
	if (Keyboard::IsDown(KEY_INPUT_W) && m_isJump)
	{
		m_rigidbody2D.AddForce(JumpForce);
	}

	if (Keyboard::IsPress(KEY_INPUT_A))
	{
		input.x = -5;
	}
	if (Keyboard::IsPress(KEY_INPUT_D))
	{
		input.x = 5;
	}
	m_rigidbody2D.velocity.x = input.x;


}

void PlayerJump::Draw()
{
	DrawRotaGraph(static_cast<int>(m_transform.position.x), static_cast<int>(m_transform.position.y), 1.0f, 0.0f, m_sprite, true);
}

void PlayerJump::OnCollision(const Actor2D* other)
{
	if (other->GetTag() == Tag::Ground)
	{
		m_isJump = true;
	}
	if (other->GetTag() == Tag::Block && other->GetPosition().y - 29 > m_transform.position.y)
	{
		m_isJump = true;
	}
}
void PlayerJump::OnCollisionEnter(const Actor2D* other)
{
	//if (other->GetTag() == Tag::Ground)
	//{
	//	m_rigidbody2D.AddForce(Vector2(0, -5));
	//}
}
void PlayerJump::OnCollisionExit(const Actor2D* other)
{
	if (other->GetTag() == Tag::Ground)
	{
		m_isJump = false;
	}
	if (other->GetTag() == Tag::Block)
	{
		m_isJump = false;
	}
}
