#include "Goal.h"
#include "BoxCollider.h"
#include "SceneManager.h"
#include "SceneGame.h"
#include "SceneTitle.h"
#include "Screen.h"
#include "Time.h"

Goal::Goal(Vector2 pos) :
	Actor2D(pos,Tag::Goal,Rigidbody2D::BodyType::Static),
	m_sprite(0),
	m_goalUI(0),
	m_isGoal(false),
	m_waitTransitionTime(WaitTransitionTime)
{
	m_collider = new BoxCollider(HitBoxSize);
	m_collider->SetAllPhysicsBehavior(PhysicsBehavior::Trigger);
}

void Goal::Load()
{
	Actor2D::Load();
	m_sprite = LoadGraph("Resource/goal_flag.png");
	m_goalUI = LoadGraph("Resource/goal.png");
}

void Goal::Release()
{
	Actor2D::Release();
	if (m_sprite)
	{
		DeleteGraph(m_sprite);
	}
	if (m_goalUI)
	{
		DeleteGraph(m_goalUI);
	}
}

void Goal::Update()
{
	if (m_isGoal)
	{
		m_waitTransitionTime -= Time::GetInstance()->GetDeltaTime();
		if (m_waitTransitionTime <= 0)
		{
			SceneManager::GetInstance()->LoadScene(new SceneTitle());
		}
	}
}

void Goal::Draw()
{
	DrawRotaGraph(static_cast<int>(m_transform.position.x), static_cast<int>(m_transform.position.y), 1.0f, 0.0f, m_sprite, true);

	if (m_isGoal)
	{
		DrawRotaGraph(static_cast<int>(Screen::Center.x), static_cast<int>(Screen::Center.y), 1.0f, 0.0f, m_goalUI, true);
	}
}

void Goal::OnCollisionEnter(const Actor2D* other)
{
	if (other->GetTag() == Tag::PlayerJump)
	{
		m_isGoal = true;
	}
}
