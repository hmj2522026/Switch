#include "Punch.h"
#include "DxLib.h"
#include "BoxCollider.h"
#include "Time.h"
#include "PlayerPunch.h"

Punch::Punch(PlayerPunch* player) :
	Actor2D(player->GetPosition(),Tag::Punch,Rigidbody2D::BodyType::Kinematic),
	m_sprite(0),
	m_isActive(false),
	m_isFront(true),
	m_ActiveTime(3.0f),
	m_flipx(false),
	m_playerPunch(player)
{

}

void Punch::Load()
{
	Actor2D::Load();
	m_sprite = LoadGraph("Resource/punch.png");
}

void Punch::Release()
{
	Actor2D::Release();
	DeleteGraph(m_sprite);
}

void Punch::Update()
{


	if (!m_isActive) { return; }

	m_transform.position = m_playerPunch->GetPosition() + (m_playerPunch->GetFront() ? Offset : -Offset);

	m_flipx = !m_playerPunch->GetFront();

	m_ActiveTime -= Time::GetInstance()->GetDeltaTime();

	if (m_ActiveTime < 0)
	{
		Actor2D::Release();
		m_isActive = false;
	}
}

void Punch::Draw()
{
	if (!m_isActive) { return; }
	DrawRotaGraph(static_cast<int>(m_transform.position.x), static_cast<int>(m_transform.position.y), 1.0f, 0.0f, m_sprite, true,m_flipx);
}

void Punch::Active()
{
	m_isActive = true;
	m_ActiveTime = 1.0f;
	m_collider = new BoxCollider(HitBoxSize);
	m_collider->SetAllPhysicsBehavior(PhysicsBehavior::Ignore);
	m_collider->SetPhysicsBehavior(Tag::BlockBreakable, PhysicsBehavior::Trigger);
	Actor2D::Load();
}
